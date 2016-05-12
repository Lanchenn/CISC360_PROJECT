#ifndef UTILITY_H_   /* Include guard */
#define UTILITY_H_

#include <stdio.h>
#include <stdlib.h>
//#include <omp.h>

/**
 * GROUP PROJECT CISC360-010
 * Group Member: Lan Chen, Jessica Chen, Xiaomeng Chen and Zhanglong Peng
 *
 * __________________________________________________________________________
 * PART FIVE: Graph Structure, Helper Function and GraphGenerator Converter
 * This class has  all the utility for other algorithms,
 * Also includs the converter of Random Graph Generator.
 *
 */


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

// A structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
}; typedef struct subset subset;

struct spanningTree
{
  int V,E;
  Edge* existingedgeList;
}; typedef struct spanningTree spanningTree;

// Functions and Method For GraphGenerator Converter
//__________________________________________________________________________
/*bool isNotInEdge(int child){
		int edgeIndex = 0;
		for(edgeIndex, edgeIndex < edge; edgeIndex++){
			  if(a){
			  	
			  }
				agraph->edge[edgeIndex].src = ;
		}
}*/

// Read from txt file and generate a graph
Graph* converter(string filename)
{
		// dealing with Vertex and Edge in Graph
		Graph* agraph = (Graph*)malloc(sizeof(Graph));
		int i = 0;
		char cha;
		string temp;
		int numVertex;
		int numEdge;
		for(i; filename[i] != '\0'; i++){
				cha = filename[i];
				if(cha == 'v'){
					 
				}else if(cha == 'e'){
						numVertex = atoi(temp);
						temp = "";
				}else if(cha == '.'){
						numEdge = atoi(temp);
						temp = "";
				}else if(cha <= 57 && cha >= 48){
						temp += cha;
				}
		}
		agraph->V = numVertex;
		agraph->E = numEdge;
		agraph->edge = (Edge)malloc(sizeof(Edge) * numEdge);
		
	
		ifstream myf;
    myf.open(filename);
    
    string line;
    char x;
    string line;
    int parent = 0;
    int index = 0;
    while (!myf.eof()) { // change the origin file to one element each line
        x = myf.get();
        if(x == ':'){
        		parent ++;
        		line = "";
        }else if(x == ']'){
        		int child;
        		child = atoi(line);
        		line = "";
        }else if(x ==')'){
        		int wei; 
        		wei = atoi(line);
        		line = "";
        		
        		// create new Edge
        		if(parent < child){
        				Edge e = (Edge)malloc(sizeof(Edge));
        				e->src = parent;
        				e->dest = child;
        				e->weight = wei;
        		
        				agraph->edge[index] = e;
        		}
        		
        }else if(x <= 57 && x >= 48){
        		line += x;
        }
    }
}





// Main
//__________________________________________________________________________
// Driver program to test above functions
//int main()
//{
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
    
//    return 0;
//}



///Do NOT edit this part
// Structure
//__________________________________________________________________________
// a structure to represent a weighted edge in graph
/*
struct Edge
{
    int src, dest, weight;
}; typedef struct Edge Edge;

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

// A structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
}; typedef struct subset subset;
*/







#endif /* UTILITY_H_ */
