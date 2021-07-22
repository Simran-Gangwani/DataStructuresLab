#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head=NULL,*n;
int c=0;
void insert_at_beg()
{
	n=(struct node *)malloc(sizeof(struct node));
	printf("Enter the value : ");
	scanf("%d",&(n->data));
        n->next=head;
	head=n;
	c++;
}
void insert_at_specific(int pos)
{
    c++;
	n=(struct node *)malloc(sizeof(struct node));
	printf("Enter the value : ");
	scanf("%d",&(n->data));
	int i;
	struct node *t=head;
	for(i=0 ; (i<pos-1) && (t->next!=NULL); i++)
 		t=t->next;
	if(t==NULL)
		printf("No such position exist\n");
	else
	{
		n->next=t->next;
		t->next=n;
	}
}
void insert_at_end()
{
    c++;
    n=(struct node *)malloc(sizeof(struct node));
	printf("Enter the value : ");
	scanf("%d",&(n->data));


	struct node *t=head;
	while(t->next!=NULL)
		t=t->next;
	t->next=n;
	n->next=NULL;

}

void display()
{
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		struct node *t=head;
		printf("The list is : ");
		while(t!=NULL)
		{
			printf("%d ",t->data);
			t=t->next;
		}
		printf("\n");
	}
}
int isEmpty()
{
	if(head==NULL)
		return 1;
	else
		return 0;
}

void main()
{
	int ch;
	printf("1.Insert\n");
	printf("2.Display\n");
	printf("3.Exit\n");
	while(1)
	{
		printf("enter your choice :");
		scanf("%d",&ch);
		if(ch==1)
		{

			int pos;
			printf("Enter the position: ");
			scanf("%d",&pos);

			if(pos<0)
			{
				printf("invalid position\n");
				return;
			}

			if(pos==0)
				insert_at_beg();
			else if(pos<c)
				insert_at_specific(pos);
			else if(pos==c)
				insert_at_end();

			else
				printf("invalid position\n");
		}
		else if(ch==2)
			display();
		else if(ch==3)
			return;
		else
			printf("wrong input");
	}
}



