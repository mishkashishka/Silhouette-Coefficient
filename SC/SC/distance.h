#pragma once
#define ROW 10000
#define COL 1000
#define SROW 10000

extern double dist[ROW][COL];
extern double insSum[ROW][COL];
extern double Outdist[ROW][COL];
extern double outSum[ROW][COL];

void InsCoorDist();
void InsCoorSum();
void OutCoorDist();
void OutCoorSum();