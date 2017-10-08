#include <stdio.h>
#include <stdlib.h>
// structure definitions
// structure of a linked list node. It contains an integer element
struct node
{
    int element;
    struct node * next;
};
typedef struct node Node;

/* structure of a linked list.
in the list and also a pointer link to the first node of the list. */
 
// function declarations
// Node *insertFirst (Node * head, int ele);  /* inserts a given element at the beginning of the list */
// Node* deleteFirst(Node * head);  /* deletes the first element of the list and returns pointer to the deleted node. */
// void traverse (Node * head);   prints all the elements in the list 
// Node * deleteEnd(Node * head, int ele);  /*deletes the node in the list that contains the element = ele & if the element is not found it returns an error message saying not found*/
// Node * insertEnd(Node* head,int data);
//void insertNodeAtPos(Node* head,int data, int pos);

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
    printf("-1: to exit\n");
    printf("-------------------\n");


    printf("Give your choice\n");

    scanf("%d",&choice);
    return choice;   
}

int main()
{

    //root=(struct node *)malloc(sizeof(struct node));
    Node *head=NULL;
    //root->left=NULL;
    //root->right=NULL;
    int N=0,p=0;
    int choice=0;
    
    choice=getChoice(choice);   
    while(choice!=-1)
    {
        if(choice==0)
        {
            printf("Enter the element to be added\n");
            scanf("%d",&N);
            head=insertFirst(head,N);
            traverse(head); 
        }
        if(choice==1)
        {
         /* declare and allocate a new int pointer */
            printf("Enter the element to be added\n");
            scanf("%d",&N);
            head=insertEnd(head,N);
            traverse(head);
            //printf("asd\n");
        }
        if(choice==2)
        { 
            printf("Deleting from head\n");
            //traverse(head);
            head=deleteFirst(head);
            traverse(head);
        }
        if(choice==3)
        {
            printf("Deleting from the tail\n");
            head=deleteEnd(head);
            traverse(head);
        }
        if(choice==4)
        {
            traverse(head);
        }
        if(choice==5)
        {
            printf("Enter the element to be added\n");
            scanf("%d",&N);
            printf("Enter the position\n");
            scanf("%d",&p);
            head=insertNodeAtPos(head,N,p);
            traverse(head);
        }
        choice=getChoice(choice);
    }
    return 0;
}