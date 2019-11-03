#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

struct Node
{
	int data;
	struct Node* next;
};
struct Node* head;
struct Node* tail;
struct Node* insert(int element)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = element;
	temp->next = head;
	head = temp;
	return head;
}
struct Node* insert_to_tail(int element)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	if (head == NULL)
	{
		temp->data = element;
		temp->next = tail;
		head = temp;
	}
	else
	{
		temp->data = element;
		temp->next = NULL;
		tail->next = temp;
		tail = tail->next;
	}


	return tail;

}

void print()
{
	struct Node* temp = head;
	while (temp != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL \n");

}
struct Node* reverse(struct Node* temp)
{
	struct Node* x = (struct Node*)malloc(sizeof(struct Node));
	if (temp->next != NULL)
		x = reverse(temp->next);
	else
		return temp;
	x->next = temp;
	if (head == temp)
	{
		head = tail;
		tail = temp;
		tail->next = NULL;

	}
	return temp;
}


void main()
{
	int size, element;
	head = NULL;
	tail = head;
	printf("how many nodes to insert ? ");
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		printf("enter element %d : ", i + 1);
		scanf("%d", &element);
		if (head == NULL)
		{
			tail = NULL;
			insert_to_tail(element);
		}
		else
		{
			struct Node* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			tail = temp;
			insert_to_tail(element);

		}

	}
	//printf("%d", tail->data);
	print();
	reverse(head);
	print();


	return 0;
}