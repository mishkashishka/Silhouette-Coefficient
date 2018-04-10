#include "stdafx.h"
#include <iostream>
#include "readmatrix.h"
#include "distance.h"
#include <cmath>
#define ROW 100000
#define COL 1000
#define SROW 1000000

using namespace std;

double dist[ROW][COL];
double insSum[SROW];
double outDist[ROW][COL];
double outSum[SROW];

void InsCoorDist() {  //Считаем квадраты разности покоординатно для точек внутри каждого кластера
	readMatrix();
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][0] == matrix[i + 1][0]) {
					dist[i][j] = ((matrix[i][j + 1] - matrix[i + 1][j + 1]) *
						(matrix[i][j + 1] - matrix[i + 1][j + 1]));
					///cout << dist[i][j] << endl;
			}
			else {
				continue;
			}
		}
	}
}  

void InsCoorSum() { // Складываем квадраты разности и получаем внутрикластерное расстояние
	InsCoorDist();
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n; j++) {
			insSum[i] = dist[i][j] + dist[i][j + 1];
			//cout << insSum[i] << endl;
		}
	}
}

void OutCoorDist() { //Считаем квадраты разности покоординатно для точек из одного кластера до другого
	readMatrix();
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][0] != matrix[i + 1][0]) {
				outDist[i][j] = matrix[i][j + 1] + matrix[i + 1][j + 1];
				//out << outDist[i][j] << endl;
			}
			else {
				continue;
			}
		}
	}
}

void OutCoorSum() { // Получаем расстояние до объектов из другого кластера
	OutCoorDist();
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n; j++) {
			outSum[i] = outDist[i][j] + outDist[i][j + 1];
			//cout << outSum[i] << endl;
		}
	}
}

/*Нужно придумать как правильно считать квадраты разности и расстояния*/