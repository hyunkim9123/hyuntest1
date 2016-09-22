#include "list.h"
#include <stdlib.h>
#include <string.h>


// Desc : Initializing a linked list
// Param : head - head pointer of linked list
// Return : None
void init_list(Node **head)
{
  *head = (Node*)malloc(sizeof(Node));
  (*head)->data = 0;
  (*head)->next = NULL;
}

// Desc : Making a new node contaning the employee
// Param : ep - menu to be contained
// Return : Node dynamically allocated
Node* new_node(Employee* ep)
{
  Node *tp;

  tp=(Node *)malloc(sizeof(Node));
  tp->data = ep;
  tp->next=NULL;

  return tp;
}

// Desc : Inserting node to list
// Param : head - head pointer of linked list, tp - node to be inserted
// Return : None
void insert_node(Node* head, Node *tp)
{

  // TODO: Write code here

}

// Desc : Sorting the list
// Param : head - head pointer of linked list, tp - node to be sorted
// Return : None
void sort_list(Node *head)
{


  // TODO: Write code here


}

// Desc : Removing a node from list
// Param : head - head pointer of linked list, tp - node to be removed
// Return : None
void remove_node(Node* head, Node *tp)
{


  // TODO: Write coe here


}

// Desc : Finding the node in position of the index
// Param : head - head pointer of linked list, new_emp_no - employee number to find
// Return : Node contains new_emp_no, NULL if not found
Node *find_node(Node *head, char *new_emp_no)
{


  // TODO: Write code here


  return NULL;
}

// Desc : Deallocate all the momory of list
// Param : head - head pointer of linked list
// Return : None
void deallocate_list(Node *head)
{


  // TODO: Write code here


}
