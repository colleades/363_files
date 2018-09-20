#include <string>
#include <stack>
#include<iostream>



using namespace std;

void messStack(stack<int>* queenStack)
{
	//queenStack.push(3);
	queenStack->push(3);
	cout<<"inside function, 3 pushed";
	
	//while (!queenStack.empty()){
	//	cout<<'\n'<<queenStack.top();
	//  	queenStack.pop();

}

int main()
{

	stack<int>qStack;
	qStack.push(4);
	cout<<"stack created, 4 pushed ";

	messStack(&qStack);

	cout<<"after function called";

	qStack.push(5);

	while (!qStack.empty()){

		cout<<'\n'<<qStack.top();
		qStack.pop();
	}

	return 0;	
}

