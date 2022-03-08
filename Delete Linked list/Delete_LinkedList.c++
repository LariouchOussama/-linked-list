#include <bits/stdc++.h>
using namespace std;
 
typedef struct Node {
    int data;
    struct Node* next;
}Node;
 
/* Function to delete the entire linked list */
void deleteList(Node** root)
{
 
    Node* current = *root;
    Node* next = NULL;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *root = NULL;
}

int isempty(Node* root)
{
    if(root==NULL)
        return 1;
    else
        return 0;
}

void push(Node** root, int Val)
{
    Node* new_node = new Node();
    new_node->data = Val;
    new_node->next = (*root);
    (*root) = new_node;
}
int main()
{
    Node* root = NULL; 
    push(&root, 1);
    push(&root, 4);
    push(&root, 1);
    push(&root, 12);
    push(&root, 1);
 
    cout << "Deleting linked list";
    deleteList(&root);
    if( isempty(root) )
        cout << "\nLinked list deleted";
}