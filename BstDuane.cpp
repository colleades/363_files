/*
	Filename: kthElement.cpp
    Written by: Duane Weddle
    Purpose: BST kth smallest element lab csci360
    Date: 10/01/2018
    Modification History:
	09/20/2018: Initial program
*/

#include<stdio.h>
#include<stdlib.h>
#include <queue>
#include <iostream>
using namespace std;

/* Creates structure for BST nodes to be stored in*/
struct bstNode
{
	int key;
	struct bstNode* left;
	struct bstNode* right;

};

struct bstNode* newBstNode(int key); // Initilazies a member of bstNode with the int key

/*	 Creates a BST from a sorted array.
	Accepts sorterd array, array start(0), and end(arr length)
	Returns array root
*/
struct bstNode* arrToBST(int arr[], int start, int end)
{
	if (start > end)				// Program returns Null if start/end don't make sense
		return NULL;

	int middle = (start + end)/2; 	// Finds middle array value to make it the BST Root
	struct bstNode *root = newBstNode(arr[middle]);		//Creates a root from the middle of the array

	root->left = arrToBST(arr, start, middle-1);	// ADD THESE
	root->right = arrToBST(arr, middle+1, end);

	return root;
}

struct bstNode* newBstNode(int key)
{
    struct bstNode* node = (struct bstNode*)
                         malloc(sizeof(struct bstNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}


void kthSmallestTraversal(bstNode *root, int k, int &c)
{
	if (root == NULL || c >= k)
		return;

	kthSmallestTraversal(root->left, k, c);

	c++;

	if (c == k)
	{
		cout << "The " << k << "th largest element is: " << root->key << endl;
	}

	kthSmallestTraversal(root->right, k, c);
}

void findKthSmallest(bstNode *root, int k)
{
	int c = 0;											//COMMENTTTTTTTTTTTTTTTTTTTTTTTT

	kthSmallestTraversal(root, k, c);
}

void printBstLevels(struct bstNode *root)
{
    // Base Case
    if (root == NULL)  return;

    cout << "Printing BST Node Tree:" << endl;

    // Create an empty queue for level order tarversal
    queue<bstNode *> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (1)
    {
        // nodeCount (queue size) indicates number of nodes
        // at current lelvel.
        int nodeCount = q.size();
        if (nodeCount == 0)
            break;

        // Dequeue all nodes of current level and Enqueue all
        // nodes of next level
        while (nodeCount > 0)
        {
            bstNode *node = q.front();
            cout << node->key << " ";
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        cout << endl;
    }
}

int main()
{
	int arr[] = {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;

	struct bstNode *root = arrToBST(arr, 0, n-1);
	cout << "Please pick a number to find the K-th smallest element in the array." << endl;
	cin >> k;
	if (k > n || k < 0)
	{
		cout << "ERROR: Please pick a number from 0 to " << n << endl;
		return 0;
	}

    findKthSmallest(root, k);
    printBstLevels(root);

	return 0;
}
