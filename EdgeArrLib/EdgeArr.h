#ifndef EDGEARR_H
#define EDGEARR_H

typedef struct _graph graph;

graph *Create_Graph(int V, int E, int dir); //dir = 0 not directed; dir = 1 directed;
void Destroy_Graph(graph *G);
void Add_Edge(graph *G, int u, int v, int cost);
void Pop_Edge(graph *G);
void Remove_Edge(graph *G, int pos);
void p_Graph(graph *G);
int G_Edges(graph *G);
int G_Vertices(graph *G);
void Sort_Edges(graph *G, int mode);
graph *Kruskal_MSF(graph *G);

#endif