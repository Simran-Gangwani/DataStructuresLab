#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
    struct tree *left,*right;
};
struct tree *queue[100];
int size,a[100],front=-1,rear=-1;
FILE *fp1,*fp2;
struct tree *create_binary_tree(struct tree *root,int i)
{
    if(i<size)
    {
    if(root==NULL)
    {
        struct tree *n;
        n=(struct tree *)malloc(sizeof(struct tree));
        n->data=a[i];
        n->right=n->left=NULL;
        root=n;
    }


        root->left=create_binary_tree(root->left,(2*i)+1);
        root->right=create_binary_tree(root->right,(2*i)+2);

    }
    return root;
}
void enqueue(struct tree *s)
{
    if(front==-1)
        front=0;
    rear=rear+1;
    queue[rear]=s;
}
struct tree *dequeue()
{
 struct tree *d;
d=queue[front];
 front=front+1;
 return d;
}
void breadth_first_search(struct tree *s)
{
    struct tree *u;
    enqueue(s);
    while(front!=-1 && front<=rear)
    {
        u=dequeue();
       fprintf(fp2,"%d ",u->data);
        if(u->right!=NULL && u->right->data!=-1)
            enqueue(u->right);
        if(u->left!=NULL && u->left->data!=-1)
            enqueue(u->left);
    }
}
void main()
{
    struct tree *root=NULL;
    int i;
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    fscanf(fp1,"%d",&size);
    for(i=0;i<size;i++)
        fscanf(fp1,"%d",&a[i]);
        root = create_binary_tree(root,0);
breadth_first_search(root);
    //    g=(struct bfs *)malloc(sizeof(struct bfs));
      //  g->arrray=(struct tree *)malloc(size * sizeof(struct tree));

         fclose(fp1);
    fclose(fp2);
}
