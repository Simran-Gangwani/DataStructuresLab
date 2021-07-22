#include<stdio.h>
#include<stdlib.h>
struct bst
{
    int data;
    struct bst *left,*right;
}*root=NULL;
int size,a[1000],b[1000],l,r,x=0,value=0;
FILE *fp1,*fp2;
struct bst *insertion(struct bst *n,int key)
{
    if(n==NULL)
    {
        n=(struct bst *)malloc(sizeof(struct bst));
        n->data=key;
        n->left=n->right=NULL;
    }
    else if(key<=n->data)
        n->left=insertion(n->left,key);
    else if(key>n->data)
        n->right=insertion(n->right,key);

}

void post_order(struct bst *n)
{
    if(n!=NULL)
    {
        post_order(n->left);
        post_order(n->right);
        fprintf(fp2,"%d ",n->data);
    }

}
void pre_order(struct bst *n)
{
    if(n!=NULL)
    {
        fprintf(fp2,"%d ",n->data);
        pre_order(n->left);
        pre_order(n->right);
    }
}
void in_order(struct bst *n)
{
    if(n!=NULL)
    {
        in_order(n->left);
        n->data=n->data + value;
        value=n->data;
        in_order(n->right);
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

  if(size==0)
  {
    fprintf(fp2,"no node");
    return;
  }
  for(i=0;i<size;i++)
    fscanf(fp1,"%d",&a[i]);

    for(i=0;i<size;i++)
        root=insertion(root,a[i]);
      in_order(root);

        pre_order(root);
        fprintf(fp2,"\n");
        post_order(root);


fclose(fp1);
fclose(fp2);
}

