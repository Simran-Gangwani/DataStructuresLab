#include<stdio.h>
void main()
{
    int n;
    printf("Enter the size : ");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("Invalid size");
        return;
    }
    int a[n];
    printf("Enter elements in an array : ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Elements in reverse order : ");
    for(int i=(n-1);i>=0;i--)
        printf("\n%d",a[i]);
}
