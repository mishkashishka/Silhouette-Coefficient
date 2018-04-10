#pragma once
#define WROW 1000000

extern double insDistSum[WROW];
extern double outDistSum[WROW];
extern double a[WROW];
extern double b[WROW];
extern double silhouette[WROW];
extern double silhouetteSum;

void InsDistSum();//������� ����� ���������� ������ ��������
void OutDistSum(); //������� ����� ��������� ����� ����������
void CountA();
void CountB();
void CountObjectSilhouette();
void SumObjectSilhouette();
double Silhouette();

//����� ������ ����, � ������� ����� ������� ���������� ��������� � ����������� ��������� � ������ �� ���