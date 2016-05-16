#ifndef UTILITY_H_   /* Include guard */
#define UTILITY_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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
// Read from txt file and generate a graph
void converter(const char* filename, Graph* agraph)
{
		// dealing with Vertex and Edge in Graph
		//Graph* agraph = (Graph*)malloc(sizeof(Graph));
		int i = 0;
		char cha;
		char* temp = (char*)malloc(sizeof(char) * 20);

		int numVertex;
		int numEdge;
		int iindex = 0;

	  int shiba;
	  shiba = strlen(filename);
		//printf("%d\n", shiba);
		//printf("%lu\n", sizeof(filename));
		//printf("%lu\n", (sizeof(filename) / sizeof(char)));
		//sizeof(filename) / sizeof(filename[0]))
		for(i = 0; i < shiba && iindex < 20; i++){
		
				cha = filename[i];
				if(cha == 'v'){
				
				}else if(cha == 'e'){
						numVertex = atoi(temp);
						temp[0] = 0;
						iindex = 0;
						
				}else if(cha == '.'){
						numEdge = atoi(temp);
						
				}else if(isdigit(cha)){
						temp[iindex] = cha;
						iindex++;
				}
		}
		
		
		//printf("%d  ", numVertex);
		//printf("%d\n", numEdge);
		agraph->V = numVertex;
		agraph->E = numEdge;
		agraph->edge = (Edge*)malloc(sizeof(Edge) * numEdge);
		
	  FILE *myf;
	  myf = fopen(filename,"r");
		//ifstream myf;
    //myf.open(filename);
    //printf("pass\n");

    int x;
    char* line = (char*)malloc(sizeof(char) * 10);
    int parent = -1;
    int child, wei;
    int index = 0;
    int jindex = 0;
    //while (!myf.eof()) { // change the origin file to one element each line
    int h, k;
    if(myf == NULL){
    	  printf("Cannot open the File.\n");
    }else {
    		do {
    			  x = getc (myf);
    			  
    			  
    			  if(isdigit(x)){
        				line[jindex] = x;
        				jindex++;
        				//printf("pass  %c\n", line[index]);
        		}else if(x == ':'){
        				//line[0] = '\0';   ///////for loop
        				for(h = 0; h <10; h++){
        						line[h] = '\0';
        				}
        				jindex = 0;
        				parent++;
        		}else if(x  == ']'){
        				child = atoi(line);
        				//line[0] = '\0';
        				for(h = 0; h <10; h++){
        						line[h] = '\0';
        				}
        				
        				jindex = 0;
        		}else if(x  == ')'){
        				wei = atoi(line);
								
								if(child > parent){
										//printf(":%d, %d, %d\n", parent, child, wei);  ////cun  edge
										//Edge e = (Edge)malloc(sizeof(Edge));
        						//e.src = parent;
        						//e.dest = child;
        						//e.weight = wei;
        						
        						agraph->edge[index].src = parent;
        						agraph->edge[index].dest = child;
        						agraph->edge[index].weight = wei;
        						
        						//printf(" %d:%d, %d, %d\n", index, agraph->edge[index].src, agraph->edge[index].dest, 
        										//agraph->edge[index].weight);
        						index++;
							  }
							
								
								child = 0;
								wei = 0;
        				
        				//line[0] = '\0';
        				
        				for(h = 0; h <10; h++){
        						line[h] = '\0';
        				}
        				jindex = 0;
        		}
        		
    		}while(x != EOF);
    }
    
    fclose(myf);
    
    free(temp);
    free(line);
    //return agraph;
}


#endif /* UTILITY_H_ */
