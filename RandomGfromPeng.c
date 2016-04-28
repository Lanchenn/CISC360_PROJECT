#include<stdio.h>
#include<stdlib.h>
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
    struct vertex **vertices;
//    int nvertices;
//    int line;
};


struct graph initialize_graph(int numberOfVertices){
    
//    g->nvertices = 0;
//    g->line = 0;
    struct graph g;
    if ((g = (struct vertex ***) malloc(sizeof(struct vertex **) * numberOfVertices)) == NULL){
        printf("Could not allocate memory for graph\n");
        exit(1);
    }
    
//    g.vertices = (struct vertex *)malloc(sizeof(struct vertex) * MAXV * MAXV);
//    for (int i=0; i<MAXV;i++)
//        g->vertices[i] = NULL;
//    
    return g;
    
}



void vertexMemAllo(struct graph *g, int numberOfVertices, int maxNumberOfEdges){
    
    /*generate space for edges*/
    int vertexCounter = 0;
    /*generate space for vertices*/
    int edgeCounter = 0;
    
    for (vertexCounter = 0; vertexCounter < numberOfVertices; vertexCounter++){
        if ((g[vertexCounter] = (struct vertex **) malloc(sizeof(struct vertex *) * maxNumberOfEdges)) == NULL){
            printf("Could not allocate memory for edges\n");
            exit(1);
        }
        for (edgeCounter = 0; edgeCounter < maxNumberOfEdges; edgeCounter++){
            if ((g[vertexCounter][edgeCounter] = (struct vertex *) malloc(sizeof(struct vertex))) == NULL){
                printf("Could not allocate memory for vertex\n");
                exit(1);
            }
        }

}
}


void addToList(struct vertex *v, struct vertex *dst_v){
    while(v->next != NULL){
        v = v-> next;
    }
    v->next=dst_v;
}




void vertexGene(struct graph *g, int numberOfVertices, int maxNumberOfEdges){
    srand ( time(NULL) );
    int vertexCounter = 0, edgeCounter = 0;
    for (vertexCounter = 0; vertexCounter < numberOfVertices; vertexCounter++){
        g->vertices[vertexCounter]->vID=vertexCounter;
        g->vertices[vertexCounter]->weight=rand()%MAX_weight;
        printf("%d:\t",vertexCounter);
        printf("%d:\t",g->vertices[vertexCounter]->weight);
        for (edgeCounter=0; edgeCounter < maxNumberOfEdges; edgeCounter++){
            if (rand()%2 == 1){ /*link the vertices*/
                int linkedVertex = rand() % numberOfVertices;
                addToList(g[vertexCounter][edgeCounter], g[linkedVertex]);
                printf("%d, ", linkedVertex);
            }
//            else{ /*make the link NULL*/
//                graph[vertexCounter][edgeCounter] = NULL;
            
        }
        printf("\n");
    }
}



int main(){
    struct graph *g;
    g = malloc(sizeof(struct graph));
    int nov, noe;
    printf("type number of vertices u want: \n");
    scanf("%d", &nov);
    printf("type number of edges u want: \n");
    scanf("%d", &noe);
    /*number of nodes in a graph*/
//    srand ( time(NULL) );
    //int numberOfVertices = rand() % MAX_VERTICES;
    int numberOfVertices = nov;
 
    /*number of maximum edges a vertex can have*/
    srand ( time(NULL) );
    //int maxNumberOfEdges = rand() % MAX_EDGES;
    /*graphs is 2 dimensional array of pointers*/
    int maxNumberOfEdges = noe;

    if( numberOfVertices == 0)
        numberOfVertices++;
    printf("Total Vertices = %d, Max # of Edges = %d\n",numberOfVertices, maxNumberOfEdges);
 
    /*generate a dynamic array of random size*/
    
    g=initialize_graph(nov);
    vertexMemAllo(g, nov, noe);
    vertexGene(g, nov, noe);
 

 

    return 1;
}
