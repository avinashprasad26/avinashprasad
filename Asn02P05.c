#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
    int data;
    struct node* link;
};
typedef struct node* NODE;
NODE createLL(int N,int Ltype)
{
    if(N==0)
    {
        printf("No Node is Created.\n");
        exit(0);
    }
    if(Ltype==0)
    {
        NODE ptr,temp,ptr1;
        NODE head = NULL;
        ptr=(NODE)malloc(sizeof(struct node));
        if(ptr==NULL)
        {
            printf("No Memory Allocated \n");
            exit(0);
        }
        else
        {
            printf("Input data for node : \n");
            scanf("%d",&ptr->data);
            ptr->link=NULL;
            head=ptr;
            temp=ptr;
            while(N!=1)
            {
                ptr1=(NODE)malloc(sizeof(struct node));
                if(ptr1==NULL)
                {
                    printf("No Memory Allocated \n");
                    exit(0);
                }
                else
                {
                    scanf("%d",&ptr1->data);
                    ptr1->link=NULL;
                    temp->link=ptr1;
                    //temp=temp->link;
                    temp=ptr1;
                }
                N--;
            }
        }
        return head;
    }
    if(Ltype==1)
    {
        NODE ptr,temp,ptr1;
        NODE head = NULL;
        ptr=(NODE)malloc(sizeof(struct node));
        if(ptr==NULL)
        {
            printf("No Memory Allocated \n");
            exit(0);
        }
        else
        {
            printf("Enter data of node : \n");
            scanf("%d",&ptr->data);
            ptr->link=NULL;
            head=ptr;
            temp=ptr;
            while(N!=1)
            {
                ptr1=(NODE)malloc(sizeof(struct node));
                if(ptr1==NULL)
                {
                    printf("No Memory Allocated \n");
                    exit(0);
                }
                else
                {
                    scanf("%d",&ptr1->data);
                    ptr1->link=NULL;
                    temp->link=ptr1;
                    temp=ptr1;
                }
                N--;
            }
            temp->link=ptr;
        }
        return head;
    }
}

int main(int argc,char *argv[])
{
    int N,Ltype,flag=0;
    N= atoi(argv[1]);
    Ltype= atoi(argv[2]);
    NODE L1,L2,temp1,temp2;
    temp1=createLL(N,Ltype);
    L1=temp1;
    L2=temp1;
    temp2 =temp1;
    while(temp2!=NULL)
    {
        L1=L1->link;
        L2=L2->link;
        if(L2->link==NULL)
        {
            flag=0;
            break;
        }
        L2=L2->link;
        if(L2->link==NULL)
        {
            flag=0;
            break;
        }
        if(L1==L2)
        {
            flag=1;
            break;
        }
        temp2=temp2->link;
    }
    if(flag==1)
        printf("It Is A Circular Linked List. \n");
    else
        printf("It Is A Terminating Linked List. \n");
    return 0;
}
