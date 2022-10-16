#ifndef HEAP_H
#define HEAP_H

void buildMaxHeap(int arr[], int n);
void HremoveMax(int arr[], int *n);
void heapSort(int arr[], int n);
void HChangePri(int arr[], int n, int element, int i);
void HInsert(int arr[], int max_size, int *n, int i);
int HPeekMax(int arr[]);
int *Heap_init(int max_size,int *cur_size);
void Free_Heap(int Heap[]);
void p_Heap(int arr[], int n);
void buildMinHeap(int arr[], int n);
#endif