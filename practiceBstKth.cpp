#include<iostream>
#include<queue>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

void printLevelByLevel(Node* root){

	queue<Node* > q;

	q.push(root);

	while(q.size() > 0){

		int currentLevelNodes = q.size();
		while (currentLevelNodes > 0){
			Node* p = q.front();
			q.pop();
			cout<<" "<<p->data;
			if (p->left !=NULL) q.push(p->left);
			if (p->right !=NULL) q.push(p->right);
			currentLevelNodes--;
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
	
	//counter to help with k calculation
	int counter=1;


	//prompt for k
	cout<<"Hello.  Please enter a value for K < 15: ";
	cin>>k;
	cout<<"\n\nThank you.  Printing Tree. . . \n\n";

	//create null root to be filled later
	Node* root = NULL;
	
	//for every array key, insert it into tree
	for (int i=0; i<15; i++){

		dataPassed=array[i];
		root = Insert(root, dataPassed);
	}
	
	//Print Nodes in Level Order. 
	printLevelByLevel(root);

	//find K using in order function
	k=InOrder(root, k, counter);

	cout<<"\nThe Kth smallest element is: "<<k<<"\n";
	
}


