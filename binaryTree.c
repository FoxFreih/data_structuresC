#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

struct node
{
	int data;
	struct node* right;
	struct node* left;
};

void insert(int key,struct node *leaf)
{
	if (leaf == NULL)
	{
		struct node *leaf = (struct node *)malloc(sizeof(struct node));
		leaf->data = key;
		leaf->left = NULL;
		leaf->right = NULL;
	}
	else
	{
		if (key < leaf->data)
		{
			insert(key, leaf->left);
		}
		else if (key >= leaf->data)
		{
			insert(key, leaf->right);
		}
	}
}

void main()
{
	struct node* leaf = NULL;
	insert(5, leaf);
	insert(8, leaf);
	insert(10, leaf);
	insert(6, leaf);
	insert(14, leaf);
	insert(5, leaf);
	insert(8, leaf);
	insert(11, leaf);
	insert(18, leaf);
}

		