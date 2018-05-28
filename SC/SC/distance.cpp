#include "stdafx.h"
#include <iostream>
#include "readmatrix.h"
#include "distance.h"
#include <cmath>
#include <omp.h>
#define ROW 1000000
#define COL 10

using namespace std;

double insDist[ROW][COL];
double insSum[ROW][COL];
double outDist[ROW][COL];
double outSum[ROW][COL];

void CoorDist() { //Считаем квадраты разности покоординатно
	int countIns = 0;
	int countOut = 0;
	readMatrix();
#pragma omp parallel for num_threads(1)
	for (int i = 0; i < m; i++)
	{
#pragma omp parallel for num_threads(4)
		for (int j = i + 1; j < m; j++)
		{
			if (matrix[i][0] == matrix[j][0]) {
				insDist[countIns][0] = matrix[i][0];
				for (int k = 1; k <= n; k++)
				{
					insDist[countIns][k] = ((matrix[i][k] - matrix[j][k]) * (matrix[i][k] - matrix[j][k]));
				}
				countIns++;
			}
			else
			{
				outDist[countOut][0] = matrix[i][0];
				outDist[countOut][1] = matrix[j][0];
				for (int k = 1; k <= n; k++)
				{
					outDist[countOut][k + 1] = ((matrix[i][k] - matrix[j][k]) * (matrix[i][k] - matrix[j][k]));
				}
				countOut++;
			}
		}
	}
}  

void InsCoorSum() { // Складываем квадраты разности и получаем внутрикластерное расстояние
	CoorDist();
	int i = 0;
	while(insDist[i][0] != 0){
		for (int j = 1; j <= n; j++) {
			insSum[i][1] += insDist[i][j];
		}
		insSum[i][1] = sqrt(insSum[i][1]);
		insSum[i][0] = insDist[i][0];
		i++;
	}
}


void OutCoorSum() { // Складываем квадраты разности и получаем расстояние до объектов из другого кластера
	CoorDist();
	int i = 0;
	while (outDist[i][0] != 0) {
			for (int j = 2; j <= n + 1; j++) {
				outSum[i][2] += outDist[i][j];
			}
		outSum[i][2] = sqrt(outSum[i][2]);
		outSum[i][0] = outDist[i][0];
		outSum[i][1] = outDist[i][1];
		i++;
	}
}
