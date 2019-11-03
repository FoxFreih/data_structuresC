#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include<string.h>
using namespace std;


struct Node
{
	int id;
	bool completed;
	string discription;
	Node *right;
	Node *left;
};

struct Node* newNode(Node*root, int element)
{
	root = new Node;
	root->id = element;
	root->completed = false;
	//printf("enter your discription :\n");
	//scanf("%s",root->discription);
	//root->discription = "fox";
	root->right = NULL;
	root->left = NULL;
	return root;
}

struct Node* insert(Node*root, int element)
{
	if (root == NULL)
		return newNode(root,element);
	if (element > root->id)
	{
		root->right = insert(root->right, element);
	}
	if (element < root->id)
	{
		root->left = insert(root->left, element);
	}
	else
		return root;
}

struct Node* update(Node *root, int k)
{
	if (root == NULL)
		printf("task not found!\n");
	if (k == root->id)
	{
		root->completed = true;
	}
	if (k > root->id)
		root->right = update(root->right, k);
	if (k < root->id)
		root->left = update(root->left, k);
	else
		return root;
}

void printInorder(struct Node* node)
{
	if (node != NULL)
	{
		printInorder(node->left);
		printf("%d\t ", node->id);
		printInorder(node->right);
	}

}
void printPostorder(struct Node* node)
{
	if (node != NULL)
	{
		printPostorder(node->left);
		printPostorder(node->right);
		printf("%d\t ", node->id);
	}
}
void printPreorder(struct Node* node)
{
	if (node != NULL)
	{
		printf("%d\t ", node->id);
		//printf("%s\t", node->completed);
		//printf("%s\t", node->discription);
		printf("\n");
		printPreorder(node->left);
		printPreorder(node->right);
	}
}


int main()
{
	struct Node* root = NULL;
	root = insert(root, 10);
	insert(root, 1);
	//root = insert(root, 100);
	//root = insert(root, 56);
	//root = insert(root, 79);
	//root = insert(root, 30);
	printPreorder(root);
	return 0;
}