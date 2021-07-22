#include<stdio.h>
#include<stdlib.h>
FILE *fp1,*fp2;
int t,a,b,n,*cal,size;

void max_heapify(int i)
{
    int largest,l,r,t;
    largest=i;
    l=(2*i)+1;
    r=(2*i)+2;
    if(l<n && cal[l]>cal[i])
        largest=l;
    if(r<n && cal[r]>cal[i])
        largest=r;
    if(largest!=i)
    {
        t=cal[i];
        cal[i]=cal[largest];
        cal[largest]=t;
        max_heapify(largest);
    }
}
void build_max_heap()
{
    for(int i=(n/2);i>=0;i--)
        max_heapify(i);
}
void heap_sort()
{
    build_max_heap();
    int t;
    for(int i=(n-1);i>0;i--)
    {
        t=cal[n-1];
        cal[n-1]=cal[0];
        cal[0]=t;
        n--;
        max_heapify(0);
    }
}
void dish_res()
{
    int cala=0,calb=0;
    for(int i=0;i<size;i++)
    {
        if(a>=cal[i])
        {
            a-=cal[i];
            cala++;
        }
        if(b>=cal[i])
        {
            b-=cal[i];
            calb++;
        }
    }
        if(cala>calb)
            fprintf(fp2,"Raghu Won\n");
        else if(calb>cala)
            fprintf(fp2,"Sayan Won\n");
        else
            fprintf(fp2,"Tie\n");

}
void main()
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

    fscanf(fp1,"%d",&t);
    while(t!=0)
    {
        fscanf(fp1,"%d%d%d",&a,&b,&n);
        size=n;
        cal=(int *)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)
            fscanf(fp1,"%d",&cal[i]);
        heap_sort();
        dish_res();
        t--;
    }
    fclose(fp1);
    fclose(fp2);
}
