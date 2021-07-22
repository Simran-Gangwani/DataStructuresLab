#include<stdio.h>
struct node
{
    int data;
    struct node *prev,*next;
}*head=NULL,*n;
int c=0;
void insert()
{
    c++;
    printf("%d",c);
    struct node *t;
    int i=0;
    n=(struct node *)malloc(sizeof(struct node));

    printf("Enter the value : ");scanf("%d",&(n->data));
    if(head==NULL)
    {
        n->prev=NULL;
        n->next=NULL;
        head=n;
    }
    else if(head->next==NULL)
    {
      head->next=n;
      n->prev=head;
      n->next=NULL;
    }
    else
    {
       t=head;i=1;
        while((i<c/2)&&(t->next!=NULL))
        {
            t=t->next;
            i++;
        }
        //printf("%d",t->data);
        n->next=t->next;
        n->prev=t;
        t->next->prev=n;
        t->next=n;

    }
}
void display()
{
    struct node *t;
    t=head;
    if(head==NULL)
        printf("List is empty");
    else
    {
        printf("LIST IS : ");
        while(t!=NULL)
        {printf("%d ",t->data);
        t=t->next;
        }
        printf("\n");
    }
}
void main()
{
    int ch;
    printf("1.Insert at middle\n");
    printf("2.Display\n");
    printf("3.Exit\n");
    while(1)
    {
        printf("Enter your choice : ");
        scanf("%d",&ch);
        if(ch==1)
            insert();
        else if(ch==2)
            display();
        else if(ch==3)
            return;
        else
            printf("wrong input");
    }
}
