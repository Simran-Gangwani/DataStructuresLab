#include<stdio.h>
#include<stdlib.h>
int size,*a;
int top=-1,flag=0;
void push(int data)
{
    if(top>=size-1)
    create();
    a[++top]=data;

}
void create()
{

    int size2;
    size2=size*2;
    int *b,i;
    b=(void *)malloc(size2*(sizeof(int)));
    for(i=0;i<size;i++)
        b[i]=a[i];
    free(a);
    a=(void *)malloc(size2*(sizeof(int)));
    for(i=0;i<=top;i++)
        a[i]=b[i];

    size=size2;


}
void pop()
{
    if(top==-1)
        printf("underflow");
    else
        printf("deleted value : %d",a[top--]);
}
void display()
{
    if(top==-1)
        printf("stack is empty");
    else
        for(int i=top;i>=0;i--)
        printf("%d ",a[i]);
printf("\n");
}
void main()
{

    printf("Enter size of array A :");
    scanf("%d",&size);
    a=(void *)malloc(size*(sizeof(int)));
    int ch,data;
    printf("1-PUSH\n");
    printf("2-POP\n");
    printf("3-Display\n");
    printf("4-Exit\n");
    while(1)
    {
        printf("enter your choice : ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter a value :");
            scanf("%d",&data);



                    push(data);


        }
        else if(ch==2)
            {
               pop();
            }
            else if (ch==3)
            {

                    display();

            }
            else if(ch==4)
                return;
            else
                printf("wrong choice");
    }
}
