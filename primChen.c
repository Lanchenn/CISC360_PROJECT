// C program for Prim's MST

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure
//__________________________________________________________________________
// a structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
}; typedef struct Edge Edge;

// a structure to represent a connected, undirected
// and weighted graph as a collection of edges.
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
    
    // graph is represented as an array of edges.
    // Since the graph is undirected, the edge
    // from src to dest is also edge from dest
    // to src. Both are counted as 1 edge here.
    Edge* edge;
}; typedef struct Graph Graph;

struct spanningTree
{
  int V,E;
  Edge* existingEdgeList;
}; typedef struct spanningTree spanningTree;

// Find duplicates
int findDuplicates(int* array,int i,int size) 
{
    array = (int*)malloc(sizeof(int)*size);
    int result = 0;
    int index;
    for (index=0;index<size;index++) {
        if (array[index]==i) {
            result = 1;
        }
    }
    return result;
}
// Get the vertex list of spanning tree
int* getVertices(spanningTree* st) 
{
    int* vertexList = (int*)malloc(sizeof(int)*st->V);
    int index;
    vertexList[0] = st->existingEdgeList[0].src;
    vertexList[1] = st->existingEdgeList[0].dest;
    
    for (index=2;index<st->V;index+=2) {
        if (!findDuplicates(vertexList,st->existingEdgeList[index/2].src,st->V)) {
            vertexList[index] = st->existingEdgeList[index/2].src;
        }
        if (!findDuplicates(vertexList,st->existingEdgeList[index/2].dest,st->V)) {
            vertexList[index+1] = st->existingEdgeList[index/2].dest;
        }
    }
    return vertexList;
}

// Get weight as given two vertices
int getWeight(int x, int y, Edge* edge,int size) 
{
    int index;
    int weight;
    for (index=0;index<size;index++) {
        if ((edge[index].src == x && edge[index].dest == y)) {
           weight = edge[index].weight; 
        }
    }
    return weight;
}

// Search for the neighbour of existing spanning tree
int findCheapestNeighbour(Graph* graph, spanningTree* st) 
{
    int index;
    int minimumWeight = INT_MAX;
    int cheapestVertex;
    for (index=0;index<graph->V-st->V;index++) {
        if (!findDuplicates(getVertices(st),graph->edge[index].dest,st->V)) {
            if (getWeight(graph->edge[index].dest,getVertices(st)[index],graph->edge,graph->V) < minimumWeight) {
                minimumWeight = getWeight(graph->edge[index].dest,getVertices(st)[index],graph->edge,graph->V);
                int cheapestVertex = graph->edge[index].src;
            }
        }
    }
    return cheapestVertex;
    
}

// Expand the spanning tree when find an unvisited vertex
void expandST(Graph* graph, spanningTree* st, int src, int dest) {
    Edge newEdge;
    newEdge.src = src;
    newEdge.dest = dest;
    Edge* newExistingEdgeList = (Edge*)malloc(sizeof(Edge)*(st->E+1));

    int index;
    if (st->V < graph->V && st->E < graph->E) {
        for (index=0;index<st->E;index++) {
            newExistingEdgeList[index] = st->existingEdgeList[index];
        }
        newExistingEdgeList[st->E] = newEdge;
        st->V++;
        st->E++;
        st->existingEdgeList = newExistingEdgeList;
    }
}

// The main function that constructs Minimum Spanning Tree (MST)
// using Prim's algorithm
void PrimMST(Graph* graph)
{
    int start = 0;
    srand(time(NULL));
    int index;
    int next;
    int src;
    int dest;
    int j;
    spanningTree* newTree = (spanningTree*)malloc(sizeof(spanningTree));
    
    for (index=0;index<graph->V;index++) {
        if (graph->edge[index].src == 0) {
            if (graph->edge[index].weight < INT_MAX) {
                dest = graph->edge[index].dest;
            }
        }
    }
    expandST(graph, newTree, start, dest);
    while (newTree->V < graph->V) {
        src = dest;
        dest = findCheapestNeighbour(graph, newTree);
        expandST(graph, newTree, src, dest);
    }
    
    for (j=0;j<newTree->E;j++) {
        printf("Edge: %d -- %d\n", newTree->existingEdgeList[j].src,newTree->existingEdgeList[j].dest);
    }
    
    
    

}

// A utility function that creates a graph of V vertices
Graph* createGraph(int V, int E)
{
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge *)malloc(sizeof(Edge) * E);
    return graph;
}

// Driver program to test above functions
int main()
{
	int V = 4;
	int E = 5;
	Graph* graph = createGraph(V,E);
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;
    
    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;
    
    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;
    
    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;
    
    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

	PrimMST(graph);

	return 0;
}

