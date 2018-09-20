//recursive function for checking conflict between queens
bool checkConflict (int row, int column){

	bool result=false;

	//row coming from top of stack
	int stackRow=row;

	//get column from stack
	int stackColumn=qStack.top();

	//if columns or diagnols are the same
	if (column==stackColumn){

		result=true;
	}	
	if ((row+column)==(stackRow+stackColumn){

		result=true;
	}
	if ((row-column)==(stackRow+stackColum)){
		
		result=true;
	}

	//pop off stack and decrease stackRow by 1
	qStack.pop();
	stackRow=stackRow-1;

	checkConflict(row, column);

	qStack.push(stackColumn);

	return result;

}



//recursive function for placing queens
void placement(int N, int row, int column, stack<int>qStack, filled){

	//if there are no conflicts
	if (checkConflict(row, column)==false){

		//increase filled
		filled=filled+1

		if (filled == N){

			//program has found solution

			//int position=1
			//
			//print stack?
			//while the stack is not empty
			//	pop off top
			//	print (position+row+column);
			//	row=row-1
			//	position=position-1
			//
			
			//end program

		}else{
			
			//move to next row and "place" queen in the first column
			row=row+1;
			column=1;
			qStack.push(column);
			
		}

	//if there is conflict and room to shift
	}else if(checkConflict(row, column)==true && column!=N){

		column=column+1;
		

	//if there is conflict and no room to shift
	}else if(checkConflict(row, column)==true && column==){

		//pop stack till a queen is found that can shift
		while (column=N){

			qStack.pop();
			filled=filled-1;
			column=qStack.top();
		}

		//when movable queen is found, move it one over (pop off, increase, push)
		qStack.pop();
		column=column+1;
		qStack.push(column);
		


	}

	//call itself and pass everything
	recursion(row, column,);



//main function
int main (){

	//initialize N for num of Qs and board size
	int N=4;

	//initialize stack for queen placement
	stack <int> qPlacement	

	//initialize first queen/position and push onto stack
	int row=1;
	int column=1;
	qPlacement.push(column);

	//init filled to 0
	int filled = 0

	//call recursive function, pass current queen position, filled, stack, N
	placement (N, row, column, qPlacement, filled);

	return 0;
	
}
