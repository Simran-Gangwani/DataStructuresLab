#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
}*root=NULL;
int size,a[100],b[100];
FILE *fp;
struct node *bst(struct node *n,int key)
{

    if(n == NULL)
    {
        n=(struct node*)malloc(sizeof(struct node));
        n->data=key;
        n->left=NULL;
        n->right=NULL;

    }
    else if(key < n->data)
        n->left=bst(n->left,key);
    else if(key > n->data)
        n->right=bst(n->right,key);
    else
        printf("Duplicate key");
        return n;
}
struct node *pre_traversal(struct node *node)
{

    static int x=0;
    if(node==NULL)
        return;
    //printf("%d ",node->data);
    b[x++]=node->data;
    pre_traversal(node->left);
    pre_traversal(node->right);

}
int search(int n)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(b[i]==n)
            return i;
    }
    return -1;
}
void main()
{
    int i,size;
    FILE *fp,*fp1;
    fp=fopen("input.txt","r");
    if(fp==NULL)
    {
        printf("no such file exist");
        return;
    }
    fscanf(fp,"%d",&size);

    int a[size];
    for(i=0;i<size;i++)
        fscanf(fp,"%d",&a[i]);



    for(i=0;i<size;i++)
    {
       root = bst(root,a[i]);
    }

    int x,y,l,h;
    fscanf(fp,"%d%d",&x,&y);
    pre_traversal(root);

    fclose(fp);
    fp1=fopen("output.txt","w");
    fprintf(fp,"Preorder traversal of BST : ");
    for(i=0;i<size;i++)
        fprintf(fp1,"%d ",b[i]);
        int flag=0,in1,max=0,in2,t;
for(i=0;i<size;i++)
{
    if(b[i]==x)
    {
        flag=1;
        in1=i;
    }
}
if(flag==0)
    fprintf(fp1,"X not found");
flag=0;
for(i=0;i<size;i++)
{
    if(b[i]==y)
    {
        flag=1;
        in2=i;
}
}
if(flag==0)
    fprintf(fp1,"Y not found");
if(in1>in2)
{
    t=in1;
    in1=in2;
    in2=t;
}

for(i=in1;i<=in2;i++)
{

    if(b[i]>max)
        max=b[i];
}
fprintf(fp,"\n maximum value = %d",max);
fclose(fp1);



}
