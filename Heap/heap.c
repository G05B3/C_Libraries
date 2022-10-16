#include <stdio.h>
#include <stdlib.h>

#define swap(A, B) \
    {              \
        int t;     \
        t = A;     \
        A = B;     \
        B = t;     \
    }

void MaxHeapify(int arr[], int n, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        MaxHeapify(arr, n, largest);
    }
}

// Function to build a Max-Heap from the given array
void buildMaxHeap(int arr[], int n)
{
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--)
    {
        MaxHeapify(arr, n, i);
    }
}

void HremoveMax(int arr[], int *n)
{

    swap(arr[0], arr[*n - 1]); //swap highest priority element with lowest priority element
    (*n)--;
    MaxHeapify(arr, *n, 0);
}

void heapSort(int arr[], int n)
{
    while (n != 0)
    {
        HremoveMax(arr, &n);
    }
}

void HFixUp(int arr[], int n, int i)
{
    int parent = i / 2;
    if (i % 2 == 0)
        parent--;

    if (arr[i] > arr[parent])
    {
        swap(arr[i], arr[parent]);
    }
    else
        return;

    if (parent > 0)
        HFixUp(arr, n, parent);
}

void HChangePri(int arr[], int n, int element, int i)
{
    if (arr[element] > i)
    { //decreasing priority
        arr[element] = i;
        MaxHeapify(arr, n, element);
    }
    else if (arr[element] < i)
    { //increasing priority
        arr[element] = i;
        HFixUp(arr, n, element);
    }
}

void HInsert(int arr[], int max_size, int *n, int i)
{
    if (*n == max_size) //if Heap is full
        return;

    arr[*n] = i;
    (*n)++;

    HFixUp(arr, *n, *n - 1);
}

int HPeekMax(int arr[])
{
    return arr[0];
}

int *Heap_init(int hsize, int *n)
{
    int *Heap = (int *)calloc(hsize, sizeof(int));
    *n = 0;
    return Heap;
}

void Free_Heap(int *Heap)
{
    free(Heap);
}

void p_Heap(int arr[], int n)
{
    int i;

    printf("Heap: ");

    for (i = 0; i < n; i++)
    {
        printf("[%d] ", arr[i]);
        if (i < n - 1)
            printf("- ");
    }
    printf("\n");
}

void MinHeapify(int arr[], int n, int i)
{
    int smallest = i;   // Initialize smallest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is smaller than root
    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    // If right child is smaller than largest so far
    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    // If smallest is not root
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);

        // Recursively heapify the affected sub-tree
        MinHeapify(arr, n, smallest);
    }
}

// Function to build a Max-Heap from the given array
void buildMinHeap(int arr[], int n)
{
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--)
    {
        MinHeapify(arr, n, i);
    }
}
