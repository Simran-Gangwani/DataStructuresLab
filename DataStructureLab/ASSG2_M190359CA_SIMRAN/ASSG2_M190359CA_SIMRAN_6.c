#include<stdio.h>
#include<stdlib.h>
FILE *fp1,*fp2;
int inor[20],pror[20],size;
struct node{
int data;
struct node *right,*left;
}*root=NULL;
int inx=0;
int binary_search(int l,int h,int key)
{
    int i;
    for(i=l;i<=h;i++)
    {
        if(inor[i]==key)
        {
          return i;
          break;
        }
    }
    return -1;
}
struct node *create_bt(int start,int end)
{

  if(start>end)
        return  NULL;
  struct node *t;
  t=(struct node *)malloc(sizeof(struct node));
  t->data=pror[inx++];
  t->left=t->right=NULL;
  if(start==end)
    return t;
  int in_index=binary_search(start,end,t->data);
//printf("%d ",in_index);

  t->left=create_bt(start,in_index-1);
  t->right=create_bt(in_index+1,end);

  return t;
}
void post_order(struct node *n)
{
    if(n==NULL)
        return;
    post_order(n->left);
    post_order(n->right);
    fprintf(fp2,"%d ",n->data);
}
void main()
{

    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    if(fp1==NULL)
        fprintf(fp2,"File doesnt exist\n");
    fscanf(fp1,"%d",&size);

    //printf("%d",size);

    int i,flag=0;
    for(i=0;i<size;i++)
        fscanf(fp1,"%d",&inor[i]);
    for(i=0;i<size;i++)
        fscanf(fp1,"%d",&pror[i]);
        for(i=0;i<size;i++)
        {
            flag=0;
            for(int j=0;j<size;j++)
            {
                if(inor[i]==pror[j])
                    flag=1;
            }
            if(flag==0)
            {
                fprintf(fp2,"wrong input\n");
                return;
            }

        }



    root=create_bt(0,size-1);
    if(root==NULL)
        fprintf(fp2,"wrong input\n");
    else
    {
        fprintf(fp2,"post order traversal : ");
        post_order(root);

    }
    fclose(fp1);
    fclose(fp2);
}

