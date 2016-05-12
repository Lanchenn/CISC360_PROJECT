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
};

void createVertexList(struct graph *g, int numberOfVertices){
	// struct graph *g;
		srand ( time(NULL) );
		g->index=numberOfVertices;
	for(int i=0; i<numberOfVertices; i++){
		g->vlist[i].next= NULL;
		g->vlist[i].vID=i;
		g->vlist[i].weight = rand()%numberOfVertices;
		g->vlist[i].visited=0;
	}
	//return g;
}

//
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
	while(tmp1 != NULL){
		if(tmp1->vID == y){
			result=1;
		}
		tmp1 = tmp1->next;
	}
	while(tmp2 != NULL){
		if(tmp2->vID == x){
			result = 1;
		}
		tmp2 = tmp2->next;
	}
	return result;

}


int findFullness(struct graph *g, int v){
	struct vertex *temp = &g->vlist[v];
	int count = 0;
	while(temp->next!= NULL){
		temp= temp->next;
		count++;
	}
	if(count >= g->index-1)
		return 1;
	else
		return 0;
}



void NedgeFirst(struct graph *g, int maxNumberOfEdges){
	srand ( time(NULL) );
	int count =0;
	if(maxNumberOfEdges>g->index)
		count = g->index;
	else
		count = maxNumberOfEdges;
	//printf("count: %d\n", count);
	for(int eIndex=0; eIndex< count; eIndex++){
		int linkvertex = (rand()%(g->index));

		int templ= linkvertex;
			int flag = 0;
		while(eIndex==linkvertex ||checkDuplicate(g , eIndex, linkvertex)||checkDuplicate(g , linkvertex, eIndex)||findFullness(g,eIndex)||findFullness(g,linkvertex)){
			if(findFullness(g,eIndex)||findFullness(g,linkvertex)){
				if(findFullness(g,eIndex)){
					if(eIndex<g->index-1){
						//printf("loop2\n");
						eIndex++;
					}
					else{
						//printf("loop3\n");
						eIndex=0;
					}
				}
				else{
					if(linkvertex<g->index-1){
						//printf("loop5\n");
						linkvertex++;
					}
					else{
						//printf("loop6\n");
						linkvertex=0;
					}
				}
			}
			else{
				if(linkvertex<g->index-1){
					//printf("loop7\n");
					linkvertex++;
				}
				else{
					//printf("loop8\n");
					linkvertex=0;
				}
				if(linkvertex==templ){
					//printf("loop9\n");
					flag = 1;
				}
				if(flag){
					eIndex++;
					flag=0;
				}
			}
		}

		//printf("in NedgeFirst: %d\n", linkvertex);
		struct vertex *temp1 = (struct vertex *)malloc(sizeof(struct vertex));
		struct vertex *temp2 = (struct vertex *)malloc(sizeof(struct vertex));


		int Rweight = rand()%(g->index+1);
		temp1->vID=linkvertex;
		temp1->weight = Rweight;
		temp1->next = NULL;
		temp1->visited=0;

		temp2->vID=eIndex;
		temp2->weight = Rweight;
		temp2->next = NULL;
		temp2->visited=0;
		findLast(g, eIndex, temp1);
		findLast(g, linkvertex, temp2);

	}
}

void edgeGenerator(struct graph *g, int nedge){
	////printf("pass1\n");
	srand ( time(NULL) );
//	for(int i=1; i<= g->index; i++){
	int eIndex=0;
		////printf("pass2\n");
		
				int edgeID=0;

	while(eIndex < nedge){
		int linkvertex1 = (rand()%(g->index));
		int linkvertex2 = (rand()%(g->index));
			//printf("edgeGenerator pass1 \n" );
		////printf("pass3\n");
			int templ1=linkvertex1;
			int templ2= linkvertex2;
			int flag = 0;

					//printf("in edgeGenerator link1 before: %d\n", linkvertex1);
		//printf("in edgeGenerator link2 before:  %d\n", linkvertex2);


		while(linkvertex1==linkvertex2 || checkDuplicate(g , linkvertex1, linkvertex2)|| findFullness(g,linkvertex1)||findFullness(g,linkvertex2)){
		//	//printf("%d\n", checkDuplicate(g , linkvertex1, linkvertex2));
		//	//printf("%d\n", findFullness(g,linkvertex1));
			if(findFullness(g,linkvertex1)||findFullness(g,linkvertex2)){
				if(findFullness(g,linkvertex1)){
					if(linkvertex1<g->index-1){
			//			//printf("loop2\n");
						linkvertex1++;
					}
					else{
			//			//printf("loop3\n");
						linkvertex1=0;
					}
				}
				else{
					if(linkvertex2<g->index-1){
			//			//printf("loop5\n");
						linkvertex2++;
					}
					else{
			//			//printf("loop6\n");
						linkvertex2=0;
					}
				}
			}
			else{
				if(linkvertex2<g->index-1){
			//		//printf("loop7\n");
					linkvertex2++;
				}
				else{
			//		//printf("loop8\n");
					linkvertex2=0;
				}
				if(linkvertex2==templ2){
			//		//printf("loop9\n");
					flag = 1;
				}
				if(flag){
					linkvertex1++;
					flag=0;
				}
			}
		}

			//printf("edgeGenerator pass2 \n" );

		// //printf("pause\n");
		// //printf("in edgeGenerator link1: %d\n", linkvertex1);
		// //printf("in edgeGenerator link2: %d\n", linkvertex2);
	//		//printf("pass5\n");
		struct vertex *temp1 = (struct vertex *)malloc(sizeof(struct vertex));
		struct vertex *temp2 = (struct vertex *)malloc(sizeof(struct vertex));


		int Rweight = rand()%(g->index+1);
		temp1->vID=linkvertex1;
		temp1->weight=Rweight;
		temp1->next=NULL;
		temp1->visited=0;
		temp2->vID=linkvertex2;
		temp2->weight=Rweight;
		temp2->next=NULL;
		temp2->visited=0;
		findLast(g, linkvertex1, temp2);
		findLast(g, linkvertex2, temp1);
		eIndex++;

// for(int i=0; i<g->index; i++){
//  	//printf("%d: ", g->vlist[i].vID);
//  	struct vertex *tmp;
//  	tmp = &g->vlist[i];
//  	while(tmp->next != NULL){
//  		tmp=tmp->next;
//  		//printf("[%d] ",tmp->vID);
//  	}
//  	 //printf("\n");
// }



		//printf("nodeinsert \n");
    printf("now generating edge number: %d\n", edgeID);
    edgeID++;

	}
}
	



