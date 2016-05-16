// C / C++ program for Prim's MST for adjacency list representation of graph
 
#include <limits.h>
#include "Heap.h"
#include "Utility.h"

// Creates a graph with V vertices and E edges
Graph* createGraph(int V, int E)
{
	Graph* graph = (Graph*) malloc( sizeof(Graph) );
	graph->V = V;
	graph->E = E;

	graph->edge = (Edge*) malloc( E * sizeof(Edge) );

	return graph;
}

// Find weight of an edge
int findWeight(Graph* graph,int src, int dest) 
{
	int i;
	int weight;
	Edge* edgeList = graph->edge;
	for (i=0;i<graph->E;i++) {
		if ((edgeList[i].src==src && edgeList[i].dest==dest)||(edgeList[i].src==dest && edgeList[i].dest==src)) 
{
			weight = edgeList[i].weight;	
		}
	}
	return weight;
}

// Find adjacency list of vertices
int* findAdjList(Graph* graph,int src) 
{
	int i,k=1;
	Edge* edgeList = graph->edge;
	int* adjList = (int*)malloc(sizeof(int)*(graph->E));
	adjList[0] = src;
	for (i=0;i<graph->E;i++) {
		if (edgeList[i].src==src) {
			adjList[k] = edgeList[i].dest;
			k++;
		}
		else if (edgeList[i].dest==src) {
			adjList[k] = edgeList[i].src;
			k++;
		}
	}
	return adjList;
}
  
// The main function that constructs Minimum Spanning Tree (MST)
// using Prim's algorithm
void PrimMST(Graph* graph)
{
    int V = graph->V;// Get the number of vertices in graph
    int E = graph->E;// Get the number of edges in graph
    int parent[V];   // Array to store constructed MST
    int key[V];      // Key values used to pick minimum weight edge in cut
 
    // minHeap represents set E
    MinHeap* minHeap = createMinHeap(V);
 
    // Initialize min heap with all vertices. Key value of
    // all vertices (except 0th vertex) is initially infinite
    for (int v = 1; v < V; ++v)
    {
        parent[v] = -1;
        key[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, key[v]);
        minHeap->pos[v] = v;
    }
 
    // Make key value of 0th vertex as 0 so that it
    // is extracted first
    key[0] = 0;
    minHeap->array[0] = newMinHeapNode(0, key[0]);
    minHeap->pos[0]   = 0;
 
    // Initially size of min heap is equal to V
    minHeap->size = V;
 
    // In the followin loop, min heap contains all nodes
    // not yet added to MST.
    while (!isEmpty(minHeap))
    {
        // Extract the vertex with minimum key value
        MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v; // Store the extracted vertex number
	// printf("%d\n",u);
        // Traverse through all adjacent vertices of u (the extracted
        // vertex) and update their key values
	int i;
        int* adjList = findAdjList(graph,u);
        for (i=1;i<V;i++) 
        {
	    int v = adjList[i];
	   
            // If v is not yet included in MST and weight of u-v is
            // less than key value of v, then update key value and
            // parent of v
            if (isInMinHeap(minHeap, v) && findWeight(graph,u,v) < key[v])
            {
                key[v] = findWeight(graph,u,v);
                parent[v] = u;
                decreaseKey(minHeap, v, key[v]);
            }
        }
    }
 
    // print edges of MST
    printArr(parent, V);
}

// Driver program to test above functions
int main()
{
    // Let us create the graph given in above fugure
  //  int V = 9;
  //  int E = 14;
  //  Graph* graph = createGraph(V,E);
    // add edge 0-1
    /*
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
    */
/*
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 4;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 7;
    graph->edge[1].weight = 8;

    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 8;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 7;
    graph->edge[3].weight = 11;

    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 7;

    graph->edge[5].src = 2;
    graph->edge[5].dest = 8;
    graph->edge[5].weight = 2;

    graph->edge[6].src = 2;
    graph->edge[6].dest = 5;
    graph->edge[6].weight = 4;

    graph->edge[7].src = 3;
    graph->edge[7].dest = 4;
    graph->edge[7].weight = 9;

    graph->edge[8].src = 3;
    graph->edge[8].dest = 5;
    graph->edge[8].weight = 14;

    graph->edge[9].src = 4;
    graph->edge[9].dest = 5;
    graph->edge[9].weight = 10;

    graph->edge[10].src = 5;
    graph->edge[10].dest = 6;
    graph->edge[10].weight = 2;

    graph->edge[11].src = 6;
    graph->edge[11].dest = 7;
    graph->edge[11].weight = 1;

    graph->edge[12].src = 6;
    graph->edge[12].dest = 8;
    graph->edge[12].weight = 6;

    graph->edge[13].src = 7;
    graph->edge[13].dest = 8;
    graph->edge[13].weight = 7;
*/  
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    converter("v10e22.txt", graph); //50%  
    PrimMST(graph);
    
    return 0;
}

