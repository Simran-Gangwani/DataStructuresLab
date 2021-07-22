#include<stdio.h>
#include<stdlib.h>
FILE *fp1,*fp2;
int n,s,**weight,*dist,*S;
struct node
{
    int u,v,w;
};
struct queue
{
    struct node **array;
    int count;
    int size;
}*pq;
void create_priority_queue()
{
    pq=(struct queue *)malloc(sizeof(struct queue));
    pq->count=0;
    pq->size=n;
    pq->array=(struct node**)malloc(n* sizeof(struct node*));
}
void min_heapify(int i)
{
    struct node *t;
    int s=i,l,r;
    l=(2*i)+1;
    r=(2*i)+2;
    if(l<pq->count && pq->array[l]->w<pq->array[s]->w )
        s=l;
    if(r<pq->count && pq->array[r]->w<pq->array[s]->w )
        s=r;
    if(s!=i)
    {
       t=pq->array[i];
       pq->array[i]=pq->array[s];
       pq->array[s]=t;
       min_heapify(s);
    }
}
struct node *extract_min()
{
    struct node *min,*l;
        l=pq->array[pq->count-1];
        pq->count--;
    if(S[pq->array[0]->v]!=1)
    {
    min=pq->array[0];
    pq->array[0]=l;
    min_heapify(0);
    }
    else
    {
        pq->array[0]=l;
        min_heapify(0);
        min=pq->array[0];

    }
    return min;
}
void dijkstra()
{
  int i;
  //Initialize single source vertex
  create_priority_queue();//Q<-v[G]
  struct node *vertex;
  for(i=0;i<n;i++)
  {
        dist[i]=10000;
        S[i]=-1;
        vertex=(struct node *)malloc(sizeof(struct node));
        vertex->v=i;
        vertex->w=10000;
        pq->array[i]=vertex;
  }
  dist[s]=0;
  struct node *min=(struct node *)malloc(sizeof(struct node));
  min->v=s;
  min->w=0;
  pq->array[s]=min;
  pq->count=n;
  int u=s;
  while(pq->count!=0)
  {

      //int u=min->v;
      printf("%d",u);
      S[u]=1;
      for(i=0;i<n;i++)
      {
          if(weight[u][i]!=0)
          {
              int d=dist[u]+weight[u][i];
              if(dist[i]==10000 || dist[i]>d)
              {
                  dist[i]=d;
                  pq->array[i]->w=d;
              }

          }
      }
      min=extract_min();
      u=min->v;
  }

}
void main()
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    fscanf(fp1,"%d",&n);
    //printf("%d ",n);
    int i,j;
    weight = (int **)malloc(n * sizeof(int *));
    for (i=0; i<n; i++)
         weight[i] = (int *)malloc(n * sizeof(int));

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            fscanf(fp1,"%d",&weight[i][j]);

    fscanf(fp1,"%d",&s);
        printf("%d",s);
    dist=(int *)malloc(sizeof(int)*n);
    S=(int *)malloc(sizeof(int)*n);
    s=s-1;
    dijkstra();
    for(i=0;i<n;i++)
        fprintf(fp2,"%d %d\n",(i+1),dist[i]);
    fclose(fp1);
    fclose(fp2);
}
