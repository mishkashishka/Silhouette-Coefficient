#include "stdafx.h"
#include <iostream>
#include "distance.h"
#include <cmath>
#include "silhouette.h"
#include "readmatrix.h"
#include <algorithm>
#define WROW 1000000

using namespace std;

double insDistSum[WROW];
double outDistSum[WROW];
double a[WROW];
double b[WROW];
double silhouette[WROW];
double silhouetteSum;
double S;

void InsDistSum() {
	InsCoorSum();
	for (int i = 0; i < m; i++) {
		insDistSum[i] = insSum[i] + insSum[i + 1];// !!!!!!!!!!!!!! Ï Å Ð Å È Ì Å Í Î Â À Ò Ü   Ì À Ñ Ñ È Â!!!!!!!
		//cout << insDistSum[i] << endl;
	}
}

void OutDistSum() {
	OutCoorSum();
	for (int i = 0; i < m; i++) {
		outDistSum[i] = outSum[i] + outSum[i + 1];// !!!!!!!!!!!!!! Ï Å Ð Å È Ì Å Í Î Â À Ò Ü   Ì À Ñ Ñ È Â!!!!!!!
		//cout << outDistSum[i] << endl;
	}
}

void CountA() {
	InsDistSum();
	//readClusters();
	for (int i = 0; i < N; i++) {
		a[i] = insSum[i] / (clusters[i] - 1);
		//cout << a[i] << endl;
	}
}
void CountB() {
	OutDistSum();
	//readClusters();
	for (int i = 0; i < N; i++) {
		b[i] = outDistSum[i] / clusters[i];
		//cout << b[i] << endl;
	}

}
void CountObjectSilhouette() {
	readClusters();
	CountA();
	CountB();
	for (int i = 0; i < num; i++) {
		silhouette[i] = (b[i] - a[i]) / max(a[i], b[i]);
	}
}
void SumObjectSilhouette() {
	CountObjectSilhouette();
	for (int i = 0; i < num; i++) {
		silhouetteSum = silhouette[i] + silhouette[i + 1];
	}
}
double Silhouette() {
	SumObjectSilhouette();
	readClusters();
	S = silhouetteSum / N;
	return S;
}