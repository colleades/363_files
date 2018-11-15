#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include<cstdio>
#include<cstdlib>
#include<bits/stdc++.h>
#include "TimeInterval.h"


using namespace std;

//table size able to handle all two letter combinations + all one letter possibilities (703)
const int TABLE_SIZE = (26*26)+27;

//Hashnode class declaration
class HashNode
{
	public:
		//string to hold word for breaking down into hash value
		string key;
		//string to hold word for storage in list
		string value;

		HashNode* next;
		HashNode(string key, string value)
		{
			this->key=key;
			this->value=value;
			this->next=NULL;
		}
};

//Hashtable declation
class HashTable
{
	private:
		HashNode** htable;
	public:
		HashTable()
		{
			htable = new HashNode*[TABLE_SIZE];
			//originally set all slots in table to NULL
			for (int i = 0; i < TABLE_SIZE; i++)
				htable[i]=NULL;
		}

		//Hash function
		//
		//turns string into array, uses first two characters in that array (first two letters of word)
		//calculates ascii of each and adds weight before adding them together, taking modulo of tablesize, and returning 
		//as hash value
		int HashFunc(string key)
		{
			//length of character array
			int n = key.length();
			
			//declare array
			char char_array[n+1];
			
			//copy string into array
			strcpy(char_array, key.c_str());

			//get first two letters of word
			char char1 = char_array[0];
			char char2 = char_array[1];

			//turn first to letters into integers from 0 to n
			int value1=int(char1)-65;
			int value2=int(char2)-65;

			//if it's a one letter word, set second "letter" value to zero
			if (value2<0){
				value2=0;
			}

			//combine characters, adding weight to first in a way that guarentees minimal collisions
			//aka number of possible different character entries (28)
			int charCombined = (value1*28) + value2;

			int hashValue = charCombined % TABLE_SIZE;
			
			//cout<<"\nhashValue is: "<<hashValue<<"\n";
			
			return hashValue;	
		}

		//insert element at a key
		void Insert(string key, string value)
		{
			int hash_val = HashFunc(key);

			//pointer to most recent node in list
			HashNode* prev = NULL;

			//pointer to first node in selected slot in table
			HashNode* entry = htable[hash_val];

			//while you haven't reached the end of the list yet/a place to put the new key
			while (entry !=NULL)
			{
				//set the starting node to variable "prev" (as in it's previous to node inserting)
				prev = entry;
				//set the entry node to the next node in list (basically shuffle down the list)
				entry = entry->next;
			}

			//if you've reached an empty spot
			if (entry == NULL)
			{
				//create a new node
				entry = new HashNode(key, value);

				//if the previous node is null
				if (prev == NULL)
				{
					//create first entry in current hashing slot in array
					htable[hash_val]=entry;
				}
				else
				{
					//move to the next node and create entry
					prev->next = entry;
				}
			}
			else
			{
				entry->value=value;
			}
		}

		//search element at a key
		int Search(string key)
		{
			//create timer object
			TimeInterval * myTimeInt = new TimeInterval();

			//start timer
			myTimeInt->start();

			//flag for indicating whether or not the word has been found
			bool flag = false;

			//find hash value and look at that slot value in hash table (array)
			int hash_val = HashFunc(key);
			HashNode* entry = htable[hash_val];

			//while the spot in the table being searched is not empty, search through list till word is found
			while (entry != NULL)
			{
				//If the word is found in the list (if current key is equal to key being searched)
				if (entry->key == key)
				{
					cout<<"\n$True. \n";
					flag = true;
					
					//stop timer
					myTimeInt->stop();
				}

				//go on to next node
				entry = entry->next;
			}

			//if the word was not found, return -1, else reset entry to first pointer and print all but searched word in list
			if (!flag){

				return -1;
			}else{
				entry = htable[hash_val];
				while (entry != NULL)
				{
					//If current node being traversed is searched word, don't print it
					if (entry->key != key)
					{
						//don't print word originally searched
						cout<<"\n"<<entry->key<<"\n";
					}

					//go on to next node
					entry = entry->next;
				}
			}

			//after printing all words, print time
			cout<<"\nSearch time: "<<myTimeInt->GetInterval()<<" micro-sec\n\n";
		}
};

//main menu
int main()
{
	int choice;
	HashTable hash;
	string key, value, line;
	
	cout<<"\nHello.  Please make a selection\n"<<endl;
	cout<<"1. Read in and hash text file"<<endl;
	cout<<"2. Exit"<<endl;
	cout<<"\nEnter your choice: ";
	cin>>choice;

	//user selection
	if (choice==1){


		ifstream myfile ("Dictionary.txt");
		if (myfile.is_open())
		{
			int i=0;
			while (getline (myfile, line))
			{
				//hash each line/string/word
				//set key and value to current word, minus last character (to avoid new line) (\n) 
				key=line;
				key=key.substr(0, key.length()-1);
				value=key;
				
				//pass to hash functions
				hash.Insert(key, value);
				i++;

			}
			myfile.close();

			cout<<"\nText file has been hashed!\n";
		}

		//backup if file can't be found
		else cout<<"Unable to find or open file";


		//prompt user to search for a word
		cout<<"\nEnter a word to be searched: ";
		cin>>key;

		//if word is not found
		if (hash.Search(key) == -1)
		{
			cout<<"\n$False.  The word '"<<key<<"' was not found\n"<<endl;
		}
			
	}else if (choice==2){
		
		cout<<"Thank you!";

	}else{

		cout<<"\nPlease make a valid selection";
	}
		
	return 0;
}


