/*c program to implement floyd warshall algorithm for all shortest path in graph (data structure)*/
#include<stdio.h>
#define inf 9999
struct graph{
    int v;
    int e;
    int *adj;
};
void printsolution(struct graph *);

void printfsolution(struct graph *g){
    int i,j;
    for(i=0;i<g->v;i++)
        for(j=0;j<g->v;j++)
            if(*(g->adj+i*g->v+j)==inf)
            printf("%7s",inf);
        else
            printf("%7d",*(g->adj+i*g->v+j));
printf("\n");

    }
void floydwarshall(struct graph *g){
    int i,j,k;
    int dist[g->v][g->v];
    for(i=0;i<g->v;i++)
        for(j=0;j<g->v;j++)
        dist[i][j]=*(g->adj+i*g->v+j);


    for(k=0;k<g->v;k++){
        for(i=0;i<g->v;i++)
        for(j=0;j<g->v;j++){
            if(dist[i][j]+dist[k][j]<dist[i][j])
                dist[i][j]=dist[i][k]+dist[k][j];
        }
    }

    for(i=0;i<g->v;i++)
        for(j=0;j<g->v;j++)
        *(g->adj+i*g->v+j)=dist[i][j];
    }
    void printsolution(struct graph *g){
        int i,j;
        for(i=0;i<g->v;i++){
            for(j=0;j<g->v;j++){
                if(*(g->adj+i*g->v+j)==inf)
                    printf("%7s","inf");
                else
                    printf("%7d",*(g->adj+i*g->v+j));
            }
        }printf("\n");
    }

main()
{
    struct graph *g;
    int i,j;
    int matrix[4][4]={ {0,5,inf,10},
                       {inf,0,3,inf},
                       {inf,inf,0,1},
                       {inf,inf,inf,0}};
    g=(struct graph *)malloc(sizeof(struct graph));
    g->v=4;
    g->e=4;
    g->adj=malloc((g->v)*(g->v)*sizeof(int));
     for(i=0;i<g->v;i++)
         for(j=0;j<g->v;j++)
         *(g->adj+i*g->v+j)=matrix[i][j];
     printf("original distances\n");
     printsolution(g);
     floydwarshall(g);
     printf("matrix below shows the shortest path between every node");
     printfsolution(g);

}
