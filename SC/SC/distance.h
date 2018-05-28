#pragma once
#define ROW 1000000
#define COL 10

extern double insDist[ROW][COL];
extern double insSum[ROW][COL];
extern double Outdist[ROW][COL];
extern double outSum[ROW][COL];

void CoorDist();
void InsCoorSum();
void OutCoorSum();