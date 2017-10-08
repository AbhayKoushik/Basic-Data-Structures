#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void traverse(Node * head)
{
    if(head==NULL) printf("List is empty, head at NULL\n");
    printf("\nPrinting the list\n");
    Node *ptr = head->next;
    while(ptr != NULL)
    {
        printf("%d\t", ptr->element);
        ptr = ptr->next;
    }
    printf("\n");
}

Node* insertFirst(Node *head,int ele)
{
    if(head==NULL)
    {
        head=(Node *)malloc(sizeof(struct node));
    }
    //printf("\ninserting in %d\n",ele);
    Node *link=( Node *)malloc(sizeof(struct node));
    link->element=ele;
    link->next=head->next;
    head->next=link;
    return head;
}

Node* insertEnd(Node* head,int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        head=insertFirst(head,data);
    }
    else
    {
        struct node *ptr=head;
        /*
     * Traverse to the n-1 position*/ 
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
            if(ptr == NULL)
            {
                printf("\npointer is at null\n");
                break;
            }
        }

        if(ptr!= NULL)
        {
            newNode->element = data; //Links the data part
            newNode->next = ptr->next;
        /* Links the address part of new node */ 
        /* Links the address part of n-1 node */  
            ptr->next = newNode;
            //printf("\nDATA INSERTED SUCCESSFULLY at %d\n",pos);
            //head->element++;
        }
        else
        {
            printf("\nUnable to insert at this position\n");
        }
    }
    return head;
}
 
Node* deleteFirst(Node * head)
{
    struct node *toDelete;
    if((head == NULL)||(head->next==NULL))
    {

        printf("Cannot delete\n");
    }
    else
    {
        
        //traverse(head);
            toDelete = head->next;
            head->next = head->next->next;
            printf("%d\n", toDelete->element);
            /* Clears the memory occupied by first node*/
            free(toDelete);
    
        //printf("\nSUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
        //head->element--;
        // printf("Now the list has %d\n",count);
    }
    return head;

}

Node* deleteEnd(Node * head)
{
    struct node* toDelete;
    if((head==NULL)||(head->next==NULL))
    {
        printf("Cannot delete\n");
    }
    else
    {
        struct node *ptr = head;
            while(ptr->next->next!= NULL)
            {
                 ptr=ptr->next;
            }


            toDelete=ptr->next;
            ptr->next=NULL;
            printf("%d\n", toDelete->element);
            /* Clears the memory occupied by first node*/
            
            free(toDelete);
        }
        // printf(" ");
    return head;
}

Node *insertNodeAtPos(Node* head,int data,int pos)
{
    Node* temp,*new,*prev = NULL;
    int i=1;
    new = (Node *)malloc(sizeof(struct node));
    new->element = data;
    if(head == NULL && pos==1)
    {
        printf("Here added at first");
        head=insertFirst(head,data);
        return head;
    }
    temp = head;
    while(temp != NULL && i<=pos)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }
    if(temp == NULL)
    {
        prev->next = new;
        new->next = NULL;
    }
    else
    {
        prev->next = new;
        new->next= temp;
    }
    return head;
}

Node* formACycle(Node * head,int pos)
{
    Node *p=head;
    Node *c=NULL;
    int flag=0;
    int pCount=1;
    int t=0;
    while(p->next!=NULL)
    {
        pCount++;
        if(pCount==pos)
        {
            // printf("%d %d choi pos\n",choice, pos );
            flag=1;
            c=p;
            t=pCount;
        }
        p=p->next;
    }
    if(flag==1)
    {
        p->next=c;
    }
    printf("Cycle is formed from the tail node to node %d\n",t);
    // printf("%d is tot",t);
    // printf("%d is pos\n",finPos);
    return p;
}

void hasCycle(Node *head) 
{
    if(head!=NULL && head->next!=NULL)
    {
        
        int n=0;
        int flag=0;
        Node *tor=head;
        Node *rab=head->next;
        int t=0;
        // if(rab==tor)
        while(rab->next!=NULL && rab->next->next!=NULL)
        {
             rab=rab->next->next;
             tor=tor->next;
             
             n++;
             
             if(rab==tor)
             {
                flag=1;
                break;
             }
        
        }
        // printf("flag is %d\n",flag );
        //if(n==1)
        //     return 1;
        if(flag==1)
        {    printf("Cycle is present\n");   }

        else
        {    printf("Cycle is not present\n");   }
    }
}


int getChoice(int choice)
{
    printf("-------------------\n");
    printf("Here are the choices:\n");
    printf("0: insert at the head\n");
    printf("1: insert at the tail\n");
    printf("2: delete from the head\n");
    printf("3: delete from the tail\n");
    printf("4: just print the list\n");
    printf("5: Insert at node you prefer\n");
    printf("6: Form a cycle\n");
    printf("7: Check for the existance of cycle\n");
    printf("-1: to exit\n");
    printf("-------------------\n");


    printf("Give your choice\n");

    scanf("%d",&choice);
    return choice;   
}
