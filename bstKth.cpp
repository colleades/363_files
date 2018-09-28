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
	cout<<"inside getnewnode";
	return newNode;
}

//function to insert in BST, returns address of root node
BstNode* Insert(BstNode* root, int data){

	//if the root is empty, make data the root
	if(root==NULL){
		root = GetNewNode(data);
		cout<<"added to root";
	
	}
	//if data is less than root, put it on the left side
	else if(data <= root->data){
		root->left = Insert(root->left, data);
		cout<<"put on the left side";
	}
	//if data is greater, right side
	else{
		root->right = Insert(root->right, data);
		cout<<"put on the right side";
	}
	return root;
}

void PrintInOrder(BstNode* root, int kth){

	if(root != NULL){

		if (root->left != NULL){

			PrintInOrder(root->left, kth);
		}
		cout<<root->data<<" ";
		if (root->right !=NULL){

			PrintInOrder(root->right, kth);
		}
	}else{

		cout<< "\nThe tree is empty.  Cannot print.";
	}
}

int main(){

	//create empty tree (pointer to top of tree)
	BstNode* root = NULL;

	//prompt user for data
	cout<<"\nPlease enter (in order) each number in the array given for the assignemnt: ";
	
	//variable for inputted array keys and K
	int dataPassed, k;

	//data is inputted into tree
	for (int i=1; i<=15; i++){

		cout<<"\nelement "<<i<<" : ";
		cin>>dataPassed;
		root = Insert(root, dataPassed);
	}

	cout<<"\nTree has been constructed.  Please enter a value for K: ";
	cin>>k;
	cout<<"\nThank you.  Printing tree...  ";

	//call print function for tree, pass K
	PrintInOrder(root, k);
}


