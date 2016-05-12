// C program for Prim's MST

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Utility.h"

// Find duplicates
int findDuplicates(int* array,int i,int size) 
{
//    array = (int*)malloc(sizeof(int)*size);
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
    
    for (index=2;index<st->V;index++) {
        if 
(!findDuplicates(vertexList,st->existingEdgeList[index-1].dest,st->V)) {
            vertexList[index] = st->existingEdgeList[index-1].dest;
        }
    }
    return vertexList;
}

// Get the vertex list of spanning tree
int* getGraphVertices(Graph* graph) 
{
    int* vertexList = (int*)malloc(sizeof(int)*graph->V);
    int index;
    vertexList[0] = graph->edge[0].src;
    vertexList[1] = graph->edge[0].dest;
    
    for (index=2;index<graph->V;index++) {
        if 
(!findDuplicates(vertexList,graph->edge[index-1].dest,graph->V)) {
            vertexList[index] = graph->edge[index-1].dest;
        }
    }
    return vertexList;
}

// Get unvisited vertices
int* getUnvisitedVertices(Graph *g,spanningTree *st) 
{
    int i,j;
    int* vertexList = (int*)malloc(sizeof(int)*(g->V-st->V));
    for (i=0;i<g->V;i++) {
        if 
(!findDuplicates(getVertices(st),getGraphVertices(g)[i],st->V)) {
            vertexList[i] = getGraphVertices(g)[i];
        }
    }
    return vertexList;
}


// Get edges between two given vertices
Edge getEdge(int src,int dest,Graph *g)
{
    g = (Graph*)malloc(sizeof(Graph));
    Edge edge;
    int i;
    for (i=0;i<g->E;i++) {
        if (src == g->edge[i].src && dest == g->edge[i].dest) {
            edge = g->edge[i];
        }
    }
    return edge;
}

// Search for the neighbour of existing spanning tree
Edge findCheapestNeighbour(Graph* g, spanningTree* st) 
{
    Edge* edgeList = (Edge*)malloc(sizeof(Edge)*(g->E-st->E));
    int* vertexListST = getVertices(st);
    int* unvisitedList = getUnvisitedVertices(g,st);
    int i,j;
    int k=0;
    int minimumWeight = INT_MAX;
    int index;
    Edge edge;
    
    for (i=0;i<st->V;i++) {
        for (j=0;j<(g->V-st->V);j++) {
            edgeList[g->V/2] = 
getEdge(vertexListST[i],unvisitedList[j],g);
        }
    }

    for (index=0;index<(g->E-st->E);index++) {
        if (edgeList[index].weight<minimumWeight) {
            minimumWeight = edgeList[index].weight;
            edge = edgeList[index];
        }
    }
    return edge;
}

// Remove loop in ST
void removeLoop(spanningTree *st) 
{
    int i;
    for (i=0;i<st->E;i++) {
        if (st->existingEdgeList[i].src == st->existingEdgeList[i].dest) 
{
            st->existingEdgeList[i] = st->existingEdgeList[i+1];
        }
    }
}

// Expand the spanning tree when find an unvisited vertex
void expandST(Graph* graph, spanningTree* st, Edge edge) {
    Edge* newExistingEdgeList = (Edge*)malloc(sizeof(Edge)*(st->E+1));

    int index;
    if (st->V < graph->V) {
        for (index=0;index<st->E;index++) {
            newExistingEdgeList[index] = st->existingEdgeList[index];
        }
        newExistingEdgeList[st->E] = edge;
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
    int index;
    Edge newEdge;
    int minimumWeight = INT_MAX;
    int j;
    
    spanningTree* newTree = (spanningTree*)malloc(sizeof(spanningTree));
    
    for (index=0;index<graph->V;index++) {
        if (graph->edge[index].src == 0) {
            if (graph->edge[index].weight < minimumWeight) {
                minimumWeight = graph->edge[index].weight;
                newEdge = graph->edge[index];
            }
        }
    }
    printf("%d,%d\n",newEdge.src,newEdge.dest);
    expandST(graph, newTree, newEdge);

    while (newTree->V < graph->V) {
        newEdge = findCheapestNeighbour(graph, newTree);
            printf("%d,%d\n",newEdge.src,newEdge.dest);
        expandST(graph, newTree, newEdge);
    }
    
    removeLoop(newTree);
    for (j=0;j<newTree->E;j++) {
        printf("Edge: %d -- %d (Weight: %d)\n", 
newTree->existingEdgeList[j].src,newTree->existingEdgeList[j].dest,newTree->existingEdgeList[j].weight);
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

spanningTree* createST(int V, int E)
{
    spanningTree* st = (spanningTree*) malloc(sizeof(spanningTree));
    st->V = V;
    st->E = E;
    st->existingEdgeList = (Edge *)malloc(sizeof(Edge) * E);
    return st;
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
	
	// Test Functions
    spanningTree* newTree = createST(2,1);
    newTree->existingEdgeList[0].src = 2;
    newTree->existingEdgeList[0].dest = 3;
    newTree->existingEdgeList[0].weight = 4;
    
    // newTree->existingEdgeList[1].src = 2;
    // newTree->existingEdgeList[1].dest = 3;
    // newTree->existingEdgeList[1].weight = 4;
    
    
    // int i;
    // for (i=0;i<2;i++) {
    //     printf("%d\n",getVertices(newTree)[i]);
    // }
    // printf("%d\n",findDuplicates(getVertices(newTree),3,3));
    printf("%d,%d\n",findCheapestNeighbour(graph, 
newTree).src,findCheapestNeighbour(graph, newTree).dest);
    // printf("%d\n",getWeight(2, 3, newTree->existingEdgeList,3));
	return 0;
}


