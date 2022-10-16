#ifndef ADJLIST_H
#define ADJLIST_H

#include <stdio.h>

// A structure to represent an adjacency list node
typedef struct AdjListNode AdjListNode;

// A structure to represent an adjacency list
typedef struct AdjList AdjList;

typedef struct Graph Graph;

AdjListNode *newAdjListNode(int dest, int xy, int cost);
Graph *createGraph(int V);
void add_edge(Graph *graph, int src, int dest, int xy, int cost);
void addEdges(Graph *graph, int src, int dest, int xy, int cost);
void printGraph(Graph *graph, int max_col);
int search_edge_cost(Graph *graph, int src, int dest);
int search_edge(Graph *graph, int src, int dest);
int update_edge(Graph *graph, int src, int dest, int xy, int cost);
int UpdateEdges(Graph *graph, int src, int dest, int xy, int cost);
int GraphVertex(Graph* G);
AdjListNode* GraphArray(Graph* G, int i);
AdjListNode* NextNodeAdjList(AdjListNode* t);
int VDest(AdjListNode* t);
int getWeight(AdjListNode* t);
void destroyGraph(Graph* graph);

/**Gfun.c*/
Graph* Get_Edges(int**, int, int, int);
void GRAPHpfsv2(Graph *G, int src, int dest, int st[], int *wt);
void getpath(FILE*, Graph*, int, int, int);

#endif
