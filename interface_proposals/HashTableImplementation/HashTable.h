
#include <iostream>
#include <string>
#include "ListItem.h"


#ifndef HASHTABLE_H
#define HASHTABLE_H

//default values

std::string dfS = "";
int dfI = 0;
double dfD = 0.00;

struct listNode //linked list
{
	item* itemPtr;
	listNode* next;
};

struct item //struct named item that will be held in the hash table (this will act like the items)
{ //what the items contain
	
	ListItem* list;
	item* next; // pointer that allows the item to point to another item
};

class Hashing
{
private:
	static const int tableSize = 25; //size of the hash table (Or max size the table can be) This will need to be changed to accept a "change-able" value to allow the hash table to be editted


	item* HashTable[tableSize]; //the hash table essentially; an array of items

	int hashFcn(const std::string& key); //Function that will take in string key and change it to an int that will become the index number in the hash table of an element 

public:
	Hashing();

							
	item *search(std::string name); //searches the hash table with the name of the item and displays the index id found

	void addItem(const *ListItem newItem, listNode *&start, listNode *&end); //Function that will add items into the hash table

	item *removeItem(const std::string name, listNode *&start, listNode *&end); //Removes items and indexes depending on what name is passed to it

	int countItems(int index); //This function will count the number of items in an index (element) in the hash table. (Will be used in the display functions)

	void display(); //Displays the hash table;

	//void displayKeySeq(); //Displays the hash table using the hashing key sequence

	void displayItems(int index); //Displays the items of a particular index


	//for the linked list

	bool empty(listNode *start)//checks to see if the list is empty
	{
		if (start == NULL) //if the first element hsa nothing
		{
			return true; //we can assume that the rest of the list is empty as well
		}
		else //if not,
			return false;
	}

	void firstNode(listNode *&start, listNode *&end, item *itemPtr)//sets up the first node in the linked list
	{
		//set up first node
		listNode *temp = new listNode;
		temp->itemPtr = itemPtr;
		temp->next = NULL;
	}

	bool searchList(item *itemPtr, listNode *&start)// searches through the list to stop doubles from being entered into the hash table
	{
		listNode *node = start; //set the first node to the first element in the list
		

		//traverse the list with the node
		while (node != NULL) //while node has something in it,
		{
			
			if (node->itemPtr == itemPtr) //check to see if there's a match
			{
				return true; //return the node
			}

			else //if it doesn't match,
			{
				//move on to the next one
				node = node->next;
			}
		}
		//if nothing matched, return NULL
		return false;
	}
	

};

#endif 