#include<stdio.h>
void main()
{
    int n;
    printf("Enter size of an array : ");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("Invalid size");
        return;
    }
    int a[n],i,j,min;
    printf("Enter elements for an array :");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<n;i++)
    {
        min=a[i];
        j=i-1;
        while((j>=0)&&(min<a[j]))
              {
                  a[j+1]=a[j];
                  j--;
              }
              a[j+1]=min;
    }
    printf("THE SORTED LIST IS :");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
