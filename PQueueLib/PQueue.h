#ifndef PQUEUE_H
#define PQUEUE_H

void PQinit(unsigned Size);
void PQinsert(int I, int wt[]);
void FixUp(int Heap[], int Idx, int wt[]);
void FixDown(int Heap[], int Idx, int N, int wt[]);
int lessPri(int child1, int child2, int wt[]);
int PQempty();

int PQdelmin(int wt[]);
void PQDec(int w, int wt[]);
void PQdestroy();

void Heapsort(int Table[], int L, int R, int wt[]);

#endif