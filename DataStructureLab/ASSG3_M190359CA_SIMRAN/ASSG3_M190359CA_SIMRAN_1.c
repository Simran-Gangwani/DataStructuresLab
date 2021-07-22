#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char color;
    int data;
    struct node *left,*right,*parent;

}*root=NULL,*sentinel;
int flag=0,in[200],x=0;
FILE *fp1,*fp2;
void rotate_left(struct node *n)
{
    struct node *t1;
    t1=n->right;
    n->right=t1->left;
    if(t1->left!=sentinel)
        t1->left->parent=n;
    t1->parent=n->parent;
    if(n->parent == sentinel)
        root=t1;
    else if(n == n->parent->left)
        n->parent->left=t1;
    else
        n->parent->right=t1;
    t1->left=n;
    n->parent=t1;
}
void rotate_right(struct node *n)
{

    struct node *t;
    t=n->left;
    n->left=t->right;
    if(t->right!=sentinel)
        t->right->parent=n;
    t->parent=n->parent;
    if(n->parent==sentinel)
        root=t;
    else if(n == n->parent->right)
        n->parent->right=t;
    else
        n->parent->left=t;
    t->right=n;
    n->parent=t;
}
int find(int item,struct node **l)
{
    struct node *p;
    if(root==sentinel)
    {
        *l=sentinel;
        return 0;
    }
    if(item==root->data)
    {
        *l=root;
        return 1;
    }
    if(item<root->data)
        p=root->left;
    else
        p=root->right;
    while(p!=sentinel)
    {
        if(item==p->data)
        {
            *l=p;
            return 1;
        }
        if(item<p->data)
        {
            p=p->left;
        }
        else
        {
            p=p->right;
        }
    }
    *l=sentinel;
    return 0;
}
void insert_balance(struct node *n)
{
    struct node *uncle,*par,*grandpar;
    while(n->parent->color == 'R')
    {
        par=n->parent;
        grandpar=par->parent;
        if(par==grandpar->left)
        {
            uncle=grandpar->right;
            if(uncle->color=='R')
            {
                par->color='B';
                uncle->color='B';
                grandpar->color='R';
                n=grandpar;
            }
            else
            {

                if(n==par->right)
                {
                    rotate_left(par);
                    n=par;
                    par=n->parent;
                }
                par->color='B';
                grandpar->color='R';
                rotate_right(grandpar);
            }
        }
        else
        {
            if(par==grandpar->right)
            {
                uncle=grandpar->left;
                if(uncle->color=='R')
                {
                    par->color='B';
                    uncle->color='B';
                    grandpar->color='R';
                    n=grandpar;
                }
                else
                {
                    if(n==par->left)
                    {
                        rotate_right(par);
                        n=par;
                        par=n->parent;
                    }
                    par->color='B';
                    grandpar->color='R';
                    rotate_left(grandpar);
                }
            }
        }
    }
    root->color='B';
}

void insert(int key)
{
    struct node *t,*p,*par;
    par=sentinel;
    p=root;
    while(p!=sentinel)
    {
        par=p;
        if(key<p->data)
            p=p->left;
        else if(key>p->data)
            p=p->right;
        else
        {
            fprintf(fp2,"Duplicate keys\n");
            return;
        }
    }
    t=(struct node *)malloc(sizeof(struct node));
    t->data=key;
    t->left=sentinel;
    t->right=sentinel;
    t->color='R';
    t->parent=par;
    if(par==sentinel)
        root=t;
    else if(t->data < par->data)
        par->left=t;
    else
        par->right=t;
    insert_balance(t);
}
void del_bal(struct node *n)
{
    struct node *sib;
    while(n!=root)
    {
        if(n==n->parent->left)
        {
            sib=n->parent->left;
            if(sib->color=='R')
            {
                sib->color='B';
                n->parent->color='R';
                rotate_left(n->parent);
                sib=n->parent->right;
            }
            if(sib->left->color=='B' && sib->right->color == 'B')
            {
                sib->color='R';
                if(n->parent->color=='R')
                {
                    n->parent->color='B';
                    return;
                }
                else
                    n=n->parent;
            }
            else
            {
                if(sib->right->color == 'B')
                {
                    sib->left->color='B';
                    sib->color='R';
                    rotate_right(sib);
                    sib=n->parent->right;
                }
                sib->color=n->parent->color;
                n->parent->color='B';
                sib->right->color='B';
                rotate_left(n->parent);
                return;

            }
        }
        else
        {
            sib=n->parent->left;
            if(sib->color == 'R')
            {
                sib->color='B';
                n->parent->color='R';
                rotate_right(n->parent);
                sib=n->parent->left;
            }
            if(sib->right->color == 'B' && sib->left->color == 'B')
            {
                sib->color='R';
                if(n->parent->color=='R')
                {
                    n->parent->color='B';
                    return;
                }
                else
                    n=n->parent;
            }
            else
            {
                if(sib->left->color=='B')
                {
                    sib->right->color='B';
                    sib->color='R';
                    rotate_left(sib);
                    sib=n->parent->left;
                }
                sib->color=n->parent->color;
                n->parent->color='B';
                sib->left->color='B';
                rotate_right(n->parent);
                return;
            }
        }
    }
}
void del(int key)
{
    struct node *child,*p,*suc;
    if(!find(key,&p))
    {
        fprintf(fp2,"NOT FOUND\n");
        return;
    }
    if(p->left!=sentinel||p->right!=sentinel)
    {
        suc=p;
        while(suc->left!=sentinel)
            suc=suc->left;
        p->data=suc->data;
        p=suc;
    }
    if(p->left!=sentinel)
        child=p->left;
    else
        child=p->right;
    child->parent=p->parent;
    if(p->parent == sentinel)
        root=child;
    else if(p==p->parent->left)
        p->parent->left=child;
    else
        p->parent->right=child;
    if(child==root)
        child->color='B';
    else if(p->color=='B')
    {
        if(child!=sentinel)
            child->color='B';
        else
            del_bal(child);
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
void main()
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    sentinel=(struct node *)malloc(sizeof(struct node));
    sentinel->data=-1;
    sentinel->color='B';
    root=sentinel;
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
      insert(key);
      fprintf(fp2,"\n");
  }
  else if(strcmp(ch,"delt")==0)
  {
      fscanf(fp1,"%d",&key);
      if(key>=0)
      {
         del(key);
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
          in_order(root);
          for(int k=0;k<x;k++)
          fprintf(fp2,"%d ",in[k]);
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

