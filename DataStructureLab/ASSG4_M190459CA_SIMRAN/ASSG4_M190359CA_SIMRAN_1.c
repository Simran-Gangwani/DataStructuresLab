#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fp1,*fp2;
int m,n;
int matrix[20][20];
char status[20][20];
void dfs(int v)
{
    int i;
    fprintf(fp2,"%d ",v);
    strcpy(status[v],"gray");
    for(i=0;i<m;i++)
    {
        if(matrix[v][i]==1 && strcpy(status[i],"white")==0)
            dfs(i);
    }
    strcpy(status[v],"black");
}
void dfs_traversal(int s)
{
    dfs(s);
    for(int i=0;i<m;i++)
    {
        if(strcmp(status[i],"white")==0)
            dfs(i);
    }

}
void main()
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    int i,j,k,x,y,s;
    fscanf(fp1,"%d%d",&m,&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            matrix[i][j]=0;
        }
    }
    for(k=0;k<n;k++)
    {
        fscanf(fp1,"%d%d",&x,&y);
        matrix[x][y]=1;

    }
    fscanf(fp1,"%d",&s);
    for(i=0;i<m;i++)
        strcpy(status[i],"white");
        dfs_traversal(s);
        fclose(fp1);
        fclose(fp2);
}
