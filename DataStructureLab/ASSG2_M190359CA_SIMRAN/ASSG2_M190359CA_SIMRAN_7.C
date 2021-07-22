#include<stdio.h>
#include<stdlib.h>
FILE *fp1,*fp2;
int a[100],n,t;
void main()
{
    int i,sum,j,flag;
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

    fscanf(fp1,"%d",&n);
    fscanf(fp1,"%d",&t);
    if(n<=0)
    {
        fprintf(fp2,"wrong size");
        return;
    }
    for(i=0;i<n;i++)
        fscanf(fp1,"%d",&a[i]);

    while(t!=0)
    {

       fscanf(fp1,"%d",&sum);
       flag=0;
       for(i=0;i<n;i++)
       {

           for(j=i+1;j<n;j++)
           {
               if(sum==(a[i]+a[j]))
               {
                 flag=1;

                fprintf(fp2,"%d %d\n",a[i],a[j]);
               break;
               }
           }
           if(flag==1)
            break;

       }
       if(flag==0)
            fprintf(fp2,"NOT POSSIBLE\n");
        t--;



    }
    fclose(fp1);
    fclose(fp2);
}
