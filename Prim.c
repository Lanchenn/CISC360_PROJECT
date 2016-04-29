#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Utility.h"

/**
 * GROUP PROJECT CISC360-010
 * PART TWO: Prim algorithm structure
 *
 * Prim's algorithm is to find Minimum Spanning Tree
 * of a given connected, undirected and weighted graph.
 * The program is for adjacency matrix representation of the graph
 *
 * The orinal code is from: 
 * http ://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-mst-for-adjacency-list-representation/
 */


// C / C++ program for Prim's MST for adjacency list representation of graph
// a structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
};

// a structure to represent a connected, undirected and weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
    
    // graph is represented as an array of edges. Since the graph is
    // undirected, the edge from src to dest is also edge from dest
    // to src. Both are counted as 1 edge here.
    struct Edge* edge;
};

// A structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
};



//// A structure to represent a node in adjacency list
//struct AdjListNode
//{
//    int dest;
//    int weight;
//    struct AdjListNode* next;
//};
//
//// A structure to represent an adjacency liat
//struct AdjList
//{
//    struct AdjListNode *head;  // pointer to head node of list
//};
//
//// A structure to represent a graph. A graph is an array of adjacency lists.
//// Size of array will be V (number of vertices in graph)
//struct Graph
//{
//    int V;
//    struct AdjList* array;
//};
//






// driver program to test above function
int main()
{
    /* Let us create the following graph
     2    3
     (0)--(1)--(2)
     |   / \   |
     6| 8/   \5 |7
     | /     \ |
     (3)-------(4)
     9          */
    int graph[V][V] = {{0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };
    
    // Print the solution
    primMST(graph);
    
    return 0;
}