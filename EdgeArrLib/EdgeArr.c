#include <stdio.h>
#include <stdlib.h>

//Edge(u,v) with cost "cost"
typedef struct _edge
{
    int u;
    int v;
    int cost;
} edge;

//The graph is an array of edges
typedef struct _graph
{
    int V;
    int E;
    edge *arr;

    int cur_pos;
    int dir;
} graph;

/*
 * Function: Create_Graph
 * Description: Creates and initializes graph
 */
graph *Create_Graph(int V, int E, int dir)
{
    graph *G;
    G = (graph *)malloc(sizeof(graph));
    if (G == NULL)
    {
        return NULL;
    }

    G->V = V;
    G->cur_pos = 0;
    G->dir = dir;
    G->arr = NULL;
    if (dir == 1)
    { //if it's directed only allocated number of edges
        G->E = E;
        G->arr = (edge *)calloc(E, sizeof(edge));
    }
    else if (dir == 0)
    { //if its not directed allocate space for double the amount of edges ( (u,v) & (v,u) )
        G->E = 2 * E;
        G->arr = (edge *)calloc(2 * E, sizeof(edge));
    }
    if (G->arr == NULL)
    {
        return NULL;
    }
    return G;
}

/*
 * Function: Destroy_Graph
 * Description: Frees graph 
 */
void Destroy_Graph(graph *G)
{
    free(G->arr);
    free(G);
}

/*
 * Function: Add_Edge 
 * Description: Adds an edge to the graph
 */
void Add_Edge(graph *G, int u, int v, int cost)
{
    if (G->cur_pos == G->E)
        return;

    G->arr[G->cur_pos].u = u;
    G->arr[G->cur_pos].v = v;
    G->arr[G->cur_pos].cost = cost;
    G->cur_pos++;

    if (G->dir == 0)
    {
        G->arr[G->cur_pos].u = v;
        G->arr[G->cur_pos].v = u;
        G->arr[G->cur_pos].cost = cost;
        G->cur_pos++;
    }
}

/*
 * Function: Pop_Edge 
 * Description: Removes last added edge
 */
void Pop_Edge(graph *G)
{
    if (G->cur_pos == 0)
        return;

    G->arr[G->cur_pos].u = 0;
    G->arr[G->cur_pos].v = 0;
    G->arr[G->cur_pos].cost = 0;
    G->cur_pos--;
}

/*
 * Function: Remove_Edge 
 * Description: Removes target edge
 */
void Remove_Edge(graph *G, int pos)
{
    if (pos == 0 || pos == G->E)
        return;

    G->arr[pos] = G->arr[G->cur_pos];
    Pop_Edge(G);
}

void Sort_Edges(graph *G, int mode) //0 = cost, 1 = 1st edge, 2 = 2nd edge
{
    //Apply Selection Sort
    int i, j = 0, min, comp, idx;
    edge A, B;

    for (j = 0; j < G->cur_pos; j++)
    {
        A = G->arr[j];
        if (mode == 0)
            min = A.cost;
        else if (mode == 1)
            min = A.u;
        else
            min = A.v;

        idx = j;
        for (i = G->cur_pos - 1; i >= j; i--)
        {
            B = G->arr[i];
            if (mode == 0)
                comp = B.cost;
            else if (mode == 1)
                comp = B.u;
            else
                comp = B.v;

            if (comp < min)
            {
                min = comp;
                idx = i;
            }
        }
        B = G->arr[j];
        G->arr[j] = G->arr[idx];
        G->arr[idx] = B;
    }
}

/*
 * Function: p_Graph 
 * Description: prints graph, through edge enumeration
 */
void p_Graph(graph *G)
{
    int i;

    printf("\nGraph's Edges: \n");

    for (i = 0; i < G->cur_pos; i++)
    {
        printf("Edge(%d,%d) with cost %d\n", G->arr[i].u, G->arr[i].v, G->arr[i].cost);
    }
}

//Returns Graph's Number of Edges
int G_Edges(graph *G)
{
    return G->E;
}

//Returns Graph's Number of Vertices
int G_Vertices(graph *G)
{
    return G->V;
}

//Links two Vertices together and adds corresponding edge to the graph (Based off of the WQU Algorithm)
void Link(graph *G, int *id, int *sz, int u, int v, int cost)
{
    int i, j;

    for (i = u; i != id[i]; i = id[i])
        ;
    for (j = v; j != id[j]; j = id[j])
        ;

    if (i == j)
    {
        return;
    }

    if (sz[i] < sz[j])
    {
        id[i] = j;
        sz[j] += sz[i];
    }
    else
    {
        id[j] = i;
        sz[i] = j;
    }
    Add_Edge(G, u, v, cost);
}

//Implements Kruskals Algorithm for determining a graph's Minimum Spanning Tree(s)
graph *Kruskal_MSF(graph *G)
{
    graph *MSF = Create_Graph(G->V, G->E, G->dir);
    int *id = (int *)malloc(G->E * sizeof(int)), *sz = (int *)malloc(G->E * sizeof(int)), i;
    if (id == NULL)
        return NULL;

    Sort_Edges(G, 0);

    for (i = 0; i < G->E; i++)
    {
        id[i] = i;
        sz[i] = 1;
    }

    for (i = 0; i < G->E; i++)
    {
        Link(MSF, id, sz, G->arr[i].u, G->arr[i].v, G->arr[i].cost);
    }

    free(id);
    free(sz);
    return MSF;
}