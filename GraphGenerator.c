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
    int visited;
};

struct graph{
//    struct vertex *vertices[MAXV];
    struct vertex *vlist;
    int index;// index+1 will be the number of vertices
//    int nvertices;
//    int line;
} ;

void createVertexList(struct graph *g, int numberOfVertices){
	// struct graph *g;
	g->index=numberOfVertices;
	g->vlist = (struct vertex *)malloc(sizeof(struct vertex) * numberOfVertices);
	for(int i=0; i<numberOfVertices; i++){
		g->vlist[i].next= NULL;
		g->vlist[i].vID=i;
		g->vlist[i].weight = 0;
		g->vlist[i].visited=0;
	}
	//return g;
}

// 改成加到最后
void findLast(struct graph *g, int i, struct vertex *v){
	struct vertex *tmp;
	tmp = &g->vlist[i];
	while(tmp->next != NULL){
		tmp= tmp->next;
	}
	tmp->next=v;
}

int checkDuplicate(struct graph *g, int x, int y){
	struct vertex *tmp1;
	tmp1 = &g->vlist[x];
	struct vertex *tmp2;
	tmp2 = &g->vlist[y];
	int result=0;
	int m=0;
	while(tmp1->next != NULL){
		printf("1: %d\n", x);
		printf("2: %d\n", y);
				printf("vID: %d\n", tmp1->vID);
		if(tmp1->vID == y){
			result=1;
		}
		tmp1 = tmp1->next;
		m++;
		printf("m: %d\n", m);
	}
	while(tmp2->next != NULL){
		if(tmp2->vID == x){
			result = 1;
		}
		tmp2 = tmp2->next;
	}
	return result;

}

void edgeGenerator(struct graph *g, int maxNumberOfEdges){
	    srand ( time(NULL) );
//	for(int i=1; i<= g->index; i++){

		for(int eIndex=0; eIndex < maxNumberOfEdges;){


			int linkvertex1 = (rand()%(g->index));
			int linkvertex2 = (rand()%(g->index));
							
			if(linkvertex1!=linkvertex2 && !checkDuplicate(g , linkvertex1, linkvertex2)){
				struct vertex *temp1 = (struct vertex *)malloc(sizeof(struct vertex));
				struct vertex *temp2 = (struct vertex *)malloc(sizeof(struct vertex));

				temp1->vID=linkvertex1;
				temp1->weight=0;
				temp1->next=NULL;
				temp1->visited=0;
				temp2->vID=linkvertex2;
				temp2->weight=0;
				temp2->next=NULL;
				temp2->visited=0;
				findLast(g, linkvertex1, temp2);
				findLast(g, linkvertex2, temp1);
				eIndex++;
			}
			else{
				int linkvertex1 = (rand()%g->index)+1;
				int linkvertex2 = (rand()%g->index)+1;
			}
		}
//	}
}

int findRoot(struct graph *g, struct vertex *v){
	for(int i=0; i<g->index+1; i++){
		if(g->vlist[i].vID==v->vID)
			return i;
}
return -1;
}


void DFS(struct graph *g, struct vertex *v);

void DFS(struct graph *g, struct vertex *v){
	printf("pass3\n");
	struct vertex *tmp=v;
		while(g->vlist[findRoot(g, tmp)].visited!=1 && tmp->next != NULL){
				printf("pass4\n");
				g->vlist[findRoot(g, tmp)].visited=1;
			tmp=tmp->next;
			DFS(g, tmp);
		}
	}


int checkConnectionTF(struct graph *g){
	for(int i=0; i < g->index+1; i++){
		if(g->vlist[i].visited==0)
			return 0;
	}
	return 1;
}

// int findMaxDegree(struct graph *g){
// 	int max =0;
// 	int index=0;
// 	for(int i=0; i<index+1; i++){
// 		struct vertex *tmp = &g->vlist[i];
// 		int m=0; 
// 		while(tmp->next != NULL){
// 			m++;
// 			tmp=tmp+next;
// 		}
// 		if(m>max){
// 			max = m;
// 			index= i;
// 		}
// 		}
// 		return index;
// 	}


// void deleteEdge(struct graph *g, int x){
// 	struct vertex *tmp= &g->vlist[x];
// 	while(tmp->next != NULL){
// 		tmp
// 	}
// }




void checkConnection(struct graph *g, int numberOfVertices){
	for(int i = 0; i<g->index+1; i++){
		g->vlist[i].visited=0;
	}
	DFS(g, &g->vlist[0]);
	int *groupA;
	int *groupB;
	groupA=(int *)malloc(sizeof(int) * numberOfVertices);
	groupB=(int *)malloc(sizeof(int) * numberOfVertices);
	int j=0;
	int k=0;
	for(int i=0; i<g->index+1; i++){
		if(g->vlist[i].visited== 1){
			groupA[j]=g->vlist[i].vID;
			j++;
		}
		else{
			groupB[k]=g->vlist[i].vID;
			k++;
		}
	}

	struct vertex *temp1 = (struct vertex *)malloc(sizeof(struct vertex));
	struct vertex *temp2 = (struct vertex *)malloc(sizeof(struct vertex));

	temp1->vID=groupA[0];
	temp1->weight=0;
	temp1->next=NULL;
	temp1->visited=0;
	temp2->vID=groupB[0];
	temp2->weight=0;
	temp2->next=NULL;
	temp2->visited=0;

	findLast(g, groupA[0], temp2);
	findLast(g, groupB[0], temp1);




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

    edgeGenerator(g, maxNumberOfEdges);

    // g=createVertexList(numberOfVertices);

for(int i=0; i<g->index; i++){
 	printf("%d: ", g->vlist[i].vID);
 	struct vertex *tmp;
 	tmp = &g->vlist[i];
 	while(tmp->next != NULL){
 		tmp=tmp->next;
 		printf("[%d] ",tmp->vID);
 	}
 	 printf("\n");
}

// printf("pass1\n");
// DFS(g, &g->vlist[0]);
// printf("pass2\n");

// while(!checkConnectionTF(g)){
// 	checkConnection(g, numberOfVertices);
// }



// for(int i=0; i<g->index; i++){
//  	printf("%d: ", g->vlist[i].vID);
//  	struct vertex *tmp;
//  	tmp = &g->vlist[i];
//  	while(tmp->next != NULL){
//  		tmp=tmp->next;
//  		printf("[%d] ",tmp->vID);
//  	}
//  	 printf("\n");
// }




   

    return 1;
}
