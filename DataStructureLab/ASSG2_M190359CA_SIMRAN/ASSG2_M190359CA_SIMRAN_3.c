#include<stdio.h>
#include<stdlib.h>
#include<math.h>
FILE *fp1,*fp2;
int size;
int a[100],b[100],x=0,c=0;
void in_order(int lev)
{
     if(lev<size && x<size)
    {
        in_order((2*lev)+1);
        b[x++]=a[lev];
        in_order((2*lev)+2);
    }
      return;

}
void sort()
{
    int min,i,j,t;

    for(i=0;i<size;i++)
    {
        min=b[i];
        for(j=i+1;j<size;j++)
        {
            if(b[j]<min)
                min=b[j];
        }

        if(min<b[i])
        {
           t=min;
           min=b[i];
           b[i]=t;
            c++;
        }

    }
}
void main()
{
    int i;
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    if(fp1==NULL)
        fprintf(fp2,"File not found");
    fscanf(fp1,"%d",&size);
    for(i=0;i<size;i++)
        fscanf(fp1,"%d",&a[i]);
       in_order(0);

       sort();
       printf("\n");


       fprintf(fp2,"minimum swap=%d",c);
            fclose(fp1);
            fclose(fp2);

}
