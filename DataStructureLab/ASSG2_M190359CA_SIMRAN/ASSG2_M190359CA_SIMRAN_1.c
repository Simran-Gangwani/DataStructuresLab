#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *left,*right;
}*root=NULL,*n;
int flag=0,in[20],x=0;
FILE *fp1,*fp2;

struct node *search(struct node *n,int key)
{
    if(n==NULL)
        fprintf(fp2,"NOT FOUND\n");
    else{

        if(key<n->data)
        return(search(n->left,key));
    else if(key>n->data)
        return(search(n->right,key));
        else
            fprintf(fp2,"FOUND\n");
    }


}
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
            flag=1;
            return temp;
        }


        struct node* temp = root->right;
         while (temp && temp->left != NULL)
        temp = temp->left;
        root->data = temp->data;
        root->right = del(root->right, temp->data);
    }

}
struct node *pre_order(struct node *n)
{
 if(n==NULL)
        return;
 fprintf(fp2,"%d ",n->data);
 pre_order(n->left);
 pre_order(n->right);
}
struct node *post_order(struct node *n)
{
 if(n==NULL)
        return;
 post_order(n->left);
 post_order(n->right);
 fprintf(fp2,"%d ",n->data);
}
struct node *in_order(struct node *n)
{
    if(n==NULL)
        return;
    in_order(n->left);
    in[x++]=n->data;
    //fprintf(fp2,"%d ",n->data);
    in_order(n->right);
}
int min()
{
    struct node *t;
    t=root;
    if(t==NULL)
        fprintf(fp2,"NIL\n");
    else
    {
        while(t->left!=NULL)
            t=t->left;
        //fprintf(fp2,"Minimum value = %d\n",t->data);
        return (t->data);
    }
}
int max()
{
    struct node *t;
    t=root;
    if(t==NULL)
        fprintf(fp2,"NIL\n");

    else
    {
        while(t->right!=NULL)
            t=t->right;
        //fprintf(fp2,"Maximum value = %d\n",t->data);
        return t->data;
    }
}
int search_ele(int key)
{
    for(int i=0;i<x;i++)
    {
        if(in[i]==key)
            return i;
    }
    return -1;
}
void predecessor(int k)
{
    int index;
    in_order(root);
    index=search_ele(k);
    if(index==-1)
    {
        fprintf(fp2,"NOT FOUND\n");
        return;
    }
    if(in[index]==min())
    {
        fprintf(fp2,"NIL\n");
        return;
    }
    else
        fprintf(fp2,"%d\n",in[index-1]);
        return;
}
void successor(int k)
{
    int index;
    in_order(root);
    index=search_ele(k);
    if(index==-1)
    {
        fprintf(fp2,"NOT FOUND\n");
        return;
    }
    if(in[index]==max())
        fprintf(fp2,"NIL\n");

    else
        fprintf(fp2,"%d\n",in[index+1]);
}
void main()
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

  char ch[10];
  int key,l,s;
  while(1)
  {
  fscanf(fp1,"%s",ch);
  if(strcmp(ch,"stop")==0)
    return;
  else if(strcmp(ch,"srch")==0)
  {
    fscanf(fp1,"%d",&key);
    search(root,key);

  }
  else if(strcmp(ch,"insr")==0)
  {
      fscanf(fp1,"%d",&key);
      root=insert(root,key);
      fprintf(fp2,"Inserted %d\n",key);
  }
  else if(strcmp(ch,"delt")==0)
  {
      fscanf(fp1,"%d",&key);
      if(key>=0)
      {
        root=  del(root,key);
        fprintf(fp2,"Deleted %d\n",key);
      }
      else
        fprintf(fp2,"wrong key");
  }
  else if(strcmp(ch,"inor")==0)
  {
      if(root==NULL)
        fprintf(fp2,"tree has no node \n");
      else
      {
          fprintf(fp2,"In-order Traversal : ");
          in_order(root);
          for(int k=0;k<x;k++)
          fprintf(fp2,"%d ",in[k]);
          fprintf(fp2,"\n");
      }
  }
  else if(strcmp(ch,"pr0r")==0)
  {
      if(root==NULL)
        fprintf(fp2,"tree has no node \n");
      else
      {
          fprintf(fp2,"Pre-order Traversal : ");
          pre_order(root);
          fprintf(fp2,"\n");
      }
  }
   else if(strcmp(ch,"post")==0)
  {
      if(root==NULL)
        fprintf(fp2,"tree has no node \n");
      else
      {
          fprintf(fp2,"Post-order Traversal : ");
          post_order(root);
          fprintf(fp2,"\n");
      }
  }
  else if(strcmp(ch,"minm")==0)
  {
       s= min();
       fprintf(fp2,"Minimum value = %d\n",s);
  }

  else if(strcmp(ch,"maxm")==0)
  {
       l= max();
       fprintf(fp2,"Maximum value = %d\n",l);
  }
    else if(strcmp(ch,"pred")==0)
    {
        fscanf(fp1,"%d",&key);
        predecessor(key);
    }
    else if(strcmp(ch,"succ")==0)
    {
        fscanf(fp1,"%d",&key);
        successor(key);
    }
    else
        fprintf(fp2,"Wrong choice\n");
  }
  fclose(fp1);
  fclose(fp2);
}
