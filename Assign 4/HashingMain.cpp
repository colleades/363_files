//Algorithm

//read in text file, turn it into strings.  Access characters in string (array)

#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include<cstdio>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;

const int TABLE_SIZE = 128;

//Hashnode class declaration
class HashNode
{
	public:
		string key;
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
			//declare array
			char char_array[n+1];
			//copy string into array
			strcpy(char_array, key.c_str());

			//get ascii value of first two letters of word
			int char1 = int(char_array[0]);
			int char2 = (char_array[1]);

			cout<<"INSIDE Hash function and char1 is: "<<char1<<" And char2 is: "<<char2;

			int hashValue=(char1+char2) % TABLE_SIZE;
			cout<<"\nAnd now the hashValue is: "<<hashValue<<"\n";
			return hashValue;
			
			//add weight then add	
		}

		//insert element at a key
		void Insert(string key, string value)
		{
			int hash_val = HashFunc(key);
			HashNode* prev = NULL;
			HashNode* entry = htable[hash_val];
			while (entry !=NULL)
			{
				prev = entry;
				entry = entry->next;
			}
			if (entry == NULL)
			{
				entry = new HashNode(key, value);
				if (prev == NULL)
				{
					htable[hash_val]=entry;
				}
				else
				{
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
			while (entry != NULL)
			{
				if (entry->key == key)
				{
					cout<<entry->value<<" ";
					flag = true;
				}
				entry = entry->next;
			}
			if (!flag)
				return -1;
		}
};

//main menu
int main()
{
	HashTable hash;
	string key, value;
	int choice;
	while (1)
	{
		cout<<"\n-----------------------"<<endl;
		cout<<"Operations on Hash table"<<endl;
		cout<<"\n---------------------"<<endl;
		cout<<"1. insert"<<endl;
		cout<<"2. search"<<endl;
		cout<<"3 delete"<<endl;
		cout<<"4 exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{

		case 1:
			cout<<"enter element to be inserted: ";
			cin>>value;
			cout<<"Enter key at which element to be inserted: ";
			cin>>key;
			hash.Insert(key, value);
			break;

		
		case 2:
			cout<<"Enter key of element to be searched: ";
			cin>>key;
			cout<<"Element at key "<<key<<" : ";
			if (hash.Search(key) == -1)
			{
				//THIS IS WHERE YOU WOULD SAY "FALSE" BC SEARCHED WORD DOESN'T EXIST
				//BUT IF IT DOES, ALL OTHER KEYS CLOSE TO IT ARE PRINTED
				cout<<"No element found at key "<<key<<endl;
				continue;
			}
			break;
		case 3:
			cout<<"Enter key of the element to be deleted: ";
			cin>>key;
			hash.Remove(key);
			break;
		case 4:
			exit(1);
		default:
			cout<<"\nEnter corrent optiont\n";


		}
	}
	return 0;
}




/*int main () {
	
	string line;
	ifstream myfile ("Dictionary.txt");
	if (myfile.is_open()){
		while (getline (myfile, line)){

			cout<<line<<'\n';
		}
		myfile.close();
	}

	else cout<<"Unable to open file";

	return 0;
}*/


