/*------------------------------------------------------------------------------
* Program Name : �ܹ��� ���� �޴� ���� ���α׷�
* Description  : �ܹ��� ������ �޴��� �����ϴ� ���α׷�
*----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 33
#define MAX_ACCOUNT 25000 //���� �ִ� ���� ��


typedef struct Bank {
	char *name;
	unsigned int amount;
} Bank;

typedef struct ListNode {
	Bank *bank;
	struct ListNode *next;
	struct ListNode *prev;
} ListNode;

ListNode *repay(ListNode *head); // ��ȯ�ؼ� 0���̸� �ش� ��� ����
ListNode *loan(ListNode *head); //������ �ִ� �����߿� ���� ���� ������ �������ش�.
ListNode *merge_bank(ListNode *head); //�������� ������ ū ���� ������ ��� ���� ���� ��ģ��.

ListNode *search_in_list(ListNode *head, char *name);
ListNode *add_to_list(ListNode *head, ListNode *new_item);
ListNode *add_item(ListNode *head);
ListNode *delete_from_list(ListNode *head, ListNode *item, int should_free);
ListNode *remove_item(ListNode *head);
ListNode *find_minimum(ListNode *head, int criteria);
ListNode *sort_all_item(ListNode *head);
void print_menu(void);
int input_menu(void);
void print_all_item(ListNode *head);
void delete_list(ListNode *head);



// Desc : ���� ����Ʈ���� �޴��� �̸��� �������� ��带 �˻�
// Param : head - ����Ʈ�� ��� ������
//         name - ����Ʈ���� ã�� �޴��� �̸�
// Return : ã�� ����� ������(ã�� ���� ��� NULL)
ListNode *search_in_list(ListNode *head, char *name)
{
	ListNode *iter = head;

	// TODO : ���⿡ �ڵ带 �ۼ��Ͻÿ�

	while(iter != NULL)
	{
		if(!strcmp(iter->bank->name, name))
			return iter;
		iter = iter->next;
	}

	return NULL;
}


// Desc : ���� ����Ʈ�� ���ο� ��带 ���� ���� ����Ʈ�� ���� �ڿ� �߰�
// Param : head - ���� ����Ʈ�� ��� ������
//         new_item - �߰��� ����� ������
// Return : ����Ʈ�� ��� ������
ListNode *add_to_list(ListNode *head, ListNode *new_item)
{
	ListNode *iter;

	new_item->next = NULL;
	new_item->prev = NULL;
	// TODO : ���⿡ �ڵ带 �ۼ��Ͻÿ�
	if(head == NULL)
	{
		head = new_item;
	}
	else
	{
		iter = head;
		if(new_item->bank->name != NULL && search_in_list(head, new_item->bank->name) != NULL)
		{
			printf(":: Already Exists!. NOT Updated!\n");
		}
		else
		{
			while(iter->next != NULL)
			{
				iter = iter->next;
			}
			iter->next = new_item;
			new_item->prev = iter;
		}
	}

	return head;
}


// Desc : Ű����κ��� ���ο� �޴��� ���� ������ �Է� �޾� ���� ����Ʈ�� �߰�
// Param : head - ����Ʈ�� ��� ������
// Return : ����Ʈ�� ��� ������
ListNode *add_item(ListNode *head)
{
	char name[MAX_NAME_SIZE];
	int amount;
	ListNode *new_item, *item_in_list;

	// TODO : ���⿡ �ڵ带 �ۼ��Ͻÿ�
	// �ʿ��, ���� �ڵ� ������ ����Ͻÿ�.
	memset(name, 0x00, MAX_NAME_SIZE);

	printf("> Name : ");
	scanf("%s", name);
	fflush(stdin);
	printf("> Amount : ");
	scanf("%d", &amount);
	fflush(stdin);
	new_item = (ListNode*) malloc(sizeof(ListNode));
	new_item->bank->amount = amount;
	new_item->bank->name = (char*) malloc(strlen(name)+1);
	strcpy(new_item->bank->name, name);

	if(head == NULL)
	{
		head = new_item;
	}
	else
	{
		item_in_list = head;
		if(search_in_list(head, name) != NULL)
		{
			printf(":: Already Exists!. NOT Updated!\n");
		}
		else
		{
			while(item_in_list->next != NULL)
			{
				item_in_list = item_in_list->next;
			}
			item_in_list->next = new_item;
			new_item->prev = item_in_list;
		}
	}
	printf(":: Updated!\n");
	// printf(":: Added!\n");

	
	return head;
}


// Desc : ���� ����Ʈ���� �޴��� ����
// Param : head - ����Ʈ�� ��� ������
//         item - ������ ����� ������
//         should_free - 0 ������ ����� �޸𸮸� ��ȯ���� ����
//                     - 1 ������ ����� �޸𸮸� ��ȯ��
// Return : ����Ʈ�� ��� ������
ListNode *delete_from_list(ListNode *head, ListNode *item, int should_free)
{
	// TODO : ���⿡ �ڵ带 �ۼ��Ͻÿ�

	return head;
}


// Desc : Ű����κ��� ������ �޴� �������� �̸��� �Է� �޾� ���� ����Ʈ���� 
//        �ش� ��� ����
// Param : head -  ���� ����Ʈ�� ��� ������
// Return : ����Ʈ�� ��� ������
ListNode *remove_item(ListNode *head)
{
	char name[MAX_NAME_SIZE];
	ListNode *node;

	// TODO : ���⿡ �ڵ带 �ۼ��Ͻÿ�
	// �ʿ��, ���� �ڵ� ������ ����Ͻÿ�.
	// printf("> Name : ");
	// printf(":: Removed!\n");
	// printf(":: Not found!\n");

	return head;
}


// Desc : ���Ḯ��Ʈ���� ���ذ��� ���� ���� ��带 ã�´�
// Param : head -  ����Ʈ�� ��� ������
//         criteria - 1 name
//                  - 2 type
//                  - 3 price
//                  - 4 calory
// Return : ���ı��ؿ� ���� ���� ���� ���� ����� ������
ListNode *find_minimum(ListNode *head, int criteria)
{
	ListNode *iter, *minimum;

	// TODO : ���⿡ �ڵ带 �ۼ��Ͻÿ�

	return minimum;
}


// Desc : Ű����κ��� ���� ������ �Է¹޾� ����Ʈ�� ����
// Param : head -  ����Ʈ�� ��� ������
// Return : ���ĵ� ����Ʈ�� ��� ������
ListNode *sort_all_item(ListNode *head)
{
	int crit;
	ListNode *temp_head;

	// TODO : ���⿡ �ڵ带 �ۼ��Ͻÿ�
	// �ʿ��, ���� �ڵ� ������ ����Ͻÿ�.
	// printf("Sort criteria(1=name, 2=type, 3=price, 4=calory) : ");
	// ListNode *find_minimum(ListNode *head, int criteria);
	// ListNode *add_to_list(ListNode *head, ListNode *new_item);
	// ListNode *delete_from_list(ListNode *head, ListNode *item, int should_free);
	
	return head;
}

/*
 * �������� �ʴ� ����� error ó��..
 * �̹� �����ϴ� ��� ���¸� amount �����Ѵ�.
 * ��ȯ�ؼ� 0���̸� �ش� ��� ����
 */
