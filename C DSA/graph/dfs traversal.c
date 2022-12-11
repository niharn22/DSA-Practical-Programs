#include<stdio.h>
#include<stdlib.h>

int source,v,e,time,visited[20],G[20][20];
void DFS(int i)
{
    int j;
    visited[i]=1;
    printf("%d->",i+1);
    for(j=0;j<v;j++)
    {
        if(G[i][j]==1 && visited[j]==0)
        DFS(j);
    }
}
int main()
{
    int i,j,v1,v2;
    printf("-----------------Graphs-----------------\n");
    printf("Enter number of edges : ");
    scanf("%d\n",&e);
    printf("Enter number of vertices : ");
    scanf("%d\n",&v);
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
            G[i][j]=0;
    }
    // Creating Edges
    for(i=0;i<e;i++)
    {
        printf("Enter edges (format: V1 V2) : ");
        scanf("%d%d",&v1,&v2);
        G[v1-1][v2-1]=1;
    }
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
            printf("%d",G[i][j]);
        printf("\n");
    }
    printf("Enter Source: \n");
    scanf("%d\n",&source);
    DFS(source-1);
    return 0;
}
