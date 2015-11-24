#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node{
	int count;
	struct node* next;
}list;

struct node* new_list(struct node *p, int count)
{
	//struct node* p;
	if((p = malloc(sizeof(struct node))) != NULL){
		p->count = count;
		p->next = NULL;
	}
	else
		printf("err:new error.\n");
	return p;
}
struct node* add_list(struct node* head, int count)
{
	if(head == NULL){
		if((head = malloc(sizeof(struct node))) != NULL){
			head->count = count;
			head->next = NULL;
		
		}
		else {
			printf("add error\n");
			return NULL;
		}
	}
	else{
		head->next = add_list(head->next, count);
	}
	return head;

}

int list_free(list *head)
{
	if(head == NULL){
		return 0;
	}
	if(head->next == NULL){
		free(head);
	}
	else {
		list_free(head->next);
	}
}

struct node* insert_sort(list *head)
{
	list *first;
	list *insert;
	list *q;
	list *p;
	if(head == NULL){
		printf("err: the pointer is NULL.\n");
		return NULL;
	}

	first = head->next;
	head->next = NULL;

	while(first != NULL){
		/*insert = head;
		p = first;
		q = NULL;
		while((insert != NULL) && insert->count < p->count){
			q = insert;
			insert = insert->next;
		}*/
		for(insert = head, p = first; ((insert != NULL) && (insert->count < p->count)); q = insert, insert = insert->next);

		first = first->next;

		if(insert == head){
			head = p;
		}
		else {
			q->next = p;		//列表头改变
		}
		p->next = insert;
			

	}
	return head;
}

void print_list(list *head)
{
	if(head){
		printf("%d ", head->count);
		print_list(head->next);
	}
}

int main()
{
	int list[] = {12, 11, 1, 2, 9, 10, 7, 22};
	int i;
	struct node *head = NULL;

	for(i = 0; i < 8; i++){
		head = add_list(head, list[i]);	
	}
	printf("before sort:\n");
	print_list(head);
	printf("\n");
	head = insert_sort(head);
	printf("after sort:\n");
	print_list(head);
	printf("\n");

	return 0;
	
}
