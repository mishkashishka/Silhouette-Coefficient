#pragma once
#define WROW 1000000

extern double insDistSum[WROW];
extern double outDistSum[WROW];
extern double a[WROW];
extern double b[WROW];
extern double silhouette[WROW];
extern double silhouetteSum;

void InsDistSum();//—читает суммы рассто€ний внутри кластера
void OutDistSum(); //—читает суммы расто€ний между кластерами
void CountA();
void CountB();
void CountObjectSilhouette();
void SumObjectSilhouette();
double Silhouette();

//нужен второй файл, в котором будет указано количество кластеров и количчество элементов в каждом из них