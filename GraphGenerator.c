#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define MAX_VERTICES 30
#define MAX_EDGES 10
#define MAX_weight 30
 
struct vertex{
    struct vertex *next;
    int vID;
    int weight;
};

struct graph{
//    struct vertex *vertices[MAXV];
    struct vertex *vlist;
    int index;
//    int nvertices;
//    int line;
} ;

void createVertexList(struct graph *g, int numberOfVertices){
	// struct graph *g;
	g->index=numberOfVertices;
	g->vlist = (struct vertex *)malloc(sizeof(struct vertex) * numberOfVertices);
	for(int i=1; i<=numberOfVertices; i++){
		g->vlist[i].next= NULL;
		g->vlist[i].vID=i;
		g->vlist[i].weight = 0;
	}
	//return g;
}




int main(){
    struct graph *g;
    // g = malloc(sizeof(struct graph));
    int nov, noe;
    printf("type number of vertices u want: \n");
    scanf("%d", &nov);
    printf("type number of edges u want: \n");
    scanf("%d", &noe);
   
    int numberOfVertices = nov;
    int maxNumberOfEdges = noe;

    createVertexList(g, numberOfVertices);
    // g=createVertexList(numberOfVertices);

 for(int i=1; i<=g->index; i++)
 	printf("%d,\n", g->vlist[i].vID);
    srand ( time(NULL) );
   

    return 1;
}
