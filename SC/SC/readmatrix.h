#pragma once
#define ROWS 10000
#define COLS 100


extern int m, n, N;
extern double matrix[ROWS][COLS];
extern int clusters[ROWS];
void readMatrix();
void readClusters();
