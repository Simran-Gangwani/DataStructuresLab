#include<stdio.h>
#include<stdlib.h>
FILE *fp1,*fp2;
struct node
{
    int u,v,w;
};
struct graph
{
    struct node *array;
}*g;
int m,n,s;
void bellman_ford()
{
    int cost[m],i,j;
    for(i=0;i<m;i++)
        cost[i]=10000;
    cost[s]=0;
    for(i=0;i<m-1;i++)
    {
        for(j=0;j<n;j++)
        {
            cost[g->array[j].v]=(cost[g->array[j].v]>cost[g->array[j].u] + g->array[j].w) ? (cost[g->array[j].u] + g->array[j].w):cost[g->array[j].v];
        }
    }
    for(i=0;i<n;i++){
        if(cost[g->array[i].v] > cost[g->array[i].u] + g->array[i].w)
        {
            fprintf(fp2,"Given graph contain a negative cycle\n");
            return;
        }
    }
    for(i=0;i<m;i++)
    {
        if(cost[i]==10000)
            fprintf(fp2,"%d INF\n",i);
        else
            fprintf(fp2,"%d %d\n",i,cost[i]);
    }
}
void main()
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

    fscanf(fp1,"%d",&m);
    fscanf(fp1,"%d",&n);

    int i,x,y,z;
    g=(struct graph *)malloc(sizeof(struct graph));
    g->array=(struct node *)malloc(n * sizeof(struct node));

    for(i=0;i<n;i++)
    {
        fscanf(fp1,"%d%d%d",&x,&y,&z);
        g->array[i].u=x;
        g->array[i].v=y;
        g->array[i].w=z;
    }
    fscanf(fp1,"%d",&s);
bellman_ford();
fclose(fp1);
fclose(fp2);}
