#include<stdio.h>
#include<stdlib.h>
#define INF 10000
FILE *fp1,*fp2;
int **res,n;
char weight[1000][1000][4];
void floyd_warshall()
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(strcmp(weight[i][j],"INF")==0)
                res[i][j]=INF;
            else if(strcmp(weight[i][j],"-INF")==0)
                res[i][j]=-INF;
            else
                res[i][j]=atoi(weight[i][j]);
        }
    }

    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(res[i][k]+res[k][j]<res[i][j])
                    res[i][j]=res[i][k]+res[k][j];

            }
        }
    }
}
void main()
{

    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    fscanf(fp1,"%d",&n);

    int i,j,k;

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                fscanf(fp1,"%s",weight[i][j]);

    res = (int **)malloc(n * sizeof(int *));
    for (i=0;i<n;i++)
         res[i] = (int *)malloc(n * sizeof(int));


    floyd_warshall();
    int flag=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(res[i][j]<0)
            {
                fprintf(fp2,"Graph contain negative cycle\n");
                flag=1;
                break;
                //return;
            }
        }
        if(flag==1)
            break;
    }
    if(flag==0)
    {


    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(res[i][j]==INF)
                fprintf(fp2,"%s ","INF");
            else
                fprintf(fp2,"%d ",res[i][j]);
        }
        fprintf(fp2,"\n");
    }
    }
fclose(fp1);
fclose(fp2);
}
