#include <stdio.h>
#include <string.h>
#define INFINITY 99999
#define MAX 10
 
void dijkstra(int G[MAX][MAX],int n,int startnode);


char nomi_stazioni[5][10];
 
int main()
{
    int G[MAX][MAX],i,j,n,partenza;
    n = 5; // da leggere dal file
    
    strcpy(nomi_stazioni[0],"Pesaro");
    strcpy(nomi_stazioni[1],"Bologna");
    strcpy(nomi_stazioni[2],"Ancona");
    strcpy(nomi_stazioni[3],"Torino");
    strcpy(nomi_stazioni[4],"Milano");

    // Pesaro
    G[0][0] = 0; // Pesaro
    G[0][1] = 158; // Bologna
    G[0][2] = 60; // Ancona
    G[0][3] = 0; // Torino
    G[0][4] = 400; // Milano
    
    // Bologna
    G[1][0] = 158; // Pesaro
    G[1][1] = 0; // Bologna
    G[1][2] = 210; // Ancona
    G[1][3] = 0; // Torino
    G[1][4] = 202; // Milano
    
    // Ancona
    G[2][0] = 0; // Pesaro
    G[2][1] = 0; // Bologna
    G[2][2] = 0; // Ancona
    G[2][3] = 505; // Torino
    G[2][4] = 412; // Milano

    // Torino
    G[3][0] = 415; // Pesaro
    G[3][1] = 0; // Bologna
    G[3][2] = 505; // Ancona
    G[3][3] = 0; // Torino
    G[3][4] = 140; // Milano

    // Milano
    G[4][0] = 400; // Pesaro
    G[4][1] = 0; // Bologna
    G[4][2] = 0; // Ancona
    G[4][3] = 0; // Torino
    G[4][4] = 0; // Milano
    
    partenza = 0; // Pesaro

    dijkstra(G,n,partenza);
    
    return 0;
}
 
void dijkstra(int G[MAX][MAX],int n,int startnode)
{
 
    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;
    
    //pred[] stores the predecessor of each node
    //count gives the number of nodes seen so far
    //create the cost matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];
    
    //initialize pred[],distance[] and visited[]
    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    
    while(count<n-1)
    {
        mindistance=INFINITY;
        
        //nextnode gives the node at minimum distance
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
            
            //check if a better path exists through nextnode            
            visited[nextnode]=1;
            for(i=0;i<n;i++)
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
        count++;
    }
 
    //print the path and distance of each node
    for(i=0;i<n;i++)
        if(i!=startnode)
        {
            printf("\nDistance of %s (%d)=%d",nomi_stazioni[i],i,distance[i]);
            printf("\nPath=%s",nomi_stazioni[i], i);
            
            j=i;
            do
            {
                j=pred[j];
                printf("<-%s",nomi_stazioni[j]);
            }while(j!=startnode);
    }
    printf("\n");
}
