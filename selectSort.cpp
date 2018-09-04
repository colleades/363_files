//Selection Sort Case-Study

#include <iostream>

//function for sorting array
void Selection_sort(int A[], int n)
{
	
	//temp variable for exchange
	int temp;

	//for every spot in array, makred with j, find smallest number and switch
	for (int j=1; j<=n-1; j++)
	{
		int smallestNum = j;

		//find smallest number in array
		for (int i=j+1; i<=n; i++)
		{
			if (A[i] < A[smallestNum])
			{
				smallestNum = i;
			}
		}

		//exchange
		temp=A[j];
		A[j]=A[smallestNum];
		A[smallestNum]=temp;	

	}
	
}

int main()
{
	//initialize array of default 100 
	int arrA[100];
	int size;

	//prompt user for length and keys
	std::cout<<"\n Enter the length of array (max 100): ";
	std::cin>>size;
	std::cout<<"\n Enter the array keys \n ";

	for (int i=1; i<=size; i++)
	{
		std::cout<<"element "<<i<<" : ";
		std::cin>>arrA[i];
	}

	//take inputted elements and call function to sort array
	Selection_sort(arrA, size);

	std::cout<<"\n Sorted in ascending order \n ";
	for (int i=1; i<=size; i++)
	{
		std::cout<<" \n element "<<i<<" : "<<arrA[i];

	}

	return 0;

}
