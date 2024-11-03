#include <stdio.h>
#include <stdlib.h>
//DFS tree traversal
struct node{

	int val;
	int count;
	struct node * left;
	struct node * right;

};

void createNew(struct node ** ptr, int value)
{
	struct node * ptrN = malloc(sizeof(struct node));
	ptrN->left = NULL;
	ptrN->right = NULL;
	ptrN->val = value;
	ptrN->count = 1;
	*ptr = ptrN;
	printf("New Node Created ! \n");

}
// pre order is Node, left , right
void preOrderPrint(struct node ** ptr)
{
	printf("(%d)", (*ptr)->val);
	if ((*ptr)->left != NULL)
	{
		//printf("(%d)", (*ptr)->val);
		preOrderPrint(&((*ptr)->left));
	}
	//printf("(%d)", (*ptr)->val);

	if ((*ptr)->right != NULL)
	{
		//printf("(%d)", (*ptr)->val);
		preOrderPrint(&((*ptr)->right));
	}
}
void InOrderPrint(struct node ** ptr)
{ // left node right
	if((*ptr)->left != NULL)
	{
		InOrderPrint(&((*ptr)->left));

	}
	printf("(%d)", (*ptr)->val);

	if ((*ptr)->right != NULL)
	{
		InOrderPrint(&((*ptr)->right));
	}
}
void PostOrderPrint(struct node **ptr)
{ // left right node
	if ((*ptr)->left != NULL)
	{
		PostOrderPrint(&((*ptr)->left));
	}
	
	if ((*ptr)->right != NULL)
	{
		PostOrderPrint(&((*ptr)->right));
		//printf("(%d)", (*ptr)->val);
	}
	printf("(%d)", (*ptr)->val);
}
void insertValue(struct node ** ptr , int value)
{	
	if((*ptr)->val == value)
	{
		(*ptr)->count +=1;
		return;
	}
	if((*ptr)->val > value)
	{
		if((*ptr)->left == NULL)
		{	printf("Inserted at left ! \n");
			struct node * temp = malloc(sizeof(struct node));
			temp->left = NULL;
			temp->right = NULL;
			temp->val = value;
			temp->count =1;
			(*ptr)->left = temp;
			return;

		}
		printf("Going left\n");
		insertValue(&((*ptr)->left),value);
		return;
	}
	if ((*ptr)->val < value)
	{
		if ((*ptr)->right == NULL)
		{
			printf("Inserted at right !\n");
			struct node *temp = malloc(sizeof(struct node));
			temp->left = NULL;
			temp->right = NULL;
			temp->val = value;
			temp->count = 1;
			(*ptr)->right = temp;
			return;
		}
		printf("going right\n");
		insertValue(&((*ptr)->right), value);
		return;
	}

}

int main()
{
	struct node * head = NULL;
	createNew(&head,10);
	insertValue(&head, 5);
	insertValue(&head, 20);
	insertValue(&head, 3);
	insertValue(&head,9);
	insertValue(&head,15);
	insertValue(&head,25);
	printf("INORDER:");
	InOrderPrint(&head);
	printf("\n");
	printf("PREORDER:");
	preOrderPrint(&head);
	printf("\n");
	printf("POSTORDER:");
	PostOrderPrint(&head);
	//printf("Here is the value stored at the top %d\n", head->val);
	//printf("\nHere is %d\n",head->left->right->val);
	//printf("Here is %d\n", head->right->left->val);
	return 0;
}
