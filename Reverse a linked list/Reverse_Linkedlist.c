// C program to reverse a linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int Val;
    struct Node* next;
}Node;

/* Function to reverse the linked list */
Node * reverse(Node ** root)
{
    Node* prev = NULL;
    Node* current = *root;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *root = prev; 
}

/* Function to push a node */
void push( Node** root, int val)
{
    Node* new_node = ( Node*)malloc(sizeof( Node));
    new_node->Val = val;
    new_node->next = (*root);
    (*root) = new_node;
}

/* Function to print linked list */
void printList( Node* root)
{
    Node* temp = root;
    while (temp != NULL) {
        printf("%d  ", temp->Val);
        temp = temp->next;
    }
}

int main()
{
    /* Start with the empty list */
    Node* root = NULL;
  
    push(&root, 11);
    push(&root, 22);
    push(&root, 33);
    push(&root, 44);
  
    printf("Given linked list\n");
    printList(root);
    reverse(&root);
    printf("\nReversed Linked list \n");
    printList(root);
    return 0;
}