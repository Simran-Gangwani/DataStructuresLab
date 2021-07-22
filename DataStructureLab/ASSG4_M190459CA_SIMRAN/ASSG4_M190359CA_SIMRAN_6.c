#include<stdio.h>
#include<stdlib.h>
FILE *fp1,*fp2;
struct node
{
    int occurance;
    int data;
    struct node *next;
}*start1=NULL,*start2=NULL;
struct list
{

    struct node *head;
};
struct hash
{
    struct list *array;
}*h;
int size1,size2;

struct node *create_list(int size)
{
    struct node *head=NULL,*n;
    int i;
    for(i=0;i<size;i++)
    {
        n=(struct node *)malloc(sizeof(struct node));
        fscanf(fp1,"%d",&n->data);
        n->next=NULL;
        n->occurance=1;
        if(head==NULL)
            head=n;
        else{
            struct node *t;
            t=head;
            while(t->next!=NULL)
                t=t->next;
            t->next=n;
        }
    }
        return head;
}
void merge(struct node *start)
{
    int k,index;

    int m=(size1 + size2);
    struct node *t;
    t=start;
    while(t!=NULL)
    {
        k=t->data;
        index=k%m;
        if(h->array[index].head==NULL)
        {
            h->array[index].head=t;
            t=t->next;
            h->array[index].head->next=NULL;
        }
        else
        {
            int flag=0;
    struct node *t2;


            t2=h->array[index].head;
            if(t2->data==k)
                {
                    flag=1;
                    t2->occurance=2;
                }
            while(t2->next!=NULL)
            {
                if(t2->data==k)
                {
                    flag=1;
                    t2->occurance=2;
                    break;
                }
                else
                    t2=t2->next;
            }
            if(t2->data==k)
            {
                 flag=1;
                    t2->occurance=2;
            }

            if(flag==0)
            {
                t2->next=t;
                t=t->next;
                t2->next->next=NULL;
            }
            else
                t=t->next;
    }}
}
void display_union()
{
    int i=0;
    for(i=0;i<(size1 + size2);i++)
    {
        if(h->array[i].head!=NULL)
        {
            struct node *t;
            t=h->array[i].head;
            while(t!=NULL)
            {
                fprintf(fp2,"%d ",t->data);
                t=t->next;
            }
        }
    }
}
void display_intersection()
{
    int i=0;
    for(i=0;i<(size1 + size2);i++)
    {
        if(h->array[i].head!=NULL)
        {
            struct node *t;
            t=h->array[i].head;
            while(t!=NULL)
            {
                if(t->occurance==2)
                    fprintf(fp2,"%d ",t->data);
                t=t->next;
            }
        }
    }
}
void print_list()
{
    for(int i=0;i<(size1 + size2);i++)
    {
        if(h->array[i].head!=NULL)
        {
            struct node *t=h->array[i].head;
            while(t!=NULL)
            {
                printf("%d",t->occurance);
                t=t->next;
            }
        }
    }
}
void main()
{
    int i;
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    fscanf(fp1,"%d%d",&size1,&size2);

    start1=create_list(size1);
    start2=create_list(size2);
    h=(struct hash *)malloc(sizeof(struct hash));
    h->array=(struct list *)malloc((size1+size2)*sizeof(struct list));
    for(i=0;i<(size1+size2);i++)
    {
        //g->array[i].occurance=0;
        h->array[i].head=NULL;
    }
    merge(start1);
    merge(start2);
//    print_list();
    display_union();
    fprintf(fp2,"\n");
    display_intersection();
fclose(fp1);
fclose(fp2);

}
