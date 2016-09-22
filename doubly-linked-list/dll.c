//
// 2. Employee Management System
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

//Bank`s name = null
//employee`s name not null

int disp_menu() ;
void print_list(Node *head);

void loan(Node *head);
void repay(Node *head);
void add_employee(Node *head);
Employee* make_employee(Node* head);
void retrieve_employee(Node *head);
void remove_employee(Node *head);
void merge_account(Node *head);//merge account if money to lend is bigger than bank`s account money
int main(void)
{
  Node *head = NULL;
  int sel;

  init_list(&head);

  while(1){
    sel=disp_menu();
    if(sel==0) break;
    switch(sel){
      case 1: loan(head); break;
      case 2: repay(head); break;
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
  printf("     Employee Management System\n");
  printf("===================================\n");
  printf("1. loan\n");
  printf("2. Repay\n");
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
    printf("[%d] %8s %22s %8d\n", ++cnt, tp->data->emp_no, tp->data->name, tp->data->account);
    tp=tp->next;
  }
}

// Desc : Adding a new employee to list
// Params : head - The head node of list
// Return : None
void add_bank(Node *head)
{
  Node* node;
  Employee* ep;
  char name[32];

  ep = make_employee(head);
  if(ep == NULL)
  {
    printf(":: The employee number already exists!\n\n");
    return;
  }

  node = new_node(ep);
  insert_node(head, node);

  printf(":: Success!\n");
}
// Desc : loan money from bank. if exists, just add the money to the account. If money is bigger than all the bank`s, then merge all bank`s account.  
// Params : head - The head node of list
// Return : None
void loan(Node *head)
{
  Node* node;
  Employee* ep;
  char name[32];

  ep = make_employee(head);
  if(ep == NULL)
  {
    printf(":: The employee number already exists!\n\n");
    return;
  }

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
  Employee* ep;
  ep = make_employee(head);
  if(ep == NULL)
  {
    printf(":: The employee number already exists!\n\n");
    return;
  }

  node = new_node(ep);
  insert_node(head, node);

  printf(":: Success!\n");
}
Employee* add_loan(Node* head)
{
  char id[7];
  char name[32];
  int account;
  Employee* new_emp = NULL;

  printf("\n");
  printf("> Employee Name : ");
  gets(name);

  if(find_node(head, id))
  {
    return NULL;
  }

  printf("> Name : ");
  gets(name);
  printf("> account : ");
  scanf("%d", &account);

  new_emp = (Employee*)malloc(sizeof(Employee));
  new_emp->name = (char*)malloc(strlen(name)+1);
  strcpy(new_emp->emp_no, id);
  strcpy(new_emp->name, name);
  new_emp->account = account;

  return new_emp;
}
Employee* make_bank(Node* head, int account)
{
  char id[7];
  char name[32];
  int account;
  Employee* new_emp = NULL;

  new_emp = (Employee*)malloc(sizeof(Employee));
  new_emp->name = (char*)malloc(strlen(name)+1);
  strcpy(new_emp->emp_no, id);
  strcpy(new_emp->name, name);
  new_emp->account = account;

  return new_emp;
}
// Desc : Make Employee data form user input
// Params : head - The head node of list
// Return : Employee(Dynamically allocated)
Employee* make_employee(Node* head)
{
  char id[7];
  char name[32];
  int account;
  Employee* new_emp = NULL;

  printf("\n");
  printf("> Employee Number : ");
  gets(id);

  if(find_node(head, id))
  {
    return NULL;
  }

  printf("> Name : ");
  gets(name);
  printf("> account : ");
  scanf("%d", &account);

  new_emp = (Employee*)malloc(sizeof(Employee));
  new_emp->name = (char*)malloc(strlen(name)+1);
  strcpy(new_emp->emp_no, id);
  strcpy(new_emp->name, name);
  new_emp->account = account;

  return new_emp;
}

// Desc : Print all the employee data
// Params : head - The head node of list
// Return : None
void retrieve_employee(Node *head) 
{
  if(head->next == NULL)
  {
    printf("\n:: There is no employee!\n");
    return;
  }
  sort_list(head);
  print_list(head);
}

// Desc : Remove a employee from list
// Params : head - The head node of list
// Return : None
void remove_employee(Node *head) 
{
  Node* node;
  char emp_no[7];

  if(head->next == NULL)
  {
    printf("\n:: There is no employee!\n");
    return;
  }

  sort_list(head);
  print_list(head); 

  printf("\n> Employee Number : ");
  gets(emp_no);
  fflush(stdin);

  node = find_node(head, emp_no);
  if(node)
  {
    remove_node(head, node);
    printf(":: Success!\n");
  }else{
    printf(":: The employee number does not exist!\n");   
  }
}
