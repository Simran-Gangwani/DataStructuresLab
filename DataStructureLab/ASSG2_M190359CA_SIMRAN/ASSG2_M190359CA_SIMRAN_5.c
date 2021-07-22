#include<stdio.h>
#include<stdlib.h>
FILE *fp1,*fp2;
struct node{
int data;
struct node *left,*right;
}*root=NULL;
int b[50],x=0;
struct node *insert(struct node *n,int key)
{

    if(n == NULL)
    {
        n=(struct node*)malloc(sizeof(struct node));
        n->data=key;
        n->left=NULL;
        n->right=NULL;
    }
    else if(key < n->data)
    {

        n->left=insert(n->left,key);
    }
    else if(key > n->data)
    {


        n->right=insert(n->right,key);
    }
    else
        fprintf(fp2,"Duplicate key\n");
        return n;

}
void in_order(struct node *n)
{
    if(n==NULL)
        return;
    in_order(n->left);
    //printf("%d ",n->data);
    b[x++]=n->data;

    in_order(n->right);
}
struct node *del(struct node *root,int key)
{
     if(root==NULL)
    {
        return root;

    }
    if (key < root->data)
        root->left = del(root->left, key);
    else if (key > root->data)
        root->right = del(root->right, key);
    else
    {
    if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);

            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);

            return temp;
        }


        struct node* temp = root->right;
         while (temp && temp->left != NULL)
        temp = temp->left;
        root->data = temp->data;
        root->right = del(root->right, temp->data);
    }

}
int l,r;
int tree_height(struct node *n)
{
    if(n==NULL)
        return 0;
    else
    {
     l=tree_height(n->left);
     r=tree_height(n->right);
     if(l>r)
            return (l+1);
     else
        return (r+1);
    }
}
void level_order(struct node *n,int level)
{

    if(n==NULL)
    {

        return;
    }

        if(level==0)
            fprintf(fp2,"%d ",n->data);
        else
        {
            level_order(n->left,level-1);
            level_order(n->right,level-1);
        }


}

void main()
{
    int n,k;
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    fscanf(fp1,"%d",&n);
    if(n<=0)
    {
        fprintf(fp2,"Invalid Size");
        return;
    }
    fscanf(fp1,"%d",&k);
    if(k>n)
    {
        fprintf(fp2,"K > N");
        return;
    }
    int a[n],i;
    for(i=0;i<n;i++)
        fscanf(fp1,"%d",&a[i]);
    for(i=0;i<n;i++)
        root=insert(root,a[i]);

        in_order(root);

      root=  del(root,b[n-k]);

      x=0;
        in_order(root);


            int height=tree_height(root);

            for(i=0;i<height;i++)
                level_order(root,i);
    fclose(fp1);
    fclose(fp2);
}
