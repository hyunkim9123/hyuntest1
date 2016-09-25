/*------------------------------------------------------------------------------
* Program Name : 햄버거 가게 메뉴 관리 프로그램
* Description  : 햄버거 가게의 메뉴를 관리하는 프로그램
*----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 33
#define MAX_ACCOUNT 25000 //은행 최대 계정 값


typedef struct Bank {
	char *name;
	unsigned int amount;
} Bank;

typedef struct ListNode {
	Bank *bank;
	struct ListNode *next;
	struct ListNode *prev;
} ListNode;

ListNode *repay(ListNode *head); // 상환해서 0원이면 해당 사람 삭제
ListNode *loan(ListNode *head); //빌릴수 있는 계좌중에 제일 작은 돈으로 대출해준다.
ListNode *merge_bank(ListNode *head); //빌리려는 돈보다 큰 은행 없으면 모든 은행 계좌 합친다.

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



// Desc : 연결 리스트에서 메뉴의 이름을 기준으로 노드를 검색
// Param : head - 리스트의 헤드 포인터
//         name - 리스트에서 찾을 메뉴의 이름
// Return : 찾은 노드의 포인터(찾지 못할 경우 NULL)
ListNode *search_in_list(ListNode *head, char *name)
{
	ListNode *iter = head;

	// TODO : 여기에 코드를 작성하시오

	while(iter != NULL)
	{
		if(!strcmp(iter->bank->name, name))
			return iter;
		iter = iter->next;
	}

	return NULL;
}


// Desc : 연결 리스트에 새로운 노드를 현재 연결 리스트의 가장 뒤에 추가
// Param : head - 연결 리스트의 헤드 포인터
//         new_item - 추가될 노드의 데이터
// Return : 리스트의 헤드 포인터
ListNode *add_to_list(ListNode *head, ListNode *new_item)
{
	ListNode *iter;

	new_item->next = NULL;
	new_item->prev = NULL;
	// TODO : 여기에 코드를 작성하시오
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


// Desc : 키보드로부터 새로운 메뉴에 대한 정보를 입력 받아 연결 리스트에 추가
// Param : head - 리스트의 헤드 포인터
// Return : 리스트의 헤드 포인터
ListNode *add_item(ListNode *head)
{
	char name[MAX_NAME_SIZE];
	int amount;
	ListNode *new_item, *item_in_list;

	// TODO : 여기에 코드를 작성하시오
	// 필요시, 다음 코드 조각을 사용하시오.
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


// Desc : 연결 리스트에서 메뉴를 삭제
// Param : head - 리스트의 헤드 포인터
//         item - 삭제할 노드의 포인터
//         should_free - 0 삭제할 노드의 메모리를 반환하지 않음
//                     - 1 삭제할 노드의 메모리를 반환함
// Return : 리스트의 헤드 포인터
ListNode *delete_from_list(ListNode *head, ListNode *item, int should_free)
{
	// TODO : 여기에 코드를 작성하시오

	return head;
}


// Desc : 키보드로부터 삭제할 메뉴 아이템의 이름을 입력 받아 연결 리스트에서 
//        해당 노드 삭제
// Param : head -  연결 리스트의 헤드 포인터
// Return : 리스트의 헤드 포인터
ListNode *remove_item(ListNode *head)
{
	char name[MAX_NAME_SIZE];
	ListNode *node;

	// TODO : 여기에 코드를 작성하시오
	// 필요시, 다음 코드 조각을 사용하시오.
	// printf("> Name : ");
	// printf(":: Removed!\n");
	// printf(":: Not found!\n");

	return head;
}


// Desc : 연결리스트에서 기준값이 가장 작은 노드를 찾는다
// Param : head -  리스트의 헤드 포인터
//         criteria - 1 name
//                  - 2 type
//                  - 3 price
//                  - 4 calory
// Return : 정렬기준에 가장 작은 값을 가진 노드의 포인터
ListNode *find_minimum(ListNode *head, int criteria)
{
	ListNode *iter, *minimum;

	// TODO : 여기에 코드를 작성하시오

	return minimum;
}


// Desc : 키보드로부터 정렬 기준을 입력받아 리스트를 정렬
// Param : head -  리스트의 헤드 포인터
// Return : 정렬된 리스트의 헤드 포인터
ListNode *sort_all_item(ListNode *head)
{
	int crit;
	ListNode *temp_head;

	// TODO : 여기에 코드를 작성하시오
	// 필요시, 다음 코드 조각을 사용하시오.
	// printf("Sort criteria(1=name, 2=type, 3=price, 4=calory) : ");
	// ListNode *find_minimum(ListNode *head, int criteria);
	// ListNode *add_to_list(ListNode *head, ListNode *new_item);
	// ListNode *delete_from_list(ListNode *head, ListNode *item, int should_free);
	
	return head;
}

/*
 * 존재하지 않는 사람은 error 처리..
 * 이미 존재하는 사람 계좌면 amount 차감한다.
 * 상환해서 0원이면 해당 사람 삭제
 */
ListNode *repay(ListNode *head)
{
	return head;

}

/*
 * 이름이 null 이면 은행 계좌, 아니면 사람 계좌
 * 이미 존재하는 사람 계좌면 입력된 amount만큼 증가 시킨다.
 * 빌릴수 있는 계좌중에 제일 작은 돈으로 대출해준다.
 * 은행 계좌 부족하면 즉시 합친 후 대출수행.
 */
ListNode *loan(ListNode *head)
{
	return head;

}
ListNode *merge_bank(ListNode *head) //빌리려는 돈보다 큰 은행 없으면 모든 은행 계좌 합친다.
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


// Desc : 사용자 선택 메뉴를 출력
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


// Desc : 키보드로부터 사용자 선택 메뉴에 대한 입력을 받음
// Param : None
// Return : 입력 받은 메뉴 선택지 (0~4)
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


// Desc : 모든 메뉴 아이템을 출력
// Param : head -  리스트의 헤드 포인터
void print_all_item(ListNode *head)
{
	int i;
	ListNode *it;

	for (it = head, i = 0; it != NULL; it = it->next, i++)
	{
		//print 사람 혹은 은행 계좌
		printf("[%d] ", i + 1);
		if(it->bank->name != NULL)
			printf("%s ", it->bank->name);
		printf(" %d \n",it->bank->amount);
	}
}


// Desc : 연결 리스트를 전체 삭제
// Param : head -  리스트의 헤드 포인터
void delete_list(ListNode *head)
{
	while (head != NULL)
		head = delete_from_list(head, head, 1);
}
