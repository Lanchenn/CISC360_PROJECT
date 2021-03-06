#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utility.h"

/**
 * GROUP PROJECT CISC360-010
 * Group Member: Lan Chen, Jessica Chen, Xiaomeng Chen and Zhanglong Peng
 *
 * __________________________________________________________________________
 * PART TWO: Kruskal algorithm structure
 * Kruskal's algorithm is to find Minimum Spanning Tree
 * of a given connected, undirected and weighted graph.
 *
 * The orinal code is from: 
 * http ://www.geeksforgeeks.org/greedy-
 *                      algorithms-set-2-kruskals-minimum-spanning-tree-mst/
 */


// Functions and Methond for SEARCH
//__________________________________________________________________________
// Function prototypes for union-find (These functions are defined
// after KruskalMST() method.
int find (subset subsets[], int i);
void Union(subset subsets[], int x, int y);


// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight - b1->weight;
}

// The main function to construct MST using Kruskal's algorithm
void KruskalMST(Graph* graph)
{
    int V = graph->V;
    int E = graph->E;
    //Edge result[V];	
    
    Edge* result = (Edge*)malloc(V * sizeof(Edge));
    // Tnis will store the resultant MST
    int e = 0;	// An index variable, used for result[]
    int i = 0;  // An index variable, used for sorted edges
    int MSTWeight = 0;		// the total weight of  Minimum Spanning Tree
    
    // Step 1:  Sort all the edges in non-decreasing order of their weight
    // If we are not allowed to change the given graph, we can create a copy of
    // array of edges
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
<<<<<<< Updated upstream
    
    //
    int u;
    for(u = 0; u < graph->E; u++){
    		printf("::%d\n", graph->edge[u].weight);
    }
    
=======
    //     for(i =0; i < graph->E; i++ ){
    // 		printf("%d:  src:%d  dest:%d   weight:%d\n", i, graph->edge[i].src, graph->edge[i].dest, graph->edge[i].weight);
    // }
>>>>>>> Stashed changes
    // Allocate memory for creating V ssubsets
    subset *subsets = (subset*) malloc(V * sizeof(subset));
    
    
    
    
    
    // Create V subsets with single elements
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    
    // Number of edges to be taken is equal to V-1
    while (e < V - 1)
    {
        // Step 2: Pick the smallest edge. And increment the index
        // for next iteration
        Edge next_edge = graph->edge[i++];
        
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        
        // If including this edge does't cause cycle, include it
        // in result and increment the index of result for next edge
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }
    
    // print the contents of result[] to display the built MST
    printf("===============================================\n");
    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i) {
        printf("Edge: %d -- %d (Weight: %d)\n", result[i].src, result[i].dest,
               result[i].weight);
        MSTWeight += result[i].weight;
    }
    printf("Total Weight: %d\n", MSTWeight);
    printf("===============================================\n");
    return;
}


// A utility function to find set of an element i
// (uses path compression technique)
int find(subset subsets[], int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    
    return subsets[i].parent;
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    
    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
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
    
    Graph* graph = (Graph*)malloc(sizeof(Graph));//createGraph(V, E);
    //converter("v10e9.txt", graph);  //20%
    converter("v10e45.txt", graph); //50%
    
//    int i;
//    for(i =0; i < graph->E; i++ ){
//    		printf("%d:  src:%d  dest:%d   weight:%d\n", i, graph->edge[i].src, graph->edge[i].dest, graph->edge[i].weight);
//    }
    
    //converter("v10e45.txt", graph); //100%
    //converter("v20e38.txt", graph); //20%
    //converter("v20e95.txt", graph); //50%
    //converter("v20e190.txt", graph); //100%
    //converter("v1000e499500.txt", graph); //100%
    
    KruskalMST(graph);
    
    
    
    
    
    
    
    
    /* Let us create following weighted graph
     10
     0--------1
     |  \     |
     6|   5\   |15
     |      \ |
     2--------3
     4       
    //int V = 4;  // Number of vertices in graph
    //int E = 5;  // Number of edges in graph
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
    graph->edge[4].weight = 4;*/
    
    //KruskalMST(graph);
    
    return 0;
}
