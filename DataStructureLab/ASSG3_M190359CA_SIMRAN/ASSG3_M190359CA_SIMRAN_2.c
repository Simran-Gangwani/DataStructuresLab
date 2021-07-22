
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data,balance;
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
struct node *rotate_right(struct node *n)
{
 struct node *t;
 t=n->left;
 n->left=t->right;
 t->right=n;
 return t;
}
struct node *rotate_left(struct node *n)
{
 struct node *t;
 t=n->right;
 n->right=t->left;
 t->left=n;
 return t;
}
struct node *insert_right_bal(struct node *n)
{
 struct node *t1,*t2;
 t1=n->right;
  if(t1->balance==-1)
  {
      n->balance=0;
      t1->balance=0;
      n=rotate_left(n);
  }
  else
  {
      t2=t1->left;
      if(t2->balance==-1)
      {
          n->balance=1;
          t1->balance=0;
      }
      else if(t2->balance==1)
      {
          n->balance=0;
          t1->balance=-1;
      }
      else if(t2->balance==0)
      {
          n->balance=0;
          t1->balance=0;
      }
      t2->balance=0;
      n->right=rotate_right(t1);
      n=rotate_left(n);
  }
  return n;
}
struct node *insert_right_check(struct node *n,int *tall)
{
        if(n->balance==0)
        {
            n->balance=-1;
        }
        else if(n->balance==1)
        {
            n->balance=0;
            *tall=0;
        }
        else if(n->balance==-1)
        {
            n=insert_right_bal(n);
            *tall=0;
        }
        return n;
}

struct node *insert_left_bal(struct node *n)
{
        struct node *t1,*t2;
        t1=n->left;
        if(t1->balance==1)
        {
            n->balance=0;
            t1->balance=0;
            n=rotate_right(n);
        }
        else
        {
            t2=t1->right;
            if(t2->balance==-1)
            {
                n->balance=0;
                t1->balance=1;
            }
            else if(t2->balance==1)
            {
                n->balance=-1;
                t1->balance=0;

            }
            else if(t2->balance==0)
            {
                n->balance=0;
                t1->balance=0;
            }
            t2->balance=0;
            n->left=rotate_left(t1);
            n=rotate_right(n);
        }
        return n;
}
struct node *insert_left_check(struct node *n,int *tall)
{
    if(n->balance==0)
        n->balance=1;
    else if(n->balance==-1)
    {
        n->balance=0;
        *tall=0;
    }
    else if(n->balance==1)
    {
        n=insert_left_bal(n);
        *tall=0;
    }
}
struct node *insert(struct node *n,int key)
{
    static int tall;
    if(n == NULL)
    {
        n=(struct node*)malloc(sizeof(struct node));
        n->data=key;
        n->left=NULL;
        n->right=NULL;
        n->balance=0;
        tall=1;
    }
    else if(key < n->data)
    {
        n->left=insert(n->left,key);
        if(tall==1)
            n=insert_left_check(n,&tall);
    }
    else if(key > n->data)
    {
        n->right=insert(n->right,key);
        if(tall==1)
            n=insert_right_check(n,&tall);
    }
    else
    {
        fprintf(fp2,"Duplicate key\n");
        tall=0;
    }
        return n;

}
struct node *del_right_check(struct node *n,int *shorter)
{
        if(n->balance==0)
        {
            n->balance=0;
            *shorter=0;
        }
        else if(n->balance==-1)
        {
            n->balance=0;
        }
        else if(n->balance==1)
        {
            if(n->left->balance==0)
            {
                n->balance=1;
                n->left->balance=-1;
                *shorter=0;
                n=rotate_right(n);
            }
            else
                n=insert_left_bal(n);
        }
        return n;
}
struct node *del_left_check(struct node *n,int *shorter)
{
        if(n->balance==0)
        {
            n->balance=-1;
            *shorter=0;
        }
        else if(n->balance==1)
        {
            n->balance=0;
        }
        else if(n->balance==-1)
        {
          if(n->right->balance==0)
          {
              n->balance=-1;
              n->right->balance=1;
              *shorter=0;
              n=rotate_left(n);
          }
          else
            n=insert_right_bal(n);
        }
        return n;
}
struct node *del(struct node *n,int key)
{
     struct node *t,*suc;
     static int shorter;
     if(n==NULL)
     {
         fprintf(fp2,"NOT FOUND\n");
         shorter=0;
         return n;
     }
     else if(key<n->data)
     {
         n->left=del(n->left,key);
         if(shorter==1)
            n=del_left_check(n,&shorter);
     }
     else if(key>n->data)
     {
         n->right=del(n->right,key);
         if(shorter==1)
            n=del_right_check(n,&shorter);
     }
     else
     {
         if(n->left!=NULL && n->right!=NULL)
         {
             suc=n->right;
             while(suc->left!=NULL)
             {
                 suc=suc->left;
             }
             n->data=suc->data;
             n->right=del(n->right,suc->data);
             if(shorter==1)
                n=del_right_check(n,&shorter);
         }
         else
         {
             t=n;
             if(n->left!=NULL)
                n=n->left;
             else if(n->right!=NULL)
                n=n->right;
             else
                n=NULL;
             free(t);
             shorter=1;
         }
     }
return n;
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
struct node *inorder(struct node *n)
{
    if(n!=NULL)
    {
        inorder(n->left);
        fprintf(fp2,"%d ",n->data);
        inorder(n->right);
    }

}
int min()
{
    struct node *t;
    t=root;
    if(t==NULL)
        return -1;
    else
    {
        while(t->left!=NULL)
            t=t->left;
        //fprintf(fp2,"\n");
        return (t->data);
    }
}
int max()
{
    struct node *t;
    t=root;
    if(t==NULL)
        return -1;

    else
    {
        while(t->right!=NULL)
            t=t->right;
        //fprintf(fp2,"\n");
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
      fprintf(fp2,"\n");
  }
  else if(strcmp(ch,"delt")==0)
  {
      fscanf(fp1,"%d",&key);
      if(key>=0)
      {
        root=  del(root,key);
        fprintf(fp2,"\n");
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
          //fprintf(fp2,"In-order Traversal : ");
          inorder(root);
          /*for(int k=0;k<x;k++)
          fprintf(fp2,"%d ",in[k]);*/
          fprintf(fp2,"\n");
      }
  }
  else if(strcmp(ch,"prer")==0)
  {
      if(root==NULL)
        fprintf(fp2,"tree has no node \n");
      else
      {
          //fprintf(fp2,"Pre-order Traversal : ");
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
          //fprintf(fp2,"Post-order Traversal : ");
          post_order(root);
          fprintf(fp2,"\n");
      }
  }
  else if(strcmp(ch,"minm")==0)
  {
       s= min();
       if(s==-1)
        fprintf(fp2,"NIL\n");
       else
       fprintf(fp2,"%d\n",s);
  }

  else if(strcmp(ch,"maxm")==0)
  {
       l= max();
       if(l==-1)
        fprintf(fp2,"NIL\n");
       else
       fprintf(fp2,"%d\n",l);
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
