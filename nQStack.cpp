#include<iostream>
#include<stack>

using namespace std;



//recursive function for checking conflict between queens
bool checkConflict (int r, int c, stack<int>qStack){

	
	bool result=false;

	//row coming from top of stack
	int stackRow=r;

	//get column from stack
	int stackColumn=qStack.top();

	if (r==1){

		result=false;
	}else{

		//if columns or diagnols are the same
		if (c==stackColumn){

			result=true;
		}	
		if ((r+c)==(stackRow+stackColumn)){

			result=true;
		}
		if ((r-c)==(stackRow+stackColumn)){
		
			result=true;
		}
		//if columns or diagnols are the same
		if (c==stackColumn){

			result=true;
		}	
		if ((r+c)==(stackRow+stackColumn)){

			result=true;
		}
		if ((r-c)==(stackRow+stackColumn)){
		
			result=true;
		}
	}

	

	return result;



	//pop off stack and decrease stackRow by 1
//	qStack.pop();
//	stackRow=stackRow-1;

//	if (qStack.empty()){

//		return result;
//	}else{
	//	checkConflict(r,c,qStack);
//	}


}





//recursive function for placing queens
void placement(int N,stack <int> queenStack,int ro, int col, int fill){


	//if there are no conflicts
	if (checkConflict(ro, col, queenStack)==false){

		//increase filled
		fill=fill+1;


		if (fill == N){

			//program has found solution

			//Variable for printing position
			int position=1;
			
			//print stack?
			while (!queenStack.empty()){

				qStack.pop();
				std::cout<<'\n'<<"Position: "<<ro<<", "<<queenStack.top();
				row=row-1;
				position=position-1;

			}
		
			//end program
			
			

		}else{
			
			//move to next row and "place" queen in the first column
			row=row+1;
			column=1;
			qPlacement.push(column);
			
		

	//if there is conflict and room to shift
	}else if(checkConflict(ro, col, queenStack)==true && col!=N){

		//pop queen off, increase by 1, push back on (move queen over one spot)
		queenStack.pop();
		col=col+1;
		queenStack.push(col);
		

	//if there is conflict and no room to shift
	}else if(checkConflict(ro, col, queenStack)==true && col==N){

		//pop stack till a queen is found that can shift
		while (col=N){

			queenStack.pop();
			ro=ro-1;
			fill=fill-1;
			col=queenStack.top();
		}

		//when movable queen is found, move it one over (pop off, increase, push)
		queenStack.pop();
		col=col+1;
		queenStack.push(col);
		


	}

	//call itself and pass everything
	placement(N,queenStack,ro,col,fill);


}	

//main function
int main ()
{

	//initialize N for num of Qs and board size
	int N=4;

	//initialize stack for queen placement
	stack <int> qPlacement;	

	//initialize first queen/position and push onto stack
	int row=1;
	int column=1;
	qPlacement.push(column);

	//place second queen on board and start placement recursion
	row=row+1;
	qPlacement.push(column);

	//init filled to 0
	int filled = 1;

	//call recursive function, pass current queen position, filled, stack, N
	placement (N,qPlacement,row,column,filled);

	return 0;
	
}




/*
 *
 * 1. how to reference array?  Pass by reference between functions?
 * 2. how to end program inside placement()
 *
 * */


