#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include<string.h>
#define SIZE 20
using namespace std;

struct Node {
	int data;
	int key;
	Node* next;
};

struct Node *hashArray[SIZE];
int hashCode(int key)
{
	return key % SIZE;
}

void linkedlist(int k,int d)
{
	struct Node* temp = hashArray[k];

	while (temp->next!= NULL)
	{
		temp = temp->next;
	}
	temp->next = new Node;
	temp->next->data = d;
	temp->next->key = k;
	temp->next->next = NULL;


}

void insert(int k, int d)
{
	int flag = 0;
	int index = hashCode(k);
	if (hashArray[index] == NULL)
	{
		hashArray[index] = new Node;
		hashArray[index]->data = d;
		hashArray[index]->key = k;
		hashArray[index]->next = NULL;
	}
	else
	{
		linkedlist(index, d);
	}
}

void sortedList(int d, int k)
{

}

void display()
{

	for (int i = 0; i < SIZE; i++)
	{
		if (hashArray[i] != NULL)
		{
			if (hashArray[i]->next != NULL)
			{
				struct Node* temp = hashArray[i];
				printf("[%d]", hashArray[i]->key);
				while (temp->next != NULL)
				{
					printf(" %d->", temp->data);
					temp = temp->next;

				}

				printf("%d\n", temp->data);
			}
			else

				printf("[%d] %d\n", hashArray[i]->key,hashArray[i]->data);
		}

	}
}

int main()
{
	/*for (int i = 0; i < SIZE; i++)
	{
		hashArray[i] = new Node;
	}*/
	insert(1, 50);
	insert(1, 20);
	insert(1, 30);
	insert(1, 40);
	insert(2, 70);
	insert(1, 80);
	insert(4, 25);
	insert(3, 50);
	insert(12, 44);
	insert(14, 32);
	insert(17, 11);
	insert(13, 78);
	insert(37, 97);
	display();
	return 0;
}
