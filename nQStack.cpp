//recursive function for solving N Queens problem
recursion(/*i, j, filled, q, N*/){

	//if there are no conflicts
	if (/*column doesn't equal any other || row+column doesn't equal any other row+ column*/){

		//increase filled
		filled=filled+1

		if (filled == N){

			//program has found solution

			//print stack?
			//while (/*!q.empty()*/){
			//	cout<<'\t'<<q.top();
			//	q.pop()
			//}
			//cout<<'\n';
			
			//end program
		}else{
			
			//move to next row and "place" queen in the first column
			i=i+1;
			q.push((i, j));
		}

	//if there is conflict and room to shift
	}else if(/*if conflict and room to shift (j<N?)*/){

		//move current queen to the right, push new position on stack
		

	//if there is conflict and no room to shift
	}else if(/*there is a conflict and j>=N (no room to shift))*/){

		//pop stack till a queen is found that can shift
		while (/*no queen can be shifted !j<N*/){

			q.pop();
			filled=filled-1;
		}

		//when shiftable is found, shift
		j=j+1;
		//push??


	}

	//call itself and pass everything
	recursion(i ,j);


//main function
int main (){

	//initialize N for num of Qs and board size
	int N=4;

	//initialize stack for queen placement
	stack <int> qPlacement	
	/*initialize first queen/position and push onto stack
	 * int i=0? int j=0?
	 * qPlacement.push((i, j));?*/

	//init filled to 0
	int filled = 0

	//call recursive function, pass current queen position, filled, stack, N
	recursion (/*i, j, filled, qPlacement, N*/);

	
}
