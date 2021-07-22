#include<stdio.h>

int size=8,stack[8],top=-1;
int isEmpty()
{
	if(top==-1)
		return 0;
	else
		return 1;
}
int isFull()
{
	if(top>=size)
		return 1;
	else
		return 0;
}
void push()
{

	if(isFull()==1)
		printf("OverFlow!!");
	else
	{
		printf("Enter an element : ");
		scanf("%d",&stack[++top]);

	}
}
void pop()
{
	if(isEmpty()==0)
		printf("Underflow");
	else
		printf("Deleted element is : %d\n",stack[top--]);
}
void display()
{
    if(isEmpty()==0)
        printf("Stack is empty");
    else{

    printf("stack is :");
	int i;
	for(i=top;i>=0;i--)
		printf("%d ",stack[i]);
    }
    printf("\n");

}
void main()
{
	int ch,e,f;
	printf("1.is empty \n");
	printf("2.PUSH\n");
	printf("3.POP\n");
	printf("4.is full \n");
	printf("5.Display\n");
	printf("6.exit\n");
	while(1)
	{
		printf("enter your choice: ");
		scanf("%d",&ch);
	if(ch==1)
	{
		if(isEmpty()==0)
			printf("Stack is empty\n");
		else
			printf("Stack is not empty\n");
	}
	else if(ch==2)
		push();
	else if(ch==3)
		pop();
	else if(ch==4)
	{
		if(isFull()==1)
			printf("Stack is Full\n");
		else
			printf("stack is not full\n");
	}
	else if(ch==5)
		display();
	else if(ch==6)
		return;
	else
		printf("Wrong choice ");
	}
}


