/* Binary tree - Level Order Traversal */
#include<iostream>
#include<queue>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

// Function to print Nodes in a binary tree in Level order
void LevelOrder(Node *root) {
	if(root == NULL) return;
	queue<Node*> Q;
	Q.push(root);  
	//while there is at least one discovered node
	while(!Q.empty()) {
		Node* current = Q.front();
		Q.pop(); // removing the element at front
		cout<<current->data<<" ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
	}
}
// Function to Insert Node in a Binary Search Tree
Node* Insert(Node *root,int data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data) root->left = Insert(root->left,data);
	else root->right = Insert(root->right,data);
	return root;
}

int main() {
	//Code To Test the logic
	//Creating an example tree

	Node* root = NULL;
	
	root = Insert(root,6); 
	root = Insert(root,17);
	root = Insert(root,20); 
	root = Insert(root,41); 
	root = Insert(root,45); 
	root = Insert(root,52);
	
	//Print Nodes in Level Order. 
	LevelOrder(root);
}
