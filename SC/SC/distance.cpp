#include "stdafx.h"
#include <iostream>
#include "readmatrix.h"
#include "distance.h"
#include <cmath>
#define ROW 10000
#define COL 1000
#define SROW 10000

using namespace std;

double dist[ROW][COL];
double insSum[ROW][COL];
double outDist[ROW][COL];
double outSum[ROW][COL];

void InsCoorDist() { //—читаем квадраты разности покоординатно дл€ точек внутри каждого кластера(работает корректно)
	int countA = 0;
	int countB = 0;
	readMatrix();
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (matrix[i][0] == matrix[j][0]) {
				dist[countA][0] = matrix[i][0];
				for (int k = 1; k <= n; k++)
				{
					dist[countA][k] = ((matrix[i][k] - matrix[j][k]) * (matrix[i][k] - matrix[j][k]));
				}
				countA++;
			}
			else
			{
				outDist[countB][0] = matrix[i][0];
				outDist[countB][1] = matrix[j][0];
				for (int k = 1; k <= n; k++)
				{
					outDist[countB][k + 1] = ((matrix[i][k] - matrix[j][k]) * (matrix[i][k] - matrix[j][k]));
				}
				countB++;
			}
		}
	}
}  

void InsCoorSum() { // —кладываем квадраты разности и получаем внутрикластерное рассто€ние
	InsCoorDist();
	int i = 0;
	while(dist[i][0] != 0){
		for (int j = 1; j <= n; j++) {
			insSum[i][1] += dist[i][j];
		}
		insSum[i][1] = sqrt(insSum[i][1]);
		insSum[i][0] = dist[i][0];
		i++;
	}
	i = 0;
	while (outDist[i][0] != 0) {
		for (int j = 2; j <= n+1; j++) {
			outSum[i][2] += outDist[i][j];
		}
		outSum[i][2] = sqrt(outSum[i][2]);
		outSum[i][0] = outDist[i][0];
		outSum[i][1] = outDist[i][1];
		i++;
	}
}
/*
void OutCoorDist() { //—читаем квадраты разности покоординатно дл€ точек из одного кластера до другого
	readMatrix();
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][0] != matrix[i + 1][0]) {
				outDist[i][j] = matrix[i][j + 1] + matrix[i + 1][j + 1];
				//cout << outDist[i][j] << endl;
			}
			else {
				continue;
			}
		}
	}
}

void OutCoorSum() { // ѕолучаем рассто€ние до объектов из другого кластера
	OutCoorDist();
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n; j++) {
//			outSum[i] = outDist[i][j] + outDist[i][j + 1];
			//cout << outSum[i] << endl;
		}
	}
}
*/
/*Ќужно придумать как правильно считать квадраты разности и рассто€ни€*/