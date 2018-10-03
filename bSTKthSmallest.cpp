#include<stdio.h>
#include<stdlib.h>
#include <queue>
#include <iostream>
using namespace std;

//function for creating actual node
struct bstNode
{
	int key;
	struct bstNode* left;
	struct bstNode* right;

};

//create a node and give it the particular key inputted from array
struct bstNode* newBstNode(int key);

//function for entering the sorted array into a balanced BST
struct bstNode* insertArray(int array[], int start, int end)
{
	//if the start is greater than the end, return NULL
	if (start > end)				
		return NULL;

	//find middle of array and make this the root node of the whole tree
	int mid=(start + end)/2;
	struct bstNode *root = newBstNode(array[mid]);	

	//use recursion.  Recursively go through array from middle to far left and same for right
	root->left = insertArray(array, start, mid-1);
	root->right = insertArray(array, mid+1, end);

	return root;
}

//function for creation of node.  Sets key and left and right child pointers.
struct bstNode* newBstNode(int key)
{
    struct bstNode* node = (struct bstNode*)malloc(sizeof(struct bstNode));
    
    //set key to current data and left and right to NULL
    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

//function for finding K smallest
void findKthSmallest(bstNode *root, int k, int &c)
{
	//if the root is NULL or counter is greater than k
	if (root==NULL||c>=k)
		return;

	findKthSmallest(root->left, k, c);

	c++;

	//when counter is = to k, print k
	if (c==k)
	{
		cout<<"\nThe "<<k<<" largest element is: "<<root->key<<endl;
	}

	findKthSmallest(root->right, k, c);
}

//function prints tree level by level
void printTree(struct bstNode *root)
{
    //return in case there is nothing in root of tree
    if (root == NULL)  return;

    cout << "\nThank you.  Printing tree based off assignment array...\n\n"; 

    //create queue for nodes
    queue<bstNode *> q;

    //push root of tree
    q.push(root);

    while (1)
    {
        int nodeCount = q.size();
        if (nodeCount == 0)
            break;

        //while there are nodes in queue, print them
        while (nodeCount > 0)
        {
            bstNode *node = q.front();
            cout << node->key << " ";
            q.pop();
	    //push children into queue
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        cout<<endl;
    }
}

//main function
int main()
{
	//initialize array
	int array[] = {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};
    	int n = sizeof(array)/sizeof(array[0]);

	//k for finding kth element and counter
    	int k;
	int counter=0;

	//call bstNode function to play array elements in balanced tree
	struct bstNode *root = insertArray(array, 0, n-1);

	//prompt user for K
	cout<<"\nHello.  Please enter a value for K < 15: ";
	cin>>k;

	//call function to print level by level, each part of the tree
    	printTree(root);

	//call function for finding K, pass it the pointer to the top and user-inputted k
    	findKthSmallest(root, k, counter);


	return 0;
}
