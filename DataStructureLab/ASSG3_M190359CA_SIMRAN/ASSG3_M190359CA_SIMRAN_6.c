#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data,pos;
    struct node *left,*right;
}*root=NULL;
FILE *fp1,*fp2;
int size,a[1000];

int x=0,min,max;
struct node *insertion(struct node *n,int key)
{


    if(n==NULL)
    {
        n=(struct node *)malloc(sizeof(struct node));
        n->data=key;
        n->left=n->right=NULL;
        n->pos=x;

    }
    else if(key<=n->data)
    {
        x=n->pos-1;
        min=x;
        n->left=insertion(n->left,key);


    }
    else //if(key>n->data)
    {
        x=n->pos+1;
        max=x;
        n->right=insertion(n->right,key);


    }
    return n;

}

void pre_order(struct node *n,int i)
{
    if(n==NULL)
        return;
        if(n->pos==i)
            fprintf(fp2,"%d ",n->data);
    pre_order(n->left,i);

    pre_order(n->right,i);

}
void main()
{
  fp1=fopen("input.txt","r");
  fp2=fopen("output.txt","w");
  if(fp1==NULL)
  {
      fprintf(fp2,"No such file exist");
      return;
  }
  fscanf(fp1,"%d",&size);

  if(size==0)
  {
    fprintf(fp2,"no node");
    return;
  }
  for(int i=0;i<size;i++)
    fscanf(fp1,"%d",&a[i]);

    for(int i=0;i<size;i++)
        root=insertion(root,a[i]);


        //printf("%d %d",min,max);
        for(int i=min;i<=max;i++)
        {
            pre_order(root,i);
            fprintf(fp2,"\n");
        }
        fclose(fp1);
        fclose(fp2);
}
