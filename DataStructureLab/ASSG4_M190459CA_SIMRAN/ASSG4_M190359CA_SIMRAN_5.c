#include<stdio.h>
#include<stdlib.h>
#include<math.h>
FILE *fp1,*fp2;
int hash[100];
char coll;
int m,count=0,c1=0,c2=1,r;
int prime(int x)
{
    int n,i,flag=0;
    for(n=x-1;n>=2;n--)
    {
        flag=0;
        for(i=2;i<n/2;i++)
        {
            if(n%i==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            return n;
    }
}
void insert(int key)
{
int k1=key%m;
    if(coll=='a')
    {
        int i=0,index;

        do
        {

            index=(k1+i)%m;
            if(hash[index]==key)
            {
                fprintf(fp2,"Duplicate keys\n");
                count--;
                break;
            }
            else if(hash[index]==-1)
            {
                hash[index]=key;
                break;
            }

                i++;
        }while( i!=m);
        if(i==m)
            fprintf(fp2,"primary clustering problem\n");
    }
    else if(coll=='b')
    {
        int i=0,index;
        do
        {
            index=(k1 + (c1*i) + (c2*i*i))%m;
            if(hash[index]==key)
            {
                fprintf(fp2,"Duplicate keys \n");
                count--;
                break;
            }
            else if(hash[index]==-1)
            {
                hash[index]=key;
                break;
            }
            i++;
        }while(i!=m);
        if(i==m)
            fprintf(fp2,"Secondary Clustering Problem\n");
    }
    else if(coll=='c')
    {
        int i=0,index,k2=r-(key%r);
        do
        {
            index=(k1 + (i*k2))%m;
            if(hash[index]==key)
            {
                fprintf(fp2,"Duplicate keys\n");
                count--;
                break;
            }
            else if(hash[index]==-1)
            {
                hash[index]=key;
                break;
            }
            i++;
        }while(i!=m);
        if(i==m)
            fprintf(fp2,"Clustering Problem\n");

    }
}
int search(int key)
{
    if(coll=='a')
    {
        int i=0,index,k1=key%m;
        do
        {

            index=(k1+i)%m;
            if(hash[index]==key)
                return 1;
            i++;
        }while(i<m);
        return -1;
    }
    else if(coll=='b')
    {
        int i=0,index,k1=key%m;
        do
        {
            index=(k1 + (c1*i) + (c2*i*i))%m;
            if(hash[index]==key)
                return 1;
            i++;
        }while(i<m);
        return -1;
    }
    else if(coll=='c')
    {
        int i=0,index,k1=key%m,k2;
        k2=r-(key%r);
        do
        {
            index=(k1 + (i*k2))%m;
            if(hash[index]==key)
                return 1;
            i++;
        }while(i<m);
        return -1;
    }
}
void deletion(int key)
{
    if(coll=='a')
    {
        int i=0,index,k1=key%m,flag=0;
        do
        {

            index=(k1+i)%m;
            if(hash[index]==key)
                {
                    hash[index]=-1;
                    flag=1;
                    break;
                }
            i++;
        }while(hash[index]!=-1 && i<m);
        if(flag==0)
            fprintf(fp2,"value not exist \n");
    }
    else if(coll=='b')
    {
        int i=0,index,k1=key%m,flag=0;
        do
        {

            index=(k1+(c1*i) +(c2*i*i))%m;
            if(hash[index]==key)
                {
                    hash[index]=-1;
                    flag=1;
                    break;
                }
            i++;
        }while( i<m);
        if(flag==0)
            fprintf(fp2,"value not exist \n");

    }
    else if(coll=='c')
    {
        int i=0,index,k1=key%m,k2,flag=0;
        k2=r-(key%r);
        do
        {
            index=(k1 + (i*k2))%m;
            if(hash[index]==key)
                {
                    flag=1;
                    hash[index]=-1;
                    break;
                }
            i++;
        }while(i<m);
        if(flag==0)
            fprintf(fp2,"Value doesnt exist");
    }
}
void display()
{
if(coll=='a'||coll=='b'||coll=='c')
{
for(int i=0;i<m;i++)
{
if(hash[i]!=-1)
    fprintf(fp2,"%d (%d)\n",i,hash[i]);
else
    fprintf(fp2,"%d ()\n",i);
}
}
else
    fprintf(fp2,"Wrong choice");
}
void main()
{
fp1=fopen("input.txt","r");
fp2=fopen("output.txt","w");
char ch;
int key;
fscanf(fp1,"%c",&coll);
fscanf(fp1,"%d",&m);
r=prime(m);
printf("%d ",r);
if(coll=='b')
    fscanf(fp1,"%d%d",&c1,&c2);

for(int i=0;i<m;i++)
    hash[i]=-1;
while(ch!='t')
{
    fscanf(fp1,"%c",&ch);
    if(ch=='i')
    {
        if(count<m)
        {
            fscanf(fp1,"%d",&key);
            insert(key);
            count++;
        }
    else
        fprintf(fp2,"overlimit\n");

    }
    else if(ch=='s')
    {
        fscanf(fp1,"%d",&key);
        fprintf(fp2,"%d\n",search(key));
    }
    else if(ch=='d')
    {
        fscanf(fp1,"%d",&key);
        deletion(key);
    }
    else if(ch=='p')
        display();
    else if(ch=='t')
        exit(0);

}
}
