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
Node *insertFirst (Node * head, int ele);  /* inserts a given element at the beginning of the list */
Node* insertEnd(Node* head,int data); // inserts the given element at the end of the list
Node* deleteFirst(Node * head);  /* deletes the first element of the list and returns pointer to the deleted node. */
void traverse (Node * head);   // prints all the elements in the list 
Node * deleteEnd(Node * head);  /*deletes the node from the end of the list*/
Node* formACycle(Node * head,int pos); //Forms a cycle from the tail to the specifies node
void hasCycle(Node *head); // Checks whether cycle exists
Node *insertNodeAtPos(Node* head,int data,int pos);
int getChoice(int choice); // this is to provide functionality to the driver