// int findRoot(struct graph *g, struct vertex *v){
// 	for(int i=0; i<g->index; i++){
// 		if(g->vlist[i].vID==v->vID)
// 			return i;
// }
// return -1;
// }


// void DFS(struct graph *g, struct vertex *v);

// void DFS(struct graph *g, struct vertex *v){
// 	//printf("pass3\n");
// 	struct vertex *tmp=v;
// 		while(g->vlist[findRoot(g, tmp)].visited!=1 && tmp->next != NULL){
// 				//printf("pass4\n");
// 				g->vlist[findRoot(g, tmp)].visited=1;
// 			tmp=tmp->next;
// 			DFS(g, tmp);
// 		}
// 	}

// void BFS(struct graph *g){
// 	struct Queue *q;
// 	q= createQueue(numberOfVertices);
// 	Enqueue();
// }



void makeVisit(struct graph *g){
	struct vertex *tmp1 = &g->vlist[0];
	g->vlist[0].visited=1;
	int flag = 1;
	while(flag){
		flag = 0;
		for(int j=0; j<g->index; j++){
			if(g->vlist[j].visited==1)
				tmp1=&g->vlist[j];
			while(tmp1!=NULL){
				for(int i=0; i <g->index; i++){
				//	//printf("i: %d\n", i);
					if(i == tmp1->vID && g->vlist[i].visited==0){
				//		//printf("temp1 de iD: %d\n", tmp1->vID);
						g->vlist[i].visited=1;
						flag =1;
					}
				}
				tmp1=tmp1->next;
			}
		}
	}

}



