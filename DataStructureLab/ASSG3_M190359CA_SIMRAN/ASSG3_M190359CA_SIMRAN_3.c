#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
}*start=NULL;
FILE *fp1,*fp2;
int size,a[1000],l,r;
struct node *insertion(struct node *n,int key)
{
    if(n==NULL)
    {
        n=(struct node *)malloc(sizeof(struct node));
        n->data=key;
        n->left=n->right=NULL;
    }
    else if(key<=n->data)
        n->left=insertion(n->left,key);
    else if(key>n->data)
        n->right=insertion(n->right,key);

}
int height(struct node *n)
{
    if(n==NULL)
    return -1;
    else
    {
        l=height(n->left);
        r=height(n->right);
        if(l>r)
            return (l+1);
        else
            return (r+1);
    }

}
void main()
{
    int i,h;
  fp1=fopen("input.txt","r");
  fp2=fopen("output.txt","w");
  if(fp1==NULL)
  {
      fprintf(fp2,"No such file exist");
      return;
  }
  fscanf(fp1,"%d",&size);
  //printf("%d ",size);
  if(size==0)
  {
    fprintf(fp2,"no node");
    return;
  }
  for(i=0;i<size;i++)
    fscanf(fp1,"%d",&a[i]);

    for(i=0;i<size;i++)
        start=insertion(start,a[i]);

    h=height(start);
    fprintf(fp2,"%d",h);
    fclose(fp1);
    fclose(fp2);
}
