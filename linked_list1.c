#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};
struct node *start=NULL;
void create()
{
    struct node *temp, *ptr;
    temp=(struct node *) malloc(sizeof(struct node));
    if (temp==NULL)
    {
        printf("not enough space\n");
        exit(0);
    }
    printf("enter the info: ");
    scanf("%d",&temp->info);
    temp->next=NULL;
    if(start==NULL)
    {
     start=temp;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }

    ptr->next=temp;
    }
}
void display()
{
    struct node *ptr;
    ptr=start;
    if (start==NULL)
    {
        printf("there is no linked list\n");
    }
    while(ptr!=NULL)
    {
        printf("%d ,",ptr->info);
        ptr=ptr->next;
    }

}
void insert_begin()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if (temp==NULL)
    {
        printf("there is no enough space\n");
    }
    printf("enter the value: ");
    scanf("%d",&temp->info);
    temp->next=NULL;
      if (start==NULL)
    {
        printf("there is no linked list i will make one");
        start=temp;
    }
    else
        {
    temp->next=start;
    start=temp;
        }
}
void insert_end()
{
    struct node *temp , *ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    if (temp==NULL)
    {
        printf("there is no enough space\n");
    }
    printf("enter the value: ");
    scanf("%d",&temp->info);
    temp->next=NULL;
    if (start==NULL)
    {
        start=temp;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}
void insert_pos()
{
    struct node *temp, *ptr;
    int i =0, pos;
    temp=(struct node *) malloc(sizeof(struct node));
    if (temp==NULL)
    {
        printf("there is no enough space");
        exit(0);
    }
    printf("enter the info :");
    scanf("%d",&temp->info);
    temp->next=NULL;
    printf("enter the position :");
    scanf("%d",&pos);
    if(pos==0)
    {
        temp->next=start;
        start = temp;
    }
    else{
    ptr=start;
    for(;i<pos-1;i++)
    {
          if(ptr==NULL)
        {
        printf("position not found ");
        return;
        }
          ptr=ptr->next;

    }
    temp->next = ptr->next;
    ptr->next=temp;
    }

}
void delete_begin()
{
    struct node *ptr;
    if (start==NULL)
    {
        printf("the list is empity");
        exit(0);
    }
    else
    {
         ptr=start;
         start=start->next;
         printf("the deleted element is :%d\n",ptr->info);
         free(ptr);
    }
}

void delete_end()
{
    struct node *ptr ,*temp;
    if(start==NULL)
    {
        printf("\nthere is no list");
        return;
    }
    else if(start->next==NULL)
    {
        ptr=start;
        start=NULL;
        printf("the deleted element is :%d",ptr->info);
        free(ptr);
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }

        temp->next=NULL;
        printf("the deleted element is :%d",ptr->info);
        free(ptr);

    }
}
void delete_pos()
{
    int i=0,pos;
    struct node *ptr , *temp;
    if (start==NULL)
    {
        printf("there is no linked list");
        return;
    }
    else
   {
    printf("enter the position :");
    scanf("%d",&pos);
    if(pos==0)
    {
        ptr=start;
        start=start->next;
        printf("the deleted element :%d",ptr->info);
        free(ptr);
    }
    else
    {
        ptr=start;
        for(;i<pos;i++)
        {
            temp=ptr;
            ptr=ptr->next;
            if (ptr==NULL)
            {
                printf("position not found");
                return;
            }
        }
        temp->next=ptr->next;
        printf("the deleted element :%d",ptr->info);
        free(ptr);

    }
   }

}
