#pragma once
#define ROW 10000
#define COL 1000

extern double insDist[ROW][COL];
extern double insSum[ROW][COL];
extern double Outdist[ROW][COL];
extern double outSum[ROW][COL];

void CoorDist();
void InsCoorSum();
void OutCoorSum();