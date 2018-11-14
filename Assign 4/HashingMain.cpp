#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include<cstdio>
#include<cstdlib>
#include<bits/stdc++.h>
//#include <TimeInterval.h>
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
			for (int i = 0; i < TABLE_SIZE; i++)
				htable[i]=NULL;
		}

		~HashTable()
		{
			for (int i = 0; i < TABLE_SIZE; ++i)
			{
				HashNode* entry = htable[i];
				while (entry != NULL)
				{
					HashNode* prev = entry;
					entry = entry->next;
					delete prev;
				}
			}
			delete[] htable;
		}

		//Hash function
		//
		//turns string into array, uses first two characters in that array (first two letters of word)
		//calculates ascii of each and adds weight to each before adding them together and returning 
		//as hash value
		int HashFunc(string key)
		{
			//length of character array
			int n = key.length();
			//cout<<"\nThis is length of array: "<<n<<"\n";
			
			//declare array
			char char_array[n+1];
			
			//copy string into array
			strcpy(char_array, key.c_str());

			//get ascii value of first two letters of word
			char char1 = char_array[0];
			char char2 = char_array[1];

			
			//cout<<"\nfirst char of array is: "<<char1<<" And 2nd char is: "<<char2<<"\n";
			
			int value1=int(char1);
			int value2=int(char2);

			//cout<<"\nAscii values: "<<value1<<" and "<<value2<<"\n";
			if(value1 <= 'Z'){ 
				value1 = (value1 - 'A' + 1) % 27 * 10000;
			}
			else {value1 = (value1 - 'a' + 1) % 27 * 100;}

			if(value2 <= 'Z'){value2 = (value2 - 'A') % 26;}
			else {value2 = (value2 - 'a') % 26;}

			int charCombined = value1 + value2;

			//cout<<"\nValue before modulo: "<<charCombined<<"\n";

			
			int hashValue = charCombined % TABLE_SIZE;
			
			cout<<"\nhashValue is: "<<hashValue<<"\n";
			
			return hashValue;	
		}

		//insert element at a key
		void Insert(string key, string value)
		{
			//cout<<"THIS IS INTERESTING: "<<key<<" "<<value;
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

		//remove element at a key
		void Remove(string key)
		{
			int hash_val = HashFunc(key);
			HashNode* entry = htable[hash_val];
			HashNode* prev=NULL;

			if (entry == NULL || entry->key != key)
			{
				cout<<"No Element found at key "<<key<<endl;
				return;
			}
			while (entry->next != NULL)
			{
				prev = entry;
				entry = entry->next;
			}
			if (prev != NULL)
			{
				prev->next = entry -> next;
			}
			delete entry;
			cout<<"Element Deleted"<<endl;
		}

		//search element at a key
		int Search(string key)
		{
			bool flag = false;
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
				//set key and value to current word
				key=line;
				key=key.substr(0, key.length()-1);
				value=key;
				cout<<"\nKey: "<<key;
				
				//pass to hash functions
				hash.Insert(key, value);
				i++;

			}
			myfile.close();

			cout<<"\nText file has been hashed!\n";
		}

		//backup if file can't be found
		//else cout<<"Unable to find or open file";

		//prompt user to search for a word
		cout<<"Enter a word to be searched: ";
		cin>>key;
		//cout<<"Element at key "<<key<<" : ";
		if (hash.Search(key) == -1)
		{
			//THIS IS WHERE YOU WOULD SAY "FALSE" BC SEARCHED WORD DOESN'T EXIST
			//BUT IF IT DOES, ALL OTHER KEYS CLOSE TO IT ARE PRINTED
			cout<<"$False.  The word '"<<key<<"' was not found"<<endl;

		}
			
	}else if (choice==2){
		
		cout<<"Thank you!";

	}else{

		cout<<"\nPlease make a valid selection";
	}
		
	return 0;
}


