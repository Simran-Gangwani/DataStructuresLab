#include<stdio.h>
#include<stdlib.h>
struct node
{
    int u,v,w;
};
struct graph
{
   struct node *array;
}*g;
FILE *fp1,*fp2;
int m,n,s;
int *disjoint;
int partition(int l,int h)
{
    int pivot=g->array[h].w;
    struct node t;
    int i,j;
    i=l-1;
    for(j=l;j<h;j++)
    {
        if(g->array[j].w<pivot)
        {
            i++;
            t=g->array[i];
            g->array[i]=g->array[j];
            g->array[j]=t;
        }
    }
    t=g->array[i+1];
    g->array[i+1]=g->array[h];
    g->array[h]=t;
    return(i+1);

}
void quick_sort(int l,int h)
{
    if(l < h)
    {
        int p=partition(l,h);
        quick_sort(l,p-1);
        quick_sort(p+1,h);
    }
}
int find(int x)
{
    if(disjoint[x]!=-1 && disjoint[x]!=x)
    {
        disjoint[x]=find(disjoint[x]);
    }
    return disjoint[x];
}
void fun_union(int x,int y)
{
    disjoint[y]=x;
}
void mst_kruskal()
{
    int i=0,cost[m-1],in=0,a,b;
    quick_sort(0,n-1);
    disjoint=(int *)malloc(sizeof(int)*m);

    for(i=0;i<m;i++)
    {
        disjoint[i]=-1;
    }
    i=0;
    disjoint[g->array[0].u]=g->array[0].u;
    while(in<m-1 && i<n)
    {
        struct node temp=g->array[i++];
        //printf("%d %d %d\n",temp.u,temp.v);
        a=find(temp.u);
        b=find(temp.v);
        //printf("%d %d\n",a,b);

        if(a!=b ||((a==-1) && (b==-1)))
        {
            cost[in++]=temp.w;
            fun_union(temp.u,temp.v);
        }
    }

    int sum=0;
    for(i=0;i<m-1;i++)
        sum+=cost[i];
    fprintf(fp2,"%d",sum);
}
void display()
{

    int i;
    for(i=0;i<n;i++)
    {
        fprintf(fp2,"%d %d %d\n",g->array[i].u,g->array[i].v,g->array[i].w);

    }
}
void main()
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    fscanf(fp1,"%d%d",&m,&n);

    g=(struct graph *)malloc(sizeof(struct graph));
    g->array=(struct node *)malloc(n * sizeof(struct node));
    int i,x,y,z;
    for(i=0;i<n;i++)
    {
        fscanf(fp1,"%d%d%d",&x,&y,&z);
        g->array[i].u=x-1;
        g->array[i].v=y-1;
        g->array[i].w=z;
    }
    mst_kruskal();
    //display();
    fclose(fp1);
    fclose(fp2);
}
