//this program finds the kth smallest element in a binary seach tree
#include<iostream>
#include<queue>
using namespace std;


//binary tree nodes
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

//function for In Order traversal (to calculate k)
int InOrder(BstNode* root, int kth, int counter){

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

//function for printing level order traversal of the tree
void printLevelOrder(BstNode* root){

	if (root == NULL) return;

	//create queue
	queue<BstNode* >q;

	//enqueue root and initialize height
	q.push (root);

	while (1){

		//set nodeCount to size of queue/number of nodes
		int nodeCount = q.size();
		if (nodeCount == 0){

			break;
		}

		//pop out current level and push next level of tree
		while (nodeCount > 0){

			BstNode* node = q.front();
			cout<<node->data<< " ";
			q.pop();
			if (node->left != NULL){
				q.push(node->left);
			}
			if (node-> right != NULL){

				q.push(node->right);
			}
			nodeCount--;

		}
		cout<<endl;
	}
	/*queue<BstNode*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()){

		BstNode *n=q.front();
		q.pop();
		if (n!=NULL){

			if(n->left!=NULL){
				q.push(n->left);
			}
			if(n->right!=NULL){
				q.push(n->right);
			}
			cout<<n->data<<" ";
		}
		else
		{
			cout<<"\n";
			if(!q.empty()){
				q.push(NULL);
			}
		}
	}*/



}

int main(){

	//initialzie array
	int array[15] = {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};

	//variable for inputted array keys and K variables
	int dataPassed, k;

	//counter to pass to print to help calculate kth smallest
	int counter=1;

	//create empty tree (pointer to top of tree)
	BstNode* root = NULL;

	//promt for value of k
	cout<<"\nHello. Please enter a value for K: ";
	cin>>k;
	
	//data is inputted into tree
	for (int i=1; i<=15; i++){

		dataPassed=array[i];
		root = Insert(root, dataPassed);
	}

	cout<<"\nThank you.  Printing tree based off assignment array...  \n\n";

	//print tree
	printLevelOrder(root);


	//find K
	k=InOrder(root, k, counter);

	//print kth smallest
	cout<<"\nThe Kth smallest element is: "<<k<<"\n";

	return 0;

}


/*
 *
 * PRINT IN THIS ORDER: ROOT, LEFT CHILD, RIGHT CHILD.  A B C B D E C F G
 *
 */
