/* Binary tree - Level Order Traversal */
#include<iostream>
#include<queue>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

// Iterative method to do level order traversal line by line 
void PrintLevelOrder(Node *root) 
{ 
    // Base Case 
    if (root == NULL)  return; 
  
    // Create an empty queue for level order tarversal 
    queue<Node *> q; 
  
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
            Node *node = q.front(); 
            cout << node->data << " "; 
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

//function for In Order traversal (to calculate k)
int InOrder(Node* root, int kth, int counter){

	//if there have been 15 node's data  printed, return smallest element
	//THIS COULD EASILY BE CHANGED TO BE DYNAMIC TO MORE THAN 15 
	if (counter==15){
		return kth;
	}

	if(root != NULL){

		if (root->left != NULL){

			//go to next node to the left 
			InOrder(root->left, kth, counter);
		}

		//if the current parse number  == declared k, set that data to k
		if (counter==kth){

			kth=root->data;
		}
	
		//increase counter
		counter=counter+1;
		
		if (root->right !=NULL){

			//go to next node to the right
			InOrder(root->right, kth, counter);
		}
	}else{

		cout<< "\nThe tree is empty.  Cannot print.";
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
	
	int array[15] = {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};

	//variable for inputted array keys and K variables
	int dataPassed, k;


	//prompt for k
	cout<<"What is K: ";
	cin>>k;

	Node* root = NULL;
	
	//for every array key, insert it into tree
	for (int i=0; i<15; i++){

		dataPassed=array[i];
		root = Insert(root, dataPassed);
	}
	
	//Print Nodes in Level Order. 
	PrintLevelOrder(root);

	//find K
	
}


	/*
	//counter to pass to print to help calculate kth smallest
	int counter=1;


	promt for value of k
	cout<<"\nHello. Please enter a value for K: ";
	cin>>k;
	
	//data is inputted into tree
	for (int i=1; i<=15; i++){

		dataPassed=array[i];
		root = Insert(root, dataPassed);
	}

		
	cout<<"\nThank you.  Printing tree based off assignment array...  \n\n";
	*/

