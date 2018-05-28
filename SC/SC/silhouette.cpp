#include "stdafx.h"
#include <iostream>
#include "distance.h"
#include <cmath>
#include "silhouette.h"
#include "readmatrix.h"
#include <algorithm>
#include <omp.h>
#define WROW 1000000

using namespace std;

double a[WROW];
double b[WROW];
double silhouette[WROW];
double silhouetteSum;
double S;

void CountA() {
	InsCoorSum();
	double tempSum = 0;
	int tempCount = 0;
	int clusterNow = insSum[0][0];
	int i = 0;
	int countA = 0;
	while (insSum[i][0] != 0)
	{
			if (insSum[i][0] == clusterNow)
			{
				tempSum += insSum[i][1];
				tempCount++;
			}
			else
			{
				a[countA] = tempSum / tempCount;
				countA++;
				tempSum = insSum[i][1];
				tempCount = 1;
				clusterNow = insSum[i][0];
			}
			i++;
	}
	a[countA] = tempSum / tempCount;
}
void CountB() {
	OutCoorSum();
	int input = outSum[0][0];
	int output = outSum[0][1];
	double myArray[1000][10][2];
#pragma omp parallel for schedule(static)
		for (int i = 0; i < 1000; i++)
#pragma omp parallel for schedule(static)
			for (int j = 0; j < 10; j++)
#pragma omp parallel for schedule(static)
				for (int k = 0; k < 2; k++)
					myArray[i][j][k] = 0;
	int i = 0;
	while (outSum[i][0] != 0)
	{
		myArray[(int)outSum[i][0] - 1][(int)outSum[i][1] - 1][0] += outSum[i][2];
		myArray[(int)outSum[i][0] - 1][(int)outSum[i][1] - 1][1]++;
		myArray[(int)outSum[i][1] - 1][(int)outSum[i][0] - 1][0] += outSum[i][2];
		myArray[(int)outSum[i][1] - 1][(int)outSum[i][0] - 1][1]++;
		i++;
	}
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 10; j++) {
			if (j == i)
				continue;
			if (myArray[i][j][0] == 0)
				break;
			myArray[i][j][0] = myArray[i][j][0] / myArray[i][j][1];
		}
	}
#pragma omp parallel for
	for (int i = 0; i < 1000; i++)
	{
		double min = INFINITY;
		for (int j = 0; j < 10; j++) {
			if (j == i)
				continue;
			if (myArray[i][j][1] == 0)
			{
				break;
			}
			if (myArray[i][j][0] < min)
				min = myArray[i][j][0];
		}
		b[i] = min;
	}
}
void CountObjectSilhouette() {
	readClusters();
	CountA();
	CountB();
#pragma omp parallel for num_threads(2)
	for (int i = 0; i < N; i++) {
		silhouette[i] = (b[i] - a[i]) / max(a[i], b[i]);
	}
}
void SumObjectSilhouette() {
	CountObjectSilhouette();
	silhouetteSum = 0;
#pragma omp parallel for reduction(+:silhouetteSum)
	for (int i = 0; i < N; i++) {
		silhouetteSum += silhouette[i];
	}
}
double Silhouette() {
	SumObjectSilhouette();
		S = silhouetteSum / N;
	return S;
}