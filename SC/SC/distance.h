#pragma once
#define ROW 100000
#define COL 1000
#define SROW 1000000

extern double dist[ROW][COL];
extern double insSum[SROW];
extern double Outdist[ROW][COL];
extern double outSum[SROW];

void InsCoorDist();
void InsCoorSum();
void OutCoorDist();
void OutCoorSum();