int checkConnectionTF(struct graph *g){
	for(int i=0; i < g->index; i++){
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
	int *groupA;
	int *groupB;
	groupA=(int *)malloc(sizeof(int) * numberOfVertices);
	groupB=(int *)malloc(sizeof(int) * numberOfVertices);
	int j=0;
	int k=0;
	for(int i=0; i<g->index; i++){
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

	    srand ( time(NULL) );



	int linkvertex1 = (rand()%j);
	int linkvertex2 = (rand()%k);
	int templ2= linkvertex2;
	int flag = 0;
	while(checkDuplicate(g, groupA[linkvertex1], groupB[linkvertex2])||findFullness(g,groupA[linkvertex1])||findFullness(g,groupA[linkvertex2])){
		printf("nothing\n");
		if(findFullness(g,groupA[linkvertex1])||findFullness(g,groupA[linkvertex2])){
				if(findFullness(g,groupA[linkvertex1])){
					if(linkvertex1<j){
						//printf("loop2\n");
						linkvertex1++;
					}
					else{
						//printf("loop3\n");
						linkvertex1=0;
					}
				}
				else{
					if(linkvertex2<k){
						//printf("loop5\n");
						linkvertex2++;
					}
					else{
						//printf("loop6\n");
						linkvertex2=0;
					}
				}
			}
			else{
				if(linkvertex2<k){
					//printf("loop7\n");
					linkvertex2++;
				}
				else{
					//printf("loop8\n");
					linkvertex2=0;
				}
				if(linkvertex2==templ2){
					//printf("loop9\n");
					flag = 1;
				}
				if(flag){
					linkvertex1++;
					flag=0;
				}
			}
	}





	int Rweight= rand()%(g->index+1);





	temp1->vID=groupA[linkvertex1];
	temp1->weight=Rweight;
	temp1->next=NULL;
	temp1->visited=0;
	temp2->vID=groupB[linkvertex2];
	temp2->weight=Rweight;
	temp2->next=NULL;
	temp2->visited=0;

	findLast(g, groupA[linkvertex1], temp2);
	findLast(g, groupB[linkvertex2], temp1);

	for(int i = 0; i<g->index; i++){
		g->vlist[i].visited=0;
	}


}




int main(){
	
	printf("pass\n");

    struct graph *g;
 
    // g = malloc(sizeof(struct graph));
    int nov, noe;
    printf("type number of vertices u want: \n");
    scanf("%d", &nov);
    printf("type percentage of edges u want: \n");
    scanf("%d", &noe);
  //  //printf("pass3\n");


    int numberOfVertices = nov;

    // float percent2 = (float)noe/100;
     int percent = ((numberOfVertices*(numberOfVertices-1))/2)*((float)noe/100);
    // int percent1 = numberOfVertices*(numberOfVertices-1)/2;
    // //printf("number of edges: %d\n", percent);
    //     //printf("number of edges1: %d\n", percent1);
    //     //printf("%f\n", percent2);
    int maxNumberOfEdges = percent;

        //printf("%d\n", maxNumberOfEdges);

		g= (struct graph*)malloc(sizeof(struct graph));
		g->vlist = (struct vertex *)malloc(sizeof(struct vertex) * numberOfVertices);
	printf("pass1\n");

    createVertexList(g, numberOfVertices);
	printf("pass2\n");

    NedgeFirst(g, maxNumberOfEdges);
	printf("pass3\n");



    for(int i=0; i<g->index; i++){
 	//printf("%d: ", g->vlist[i].vID);
 	struct vertex *tmp;
 	tmp = &g->vlist[i];
 	while(tmp->next != NULL){
 		tmp=tmp->next;
 		//printf("[%d] ",tmp->vID);
 	}
 	 //printf("\n");
}

	printf("pass4\n");

    int counter=0;
    //printf("pass\n");

   // //printf("pass1\n");
   
if(maxNumberOfEdges-g->index>0){
    makeVisit(g);
	if(!checkConnectionTF(g))
		{
			while(!checkConnectionTF(g)){
				checkConnection(g, numberOfVertices);
				makeVisit(g);
				counter++;
	}
	}
}

	printf("pass5\n");

    //printf("pass1\n");
    //printf("counter for edge: %d\n", counter);

	////printf("%d\n", counter);
 //   //printf("pass2\n");

////printf("%d\n", maxNumberOfEdges-g->index-counter );

if((maxNumberOfEdges-g->index-counter) >0){
	int nedge = maxNumberOfEdges-g->index-counter;
	//    //printf("pass5\n");
	//printf("%d\n", nedge);
    edgeGenerator(g, nedge);

   //     //printf("pass6\n");

}
    //printf("pass2\n");

	printf("pass6\n");

    // g=createVertexList(numberOfVertices);

for(int i=0; i<g->index; i++){
 	printf("%d: ", g->vlist[i].vID);
 	struct vertex *tmp;
 	tmp = &g->vlist[i];
 	while(tmp->next != NULL){
 		tmp=tmp->next;
 		printf("[%d](%d) ",tmp->vID, tmp->weight);
 	}
 	 printf("\n");
}
	printf("pass7\n");

// //printf("pass1\n");
// makeVisit(g);
// for(int i=0; i<g->index;i++){
// 	//printf("%d\n", g->vlist[i].visited);
// }
// //printf("pass2\n");


// if(!checkConnectionTF(g))
// 	{
// 		while(!checkConnectionTF(g)){
// 			checkConnection(g, numberOfVertices);
// 			makeVisit(g);
// }
// }


// for(int i=0; i<g->index; i++){
//  	//printf("%d: ", g->vlist[i].vID);
//  	struct vertex *tmp;
//  	tmp = &g->vlist[i];
//  	while(tmp->next != NULL){
//  		tmp=tmp->next;
//  		//printf("[%d] ",tmp->vID);
//  	}
//  	 //printf("\n");
// }




	char *filename;
	filename = (char *)malloc(sizeof(char) * 20);

	snprintf(filename, 20, "v%de%d.txt", numberOfVertices, maxNumberOfEdges);

		FILE * Output;
	     Output = fopen(filename, "w+");


for(int i=0; i<g->index; i++){
 	fprintf(Output, "%d: ", g->vlist[i].vID);
 	struct vertex *tmp;
 	tmp = &g->vlist[i];
 	while(tmp->next != NULL){
 		tmp=tmp->next;
 		fprintf(Output, "[%d](%d) ",tmp->vID, tmp->weight);
 	}
 	 fprintf(Output, "\n");
}

    fclose(Output);
    free(filename);

    return 1;
}
