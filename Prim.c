#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * GROUP PROJECT CISC360-010
 * PART THREE: Prim algorithm structure
 *
 * Prim's algorithm is to find Minimum Spanning Tree
 * of a given connected, undirected and weighted graph.
 * The program is for adjacency matrix representation of the graph
 *
 * The orinal code is from: 
 * http ://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-mst-
 *                                    for-adjacency-list-representation/
 */



// Structure
//__________________________________________________________________________
// a structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
};typedef struct Edge Edge;

// a structure to represent a connected, undirected and weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
    
    // graph is represented as an array of edges. Since the graph is
    // undirected, the edge from src to dest is also edge from dest
    // to src. Both are counted as 1 edge here.
    struct Edge* edge;
    
}; typedef struct Graph Graph;

// Search Function
//__________________________________________________________________________

void PrimMST(Graph *graph)
{
    int V = graph->V, E = graph->E;
    Edge *edge = graph->edge;
    int* reachset = (int *)malloc(sizeof(int) * V);
    int* unreachset = (int *)malloc(sizeof(int) * V);
    int* ST = (int *)malloc(sizeof(int) * V);
    int MSTWeight = 0;
    int i;
    
    
    
    
    // print the contents of result[] to display the built MST
    printf("===============================================\n");
    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < V; ++i) {
        printf("Edge: %d -- %d (Weight: %d)\n", edge[i].src, edge[i].dest,
               edge[i].weight);
        MSTWeight += edge[i].weight;
    }
    printf("Total Weight: %d\n", MSTWeight);
    printf("===============================================\n");
    return;
}


// Creates a graph with V vertices and E edges
Graph* createGraph(int V, int E)
{
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    
    graph->edge = (Edge*) malloc(graph->E * sizeof(Edge));
    
    return graph;
}

// Main
//__________________________________________________________________________
// Driver program to test above functions
int main()
{
    /* Let us create following weighted graph
     10
     0--------1
     |  \     |
     6|   5\   |15
     |      \ |
     2--------3
     4       */
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    Graph* graph = createGraph(V, E);
    
    
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