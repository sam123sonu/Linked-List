#include<stdio.h>
#include<malloc.h>
struct node
{
   int info;
    struct node *next;
};
struct node *start=NULL;
struct node* createnode()
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    return n;
};
void insert()
{
    struct node *temp;
    temp=createnode();
    printf("enter the number");
    scanf("%d",&temp->info);
    temp->next=NULL;
    if(start==NULL)
        start=temp;
    else
    {
        struct node *t;
        t=start;
        while(t->next!=NULL)
            t=t->next;
            t->next=temp;

    }
}
void deletenode()
{
    struct node *r;
    if(start==NULL)
        printf("list is empty");
    else
    {
        r=start;
        start=start->next;
        free(r);
    }
}
void display()
{
    struct node *t;
    t=start;
    while(t!=NULL)
     {printf("%d\n",t->info);
      t=t->next;
     }
}
void swap()
{ int n,r;
 struct node *t;
    printf("enter the no u want to swap:");
    scanf("%d",&n);
    t=start;
    while(t!=NULL)
    { if(t->info==n)
       {
           r=start->info;
           start->info=t->info;
           t->info=r;
       }
       t=t->next;
    }
}
void max()
{

    struct node *t,*r;
    t=start;
    r=createnode();
    r->info=start->info;
    while(t!=NULL)
    {
        if(t->info >= r->info)
            r->info=t->info;
        t=t->next;
    }
    printf("max element in the list is:%d",r->info);
}
void sort()
{ int r,op;
    struct node *t;
    struct node *s=NULL;
do{
    op=0;
    t=start;
    while(t->next!=s)
            {
                if(t->info >= (t->next)->info)
                   {r=t->info;
                    t->info=(t->next)->info;
                    (t->next)->info=r;
                    op=1;
                   }
                   t=t->next;
            }
                   s=t;
    } while(op);

}

int main()
{int i,c;
    do{printf("1:insert\n2:delete\n3:display\n4:swap\n5:max\n6:sort");
    scanf("%d",&i);
    switch(i)
    {
        case 1:insert();
            break;
        case 2:deletenode();
            break;
        case 3:display();
            break;
        case 4:swap();
            break;
        case 5:max();
           break;
        case 6:sort();
           break;
    }
    printf("\nu want operate again:");
    scanf("%d",&c);
}while(c);
return 0;
}
