/*
Given a Sorted Doubly Linked List and a Binary Search Tree , Check if they are identical or not .
The DLL will have nodes of type node_dll
Note :
A DLL can be represented as a BST in many forms ,And if a dll and any one of the forms is given as input you
need to return 1 otherwise 0. 

->Dont Create an Extra Array ,or else your solution would receive 20% Cut in the Marks you got .

Examples :

Example 0:
DLL:1->5->8
BST(All 3 return 1):
    5         8      1
   / \       /        \
  1   8     5          5
           /            \
          1              8
Returns 1
    8
   / \
  5   1
Returns 0
Example 1:
DLL : 1->5
BST : 
5
 \
 10
Returns 0

Example 2:
DLL:1->3->5-9->11
BST:
    5
   / \
  1   11
   \  /      
    3 9

Returns 1

Example 3:
DLL: 1->5->7->10->12->15->20
BST:
        10
        /\
       5  15
      /\  / \
     1  7 12 20
Returns 1

Note 2 :
Unequal Length BST and DLL should return 0;
Return -1 for NULL inputs

Difficulty : Medium +
*/
#include <stdlib.h>
#include <stdio.h>

struct node_dll{
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};
struct node{
	int data;
	struct node *left;
	struct node *right;
};

void inorderTraversal(struct node *root, int *arr);
void quicksort2(int x[10], int first, int last);


int *array1 = NULL, l1 = 0;
int *array2 = NULL, l2 = 0;



int is_identical(struct node_dll *head, struct node *root){

	array1 = (int *)malloc(40 * sizeof(int));
	array2 = (int *)malloc(40 * sizeof(int));
	int i = 0;
	int flag = 1;


	if (root == NULL || head == NULL)
	{
		return -1;
	}
	else
		inorderTraversal(root, array1);

	quicksort2(array1, 0, l1 - 1);


	for (i = 0; i < l1; i++)
		printf(" %d", array1[i]);

	while (head != NULL)
	{
		array2[l2++] = head->data;
		head = head->next;
	}

	quicksort2(array2, 0, l2 - 1);

	for (i = 0; i < l2; i++)
		printf("  %d", array2[i]);

	if (l1 != l2)
		return 0;
	for (i = 0; i < l1; i++)
	{
		if (array1[i] != array2[i])
			flag = 0;
	}

	return flag;
}

void inorderTraversal(struct node *root, int *arr1)
{

	if (root == NULL) {
		return;
	}

	inorderTraversal(root->left, arr1);

	arr1[l1++] = root->data;

	inorderTraversal(root->right, arr1);

}

void quicksort2(int x[10], int first, int last){
	int pivot, j, temp, i;

	if (first<last){
		pivot = first;
		i = first;
		j = last;

		while (i<j){
			while (x[i] <= x[pivot] && i<last)
				i++;
			while (x[j]>x[pivot])
				j--;
			if (i<j){
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}

		temp = x[pivot];
		x[pivot] = x[j];
		x[j] = temp;
		quicksort2(x, first, j - 1);
		quicksort2(x, j + 1, last);

	}
}
