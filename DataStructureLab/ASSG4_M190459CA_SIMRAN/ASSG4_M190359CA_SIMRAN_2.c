#include<stdio.h>
#include<stdlib.h>
FILE *fp1,*fp2;
int map[100][100],island=0;
int m,n;
void depth_first_search(int i,int j)
{
    if(i>=0 && i<m && j>=0  && j<n)
    {
        if(map[i][j]==1)
        {
        map[i][j]=-1;
        depth_first_search(i+1,j);
        depth_first_search(i,j+1);
        depth_first_search(i-1,j);
        depth_first_search(i,j-1);
        depth_first_search(i+1,j+1);
        depth_first_search(i-1,j-1);
        depth_first_search(i+1,j-1);
        depth_first_search(i-1,j+1);
        }
    }
}
void main()
{
    int i,j;
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    fscanf(fp1,"%d%d",&m,&n);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            fscanf(fp1,"%d",&map[i][j]);

        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(map[i][j]==1)
                {
                    //map[i][j]=-1;
                    depth_first_search(i,j);
                    island=island+1;
                }
            }
        }
        fprintf(fp2,"%d",island);
        fclose(fp1);
        fclose(fp2);

}
