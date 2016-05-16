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

/*
AdjList* findAdjList(Graph* graph,int src) 
{
        int i;

	Edge* edgeList = graph->edge;
	AdjList* newList = (AdjList*)malloc(sizeof(AdjList));
	newList->list[0] = src;
	int count = 1;

	for (i=0;i<graph->E;i++) {
		if (edgeList[i].src==src) {
			newList->list[count] = edgeList[i].dest;
       			count++;
		}
		else if (edgeList[i].dest==src) {
			newList->list[count] = edgeList[i].src;
			count++;
		}
	}

	newList->size = count;
	return newList;
}*/

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

/* returns the count of elements that would have been written to outList assuming outSize was large enough */
int findAdjListCount(Graph* graph, int src, int* outList, size_t outSize)
{
  Edge* edgeList = graph->edge;
  size_t k = 1;
  if (outSize > 0)
    outList[0] = src;
  for (size_t i=0; i < graph->E; i++) {
    if (edgeList[i].src==src) {
      if (k < outSize)
	outList[k] = edgeList[i].dest;
      k++;
    }
    else if (edgeList[i].dest==src) {
      if (k < outSize)
	outList[k] = edgeList[i].src;
      k++;
    }
  }
  return k;
}

// The main function that constructs Minimum Spanning Tree (MST)
// using Prim's algorithm
void PrimMST(Graph* graph)
{
    int MSTWeight = 0;
    int V = graph->V;// Get the number of vertices in graph
    int E = graph->E;// Get the number of edges in graph
    int parent[V];   // Array to store constructed MST
    int key[V];      // Key values used to pick minimum weight edge in cut
 
    // minHeap represents set E
    MinHeap* minHeap = createMinHeap(V);
 
    // Initialize min heap with all vertices. Key value of
    // all vertices (except 0th vertex) is initially infinite

    // print edges of MST
    printf("===============================================\n");
    printf("Following are the edges in the constructed MST\n");

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
        // Traverse through all adjacent vertices of u (the extracted
        // vertex) and update their key values
	int i;
	int* adjList = findAdjList(graph,u);
        int size = findAdjListCount(graph, u, NULL, 0);
	//printf("%d->%d\n",adjList[0],adjList[1]);
        //printf("%d\n",size);
	for (i=1;i<size;i++) 
        {
	    int v = adjList[i];
	    // printf("%d\n",v);   
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
	 MSTWeight += minHeapNode->key;
    }
    int n;
    for (n=1;n<V;n++) {
       printf("Edge: %d -- %d (Weight: %d)\n",parent[n],n,key[n]);
    }
    printf("Total Weight: %d\n", MSTWeight);
    printf("===============================================\n");
}

// Driver program to test above functions
int main()
{
  // Let us create the graph given in above fugure
    
    Graph* graph = (Graph*)malloc(sizeof(Graph));
//    converter("v10e22.txt", graph); //50%  
//    converter("v10e45.txt",graph); 
    converter("v40e156.txt",graph);
    PrimMST(graph);
    return 0;
}

