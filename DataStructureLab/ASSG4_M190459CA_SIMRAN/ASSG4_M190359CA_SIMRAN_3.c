#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *next;
};
struct list
{
    char color[20];
    struct node *start;
};
struct graph
{
    struct list *array;
}*g;
FILE *fp1,*fp2;
int m,n;
int queue[100],rear=-1,front=-1;
void display()
{
    int i;
    for(i=0;i<m;i++)
    {
        fprintf(fp2,"%d ",i);
        struct node *t;
        t=g->array[i].start;
        while(t!=NULL)
        {
            fprintf(fp2,"%d ",t->data);
            t=t->next;
        }
        fprintf(fp2,"\n");
    }
}
void insert_edge(int u,int v)
{
    struct node *vertex;
    vertex=(struct node *)malloc(sizeof(struct node));
    vertex->data=v;
    vertex->next=NULL;
    if(g->array[u].start==NULL)
    {
        g->array[u].start=vertex;
    }
    else
    {
        struct node *temp;
        temp=g->array[u].start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=vertex;
    }
}
void enqueue(int key)
{
    if(front==-1)
        front=0;
    rear=rear+1;
    queue[rear]=key;

}
int dequeue()
{
    int d=(queue[front]);

    front=front+1;
    return d;
}
void breadth_first_search(int s)
{
    strcpy(g->array[s].color,"gray");
    enqueue(s);
    while(front!=-1 && front<=rear)
    {
        int u=dequeue();
        fprintf(fp2,"%d ",u);
        struct node *t;
        t=g->array[u].start;
        while(t!=NULL)
        {
            if(strcmp(g->array[t->data].color,"white")==0)
            {
                strcpy(g->array[t->data].color,"gray");
                enqueue(t->data);
            }
            t=t->next;
        }
        strcpy(g->array[s].color,"black");
    }

}
void main()
{
    int x,y;
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    fscanf(fp1,"%d%d",&m,&n);
    g=(struct graph *)malloc(sizeof(struct graph));
    g->array=(struct list *)malloc(m * sizeof(struct list));
    for(int i=0;i<m;i++)
    {
        g->array[i].start=NULL;
        strcpy(g->array[i].color,"white");
    }
    for(int i=0;i<n;i++)
    {
        fscanf(fp1,"%d%d",&x,&y);
        insert_edge(x,y);
    }
    int s;
    fscanf(fp1,"%d",&s);
    breadth_first_search(s);
    //display();
    fclose(fp1);
    fclose(fp2);

}
