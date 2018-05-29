#include "readmatrix.h"
#include "stdafx.h"
#include "assert.h"
#include <string>
#include <fstream>
#include <iostream>
#include<omp.h>
#define ROWS 10000
#define COLS 100

using namespace std;

double matrix[ROWS][COLS];
int clusters[ROWS];
int m, n, N;

void readMatrix() {
	ifstream dataset("input.txt");
	assert(dataset.is_open());
	dataset >> m; // Кол-во точек
	dataset >> n; // Размерность пр-ва
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n + 1; j++) {
			dataset >> matrix[i][j];
		}
	}
	dataset.close();
}
void readClusters() {
	ifstream cluster("clusters.txt");
	assert(cluster.is_open());
	cluster >> N; //Кол-во кластеров
}