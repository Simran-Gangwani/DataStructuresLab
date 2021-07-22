#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<string.h>
int adj[3001][3001]={0};
int vis[3001]={0};
int dis[3001];
int vertices;
FILE *fp1,*fp2;
int find_Min();
long long int mst_prims(int src);
//Extarct minimum
//Prim’s algorithm and its implementation for adjacency matrix representation of graphs.
//Following are the detailed steps.


//3) While Min Heap is not empty, do following
//…..a) Extract the min value node from Min Heap. Let the extracted vertex be u.
//…..b) For every adjacent vertex v of u, check if v is in Min Heap (not yet included in MST). If v is in Min Heap and its key value is more than weight of u-v, then update the key value of v as weight of u-v.
int main()
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

    int n,e,u,v,w,i,src,j;
    fscanf(fp1,"%d%d",&n,&e);
//nitially, key value of first vertex is 0 and INF (infinite) for all other vertices
    for(i=1;i<=n;i++)
    {
        dis[i]=INT_MAX;
        vis[i]=0;
    }
    //The set mstSet is initially empty and keys assigned to vertices are {0, INF, INF, INF, INF, INF, INF, INF}
//1) Create a Min Heap of size V where V is the number of vertices in the given graph. Every node of min heap contains vertex number and key value of the vertex.
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            adj[i][j]=-1;
    }
    vertices=n;
    //loop to insert values
    for(i=0;i<e;i++)
    {
        fscanf(fp1,"%d%d%d",&u,&v,&w);
        if(adj[u][v]==-1)
        {
            adj[u][v]=w;
            adj[v][u]=w;
        }
        else if(adj[u][v]>w)
        {
            adj[u][v]=w;
            adj[v][u]=w;
        }
    }
    /*
    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
        printf("%d",adj[i][j]);
        */
    fscanf(fp1,"%d",&src);
    long long int cost=mst_prims(src);
    //output
    fprintf(fp2,"%lld\n",cost);
    return 0;
}
int find_Min()
{

//Pick the vertex with minimum key value and not already included in MST
    int i=1;
    int index;
    int min=INT_MAX;
    while(i<=vertices)
    {
        if(vis[i]==0)
        {
            if(dis[i]<=min)
            {
            min=dis[i];
            index=i;
            }
        }
        i++;
    }
    return index;
}
//minimum spanning tree Prims
/*
void decrease_key(struct min_heap *heap,int v, int key)
{
    struct pq_node *t;
    int i;
    i=heap->vis[v];
    heap->pq[i]->key=key;
    while(i>0 && heap->pq[(i-1)/2]->key>heap->pq[i]->key)
    {
        heap->vis[heap->pq[i]->v]=(i-1)/2;
        heap->vis[heap->pq[(i-1)/2]->v]=i;


        t=heap->pq[(i-1)/2];
        heap->pq[(i-1)/2]=heap->pq[i];
        heap->pq[i]=t;

        min_heapify(heap,0);
        //printf("%d %d",i,parent(i));
        i=(i-1)/2;
        //min_heapify(heap,i);
    }
}*/
long long int mst_prims(int src)
{
    //printf("emter");
    dis[src]=0;
    int next,cost=0,i;
    for(int discovered=0;discovered<vertices;discovered++)
    {
        //Pick a vertex u which is not there in mstSet and has minimum key value.
        next=find_Min();
        cost+=dis[next];
        //Update key value of all adjacent vertices of u.
        vis[next]=1;
        //2) Initialize Min Heap with first vertex as root (the key value assigned to first vertex is 0). The key value assigned to all other vertices is INF (infinite).
        // adj nodes update
        for(i=1;i<=vertices;i++)
        {
            if(adj[next][i]>=0)
            {
                if(vis[i]==0)
                {
                    if(dis[i]>adj[next][i])
                        dis[i]=adj[next][i];
                }
            }
        }
    }
    //output
    return cost;
}
/*struct pq_node *extract_min(struct min_heap *heap)
{
    //printf("ente");
    min_heapify(heap,0);
    struct pq_node *min,*l,*f;
    l=heap->pq[heap->size-1];
    f=heap->pq[0];
    heap->pq[0]=l;


    heap->vis[f->v]=heap->size-1;
    heap->vis[l->v]=0;
    heap->size--;

    min_heapify(heap,0);
    printf("   %d",f->v);
    return f;
   // printf("exe");
}
int parent(int x)
{
    return ((x-1)/2);
}
*/

