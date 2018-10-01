// C++ program to insert element in binary tree 
#include <iostream> 
#include <queue> 
using namespace std; 

/* A binary tree node has key, pointer to left child 
and a pointer to right child */
struct Node { 
	int key; 
	struct Node* left, *right; 
}; 

/* function to create a new node of tree and r 
eturns pointer */
struct Node* newNode(int key) 
{ 
	struct Node* temp = new Node; 
	temp->key = key; 
	temp->left = temp->right = NULL; 
	return temp; 
}; 

/* Inorder traversal of a binary tree*/
void inorder(struct Node* temp) 
{ 
	if (!temp) 
		return; 

	inorder(temp->left); 
	cout << temp->key << " "; 
	inorder(temp->right); 
} 

/*function to insert element in binary tree */
void insert(struct Node* temp, int key) 
{ 
	queue<struct Node*> q; 
	q.push(temp); 

	// Do level order traversal until we find 
	// an empty place. 
	while (!q.empty()) { 
		struct Node* temp = q.front(); 
		q.pop(); 

		if (!temp->left) { 
			temp->left = newNode(key); 
			break; 
		} else
			q.push(temp->left); 

		if (!temp->right) { 
			temp->right = newNode(key); 
			break; 
		} else
			q.push(temp->right); 
	} 
} 

// Driver code 
int main() 
{ 
	struct Node* root = newNode(10); 
	 
    //int for data passed in 
    int dataPassed, key;
    
	cout << "Inorder traversal before insertion:"; 
	inorder(root); 
	
	cout<<"Enter tree keys";
	for (int i=1; i<=15; i++){
	    
	    cout<<"\nelement "<<i<<" : ";
	    cin>>dataPassed;
	    insert(root, key);
	}

	//int key = 12; 
	//insert(root, key); 

	cout << endl; 
	cout << "Inorder traversal after insertion:"; 
	inorder(root); 

	return 0; 
} 
