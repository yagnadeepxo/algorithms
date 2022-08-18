// to find spanning tree with min cost
// enter the number of nodes 
// enter the adjacency matrix
// if there is a zero then make it 999

// in kruskal function loop through the matrix and find
// min no 
// min=cost[i][j]
 
// then after performing kruskal algo main step

// cost[a][b]=cost[b][a]=999

#include<stdio.h>

void kruskal(int cost[20][20],int n){
    int parent[20] = {0};
    int a,b,u,v;
    int ne = 1;
    int mincost = 0;
    int min = 999;
    while(ne<n){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(cost[i][j]<min){
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        if(parent[u]){
            u=parent[u];
        }
        if(parent[v]){
            v=parent[v];
        }
        if(u!=v){
            printf("%d edge (%d,%d) = %d",ne++,a,b,min);
            parent[v]=u;
            mincost = mincost +min;
        }
        cost[a][b]=cost[b][a] = 999;
    }
    printf("the minimum wiring cost %d",&mincost);
}

int main(){
    int cost[20][20];
    int n;
    printf("enter the number of nodes");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0){
                cost[i][j]=999;
            }
        }
    }
    printf("the minimum cost spanning tree is ");
    kruskal(cost,n);
}
