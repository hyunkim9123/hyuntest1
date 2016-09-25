//
// 2. Bank Management System
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

//Bank`s name = null
//Account`s name not null

int disp_menu() ;
void print_list(Node *head);

void add_loan(Node *head);
void repay(Node *head);
void add_account(Node *head, int account);
Account* make_account(Node* head, char* name,int account);
void merge_account(Node *head);//merge account if money to lend is bigger than bank`s account money
int main(void)
{
  Node *head = NULL;
  int sel;

  init_list(&head);

  add_account(head, 50000);
  print_list(head);
  while(1){
    sel=disp_menu();
    if(sel==0) break;
    switch(sel){
      case 1: add_loan(head); break;
      case 2: repay(head); break;
      case 3: print_list(head); break;
      default: break;
    }
  }
  deallocate_list(head);

  system("pause");
  return 0;
}

// Display menu
int disp_menu() 
{
  int sel;

  printf("\n===================================\n");
  printf("     Account Management System\n");
  printf("===================================\n");
  printf("1. loan\n");
  printf("2. Repay\n");
  printf("3. Print\n");
  printf("0. Exit\n");
  printf(">> Select menu : ");
  scanf("%d", &sel);
  fflush(stdin);
  return sel;
}

// Print list
void print_list(Node *head)
{
  Node *tp=head->next;
  int cnt=0;

  printf("\n");
  while(tp != NULL){
    printf("[%d] %22s %8d\n", ++cnt,  tp->data->name, tp->data->account);
    tp=tp->next;
  }
}

// Desc : Adding a new Account to list
// Params : head - The head node of list
// Return : None
void add_account(Node *head, int account)
{
  Node* node;
  Account* ep;

  ep = make_account(head, NULL, account);

  node = new_node(ep);
  insert_node(head, node);

  printf(":: Success!\n");
}

// Desc : repay money to bank. if person not exists, pop up error. If repay all the money in the account, remove the node.
// Params : head - The head node of list
// Return : None
void repay(Node *head)
{
  Node* node;
  char name[32];
  Account* ep;

  printf(":: Success!\n");
}
// Desc : loan money from bank. if exists, just add the money to the account. If money is bigger than all the bank`s, then merge all bank`s account.  
// Params : head - The head node of list
// Return : None
void add_loan(Node* head)
{
  char name[32];
  int account;
  Account* ep = NULL;
  Node* node;

  printf("\n");
  printf("> Account Name : ");
  scanf("%s", name);
  fflush(stdin);

  printf("> amount to loan : ");
  scanf("%d", &account);
  fflush(stdin);
  ep = make_account(head, name, account);
  if(ep == NULL)
  {
    printf(":: The Account name already exists!\n\n");
    return;
  }

  node = new_node(ep);
  insert_node(head, node);
}
Account* make_account(Node* head, char* name, int account)
{
  Account* new_account = NULL;

  if(name != NULL && find_node(head, name) != NULL)
  {
    return NULL;
  }

  new_account = (Account*)malloc(sizeof(Account));
  if(name == NULL)
    new_account->name = NULL;
  else
  {
    new_account->name = (char*)malloc(strlen(name)+1);
    strcpy(new_account->name, name);
  }
  new_account->account = account;

  return new_account;
}

