// A C Program to demonstrate adjacency list
// representation of graphs
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent an adjacency list node
typedef struct AdjListNode
{
    int dest;
    int xy;
    int cost;
    struct AdjListNode *next;
}AdjListNode;

// A structure to represent an adjacency list
typedef struct AdjList
{
    struct AdjListNode *head;
}AdjList;

// A structure to represent a graph. A graph
// is an array of adjacency lists.
// Size of array will be V (number of vertices
// in graph)
typedef struct Graph
{
    int V;
    struct AdjList *array;
} Graph;

// A utility function to create a new adjacency list node
AdjListNode *newAdjListNode(int dest, int xy, int cost)
{
    AdjListNode *newNode =
        (AdjListNode *)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->xy = xy;
    newNode->cost = cost;
    newNode->next = NULL;
    return newNode;
}

// A utility function that creates a graph of V vertices
Graph *createGraph(int V)
{
    Graph *graph =
        (Graph *)malloc(sizeof(Graph));
    if(graph==NULL) exit(0);
    graph->V = V;

    // Create an array of adjacency lists.  Size of
    // array will be V
    graph->array =
        (AdjList *)malloc(V * sizeof(AdjList));
    if(graph->array==NULL) exit(0);
    // Initialize each adjacency list as empty by
    // making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// A utility function that destroys a graph of V vertices
void destroyGraph(Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        AdjListNode *pCrawl = graph->array[v].head, *aux;
    
        while (pCrawl)
        { 
            aux = pCrawl;
            pCrawl = pCrawl->next;
            free(aux);
        }
    }
    free(graph->array);
    free(graph);
}

void add_edge(Graph *graph, int src, int dest, int xy, int cost){
    // Add an edge from src to dest.  A new node is
    // added to the adjacency list of src.  The node
    // is added at the beginning
    AdjListNode *newNode = newAdjListNode(dest, xy, cost);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Adds an edge to an undirected graph
void addEdges(Graph *graph, int src, int dest, int xy, int cost)
{
    //It needs to add two edges, one to the source one to the destiny
    add_edge(graph, src, dest, xy, cost);
    add_edge(graph, dest, src, xy, cost);
}

//Returns cost of edge [src,dest],, int **m, int max_col,int search_edge_cost(Graph *graph, int **m, int max_col, int src, int dest)
int search_edge_cost(Graph *graph, int src, int dest)
{

    AdjListNode *pCrawl = graph->array[src].head;

    if (pCrawl == NULL) //Empty List
        return -1;

    while (pCrawl->dest != dest)
    {
        if (pCrawl->next == NULL) //if there's no edge between src and dest
        {
            return INT_MAX;
        }
        pCrawl = pCrawl->next;

    }  
    
    return pCrawl->cost;
    
} 

int search_edge(Graph *graph, int src, int dest)
{
    AdjListNode *pCrawl = graph->array[src].head;

    if (pCrawl == NULL) //Empty List
        return -1;

    while (pCrawl->dest != dest)
    {
        if (pCrawl->next == NULL) //if there's no edge between src and dest
        {
            return INT_MAX;
        }
        pCrawl = pCrawl->next;

    }  
    
    return pCrawl->xy;
    
} 

int update_edge(Graph *graph, int src, int dest, int xy, int cost){

    AdjListNode *pCrawl = graph->array[src].head;

    if (pCrawl == NULL) //Empty List
        return -1;

    //Search and Change Edge(src,dest)
    while (pCrawl->dest != dest)
    {
        if (pCrawl->next == NULL) //if there's no edge between src and dest
        {
            return 0; //Unsuccessful
        }

        pCrawl = pCrawl->next;
    }

    /**Update Edge Values*/
    if (xy>= 0 && cost > 0){
        pCrawl->xy = xy;
        pCrawl->cost = cost;
    }

   return 1;
}
/**
 * Updates Values of a Specified Edge
 * Only updates if values are positive
 * Returns 1 if successfully updated, 0 if failed
*/
int UpdateEdges(Graph *graph, int src, int dest, int xy, int cost)
{

    if (cost <= 0 || xy < 0) //Nothing to update
        return 0;

     if(update_edge(graph, src, dest, xy, cost)==0) return 0;
     if(update_edge(graph, dest, src, xy, cost)==0) return 0;

    return 1;
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(Graph *graph, int max_col)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        AdjListNode *pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d (color \"%d\")\n head ", v,-3 - v);
        while (pCrawl)
        { 
            printf("-> [dest = %d|val = %d|x = %d|y = %d]", pCrawl->dest,pCrawl->cost,pCrawl->xy/max_col,pCrawl->xy%max_col);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int GraphVertex(Graph* G)
{
    return G->V;
}

AdjListNode* GraphArray(Graph *G, int i) {
    return G->array[i].head;
}

AdjListNode* NextNodeAdjList(AdjListNode* t){
    return t->next;
}

int VDest(AdjListNode* t){
    return t->dest;
}

int getWeight(AdjListNode* t){
    return t->cost;
}