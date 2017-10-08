#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
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
        if(choice==6)
        {
            printf("Enter the position to be cycled back to\n");
            scanf("%d",&p);
            head=formACycle(head,p);
            //  traverse(head);   //Do not traverse, its a cycle now
        }
        if(choice==7)
        {
            hasCycle(head);
        }
        choice=getChoice(choice);
    }
    return 0;
}