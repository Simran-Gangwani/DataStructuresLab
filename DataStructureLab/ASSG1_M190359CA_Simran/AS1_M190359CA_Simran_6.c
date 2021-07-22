#include<stdio.h>
int stack1[100],stack2[100];
int top1=-1,top2=-1,c=0;
void push_1(int data)
{
    stack1[++top1]=data;
}
int pop_1()
{
    return(stack1[top1--]);
}
void push_2(int data)
{
    stack2[++top2]=data;
}
int pop_2()
{
    return(stack2[top2--]);
}
void enqueue()
{
    int data;
    printf("Enter value : ");
    scanf("%d",&data);
    push_1(data);
    c++;
}
void dequeue()
{

    int i;
    for(i=0;i<=c;i++)

        push_2(pop_1());

    pop_2;
    c--;
    for(i=0;i<=c;i++)

        push_1(pop_2());

}
void display()
{
    int i;
    for(i=0;i<=top1;i++)
        printf("%d ",stack1[i]);
}
void main()
{
     int ch;

    printf("\n1 - Enqueue element into queue");
    printf("\n2 - Dequeue element from queue");
    printf("\n3 - Display from queue");
    printf("\n4 - Exit");

    while (1)
    {
        printf("\nEnter choice :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return;
        default:
            printf("Wrong choice");
        }
    }
}
