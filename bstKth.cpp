//this program finds the kth smallest element in a binary seach tree
#include<iostream>
using namespace std;


//build tree
struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};

//function for creation new node
BstNode* GetNewNode(int data){

	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

//function to insert in BST, returns address of root node
BstNode* Insert(BstNode* root, int data){

	//if the root is empty, make data the root
	if(root==NULL){
		root = GetNewNode(data);
	
	}
	//if data is less than root, put it on the left side
	else if(data <= root->data){
		root->left = Insert(root->left, data);
	}
	//if data is greater, right side
	else{
		root->right = Insert(root->right, data);
	}
	return root;
}

int PrintInOrder(BstNode* root, int kth, int counter){

	//if there have been 15 node datas printed, return smallest element
	//THIS COULD EASILY BE CHANGED TO BE DYNAMIC TO MORE THAN 15 
	if (counter==15){
		return kth;
	}

	if(root != NULL){

		if (root->left != NULL){

			//go to next node to the left 
			PrintInOrder(root->left, kth, counter);
		}

		//print the nodes data
		cout<<root->data<<" ";

		//snag smallest when currently on it
		if (counter==kth){

			kth=root->data;
		}
	
		//increase counter
		counter=counter+1;
		
		if (root->right !=NULL){

			//go to next node to the right
			PrintInOrder(root->right, kth, counter);
		}
	}else{

		cout<< "\nThe tree is empty.  Cannot print.";
	}
}

int main(){


	//variable for inputted array keys and K variables
	int dataPassed, k;

	//counter to pass to print to help calculate kth smallest
	int counter=1;

	//create empty tree (pointer to top of tree)
	BstNode* root = NULL;

	//promt for value of k
	cout<<"\nHello. Please enter a value for K: ";
	cin>>k;

	//prompt user for data
	cout<<"\nPlease enter (in order) each number in the array given for the assignemnt: ";
	
	//data is inputted into tree
	for (int i=1; i<=15; i++){

		cout<<"\nelement "<<i<<" : ";
		cin>>dataPassed;
		root = Insert(root, dataPassed);
	}

	//print tree
	cout<<"\nThank you.  Printing tree...  ";


	//call print function for tree, pass K
	k=PrintInOrder(root, k, counter);

	//print kth smallest
	cout<<"\nThe Kth smallest element is: "<<k;

}


