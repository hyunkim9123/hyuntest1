#ifndef __LIST_H__
#define __LIST_H__

// Account structure
typedef struct {
  char* name;
  int account;
} Account;

// Node for linked list 
typedef struct node {
  Account *data;     
  struct node *next;
  struct node *prev;
} Node;

Node *find_node(Node *head, char *name);
void remove_node(Node* head, Node *tp);
Node* new_node(Account* ep);
void insert_node(Node* head, Node *tp);

void init_list(Node **head);
void sort_list(Node *head);
void deallocate_list(Node *head);

#endif