ListNode *repay(ListNode *head)
{
	return head;

}

/*
 * �̸��� null �̸� ���� ����, �ƴϸ� ��� ����
 * �̹� �����ϴ� ��� ���¸� �Էµ� amount��ŭ ���� ��Ų��.
 * ������ �ִ� �����߿� ���� ���� ������ �������ش�.
 * ���� ���� �����ϸ� ��� ��ģ �� �������.
 */
ListNode *loan(ListNode *head)
{
	return head;

}
ListNode *merge_bank(ListNode *head) //�������� ������ ū ���� ������ ��� ���� ���� ��ģ��.
{
	return head;

}

int main()
{
	int menu;
	ListNode *head=NULL;
	setvbuf(stdout, NULL, _IONBF, 0);
	ListNode* init_bank = (ListNode*) malloc(sizeof(ListNode));
	init_bank->bank = (Bank*) malloc(sizeof(Bank));
	init_bank->bank->amount = 50000;
	init_bank->bank->name = NULL;
	head = add_to_list(head, init_bank);
	printf("============= Initial Bank =============== \n");
	print_all_item(head);
	do
	{
		print_menu();
		menu = input_menu();

		switch (menu)
		{
		case 1:
			head = loan(head);
			break;
		case 2:
			head = repay(head);
			break;
		case 3:
			print_all_item(head);
			break;
		case 0:
			break;
		default:
			break;
		}
		printf("\n");
	} while (menu != 0);

	//delete_list(head);
  free(head->bank);
	free(head);
	head = NULL;

	printf("Bye\n");

	return 0;
}


// Desc : ����� ���� �޴��� ���
// Param : None
void print_menu(void)
{
	printf("========================================\n");
	printf(" Bank Management System \n");
	printf("========================================\n");
	printf("1. Loan\n");
	printf("2. Repay\n");
	printf("3. Print Bank\n");
	printf("0. Exit\n");
}


// Desc : Ű����κ��� ����� ���� �޴��� ���� �Է��� ����
// Param : None
// Return : �Է� ���� �޴� ������ (0~4)
int input_menu(void)
{
	int value;

	while (1) {
		printf(">> Select menu : ");
		fflush(stdin);
		scanf("%d", &value);
		if (value < 0 || value > 3) {
			printf("Invalid menu item!\n");
			continue;
		}
		else {
			break;
		}
	}

	return value;
}


// Desc : ��� �޴� �������� ���
// Param : head -  ����Ʈ�� ��� ������
void print_all_item(ListNode *head)
{
	int i;
	ListNode *it;

	for (it = head, i = 0; it != NULL; it = it->next, i++)
	{
		//print ��� Ȥ�� ���� ����
		printf("[%d] ", i + 1);
		if(it->bank->name != NULL)
			printf("%s ", it->bank->name);
		printf(" %d \n",it->bank->amount);
	}
}


// Desc : ���� ����Ʈ�� ��ü ����
// Param : head -  ����Ʈ�� ��� ������
void delete_list(ListNode *head)
{
	while (head != NULL)
		head = delete_from_list(head, head, 1);
}
