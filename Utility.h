#ifndef UTILITY_H_   /* Include guard */
#define UTILITY_H_

#include <stdio.h>
//#include <omp.h>

/**
 * GROUP PROJECT CISC360-010
 * Group Member: Lan Chen, Jessica Chen, Xiaomeng Chen and Zhanglong Peng
 *
 * __________________________________________________________________________
 * PART FIVE: 
 * This Random Graph generator should generate a complete graph
 * with given density and vertex number.
 *
 */


// Structure
//__________________________________________________________________________
// a structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
};

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
};

// A structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
};


// Functions and Method For Random Graph Generator
//__________________________________________________________________________






// Main
//__________________________________________________________________________
// Driver program to test above functions
int main()
{
//    /* Let us create following weighted graph
//     10
//     0--------1
//     |  \     |
//     6|   5\   |15
//     |      \ |
//     2--------3
//     4       */
//    int V = 4;  // Number of vertices in graph
//    int E = 5;  // Number of edges in graph
//    struct Graph* graph = createGraph(V, E);
//    
//    
//    // add edge 0-1
//    graph->edge[0].src = 0;
//    graph->edge[0].dest = 1;
//    graph->edge[0].weight = 10;
//    
//    // add edge 0-2
//    graph->edge[1].src = 0;
//    graph->edge[1].dest = 2;
//    graph->edge[1].weight = 6;
//    
//    // add edge 0-3
//    graph->edge[2].src = 0;
//    graph->edge[2].dest = 3;
//    graph->edge[2].weight = 5;
//    
//    // add edge 1-3
//    graph->edge[3].src = 1;
//    graph->edge[3].dest = 3;
//    graph->edge[3].weight = 15;
//    
//    // add edge 2-3
//    graph->edge[4].src = 2;
//    graph->edge[4].dest = 3;
//    graph->edge[4].weight = 4;
//    
//    boruvkaMST(graph);
    
    return 0;
}





#endif /* UTILITY_H_ */