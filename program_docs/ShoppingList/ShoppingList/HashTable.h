/*Nicolette Hart
22C Data Structures
Team 5
Goel
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <iostream>
#include <string>
#include "ListItem.h"


struct keyOverFlow //linked list for collision resolution
{
	ListItem* itemPtr;
	keyOverFlow* overflow;	//change to be named overflow
};

struct item //struct named item that will be held in the hash table (this will act like the items)
{ //what the items contain
	
	ListItem* list;
	item* next; // pointer that allows the item to point to another item
	keyOverFlow* overflow; //puts any key conflicts here
	item(){
		list = NULL;
		next = NULL;
		overflow = NULL;
	};
};

struct listKey //linked list for key comparing
{
	//listKey(listKey *&start1, int itemKey1, item* itemPtr1, listKey* next1) : start(start1), itemKey(itemKey1), itemPtr(itemPtr1), next(next1) {}; //used to initialize the ref variable start.
	int itemKey;
	item *itemPtr;
	listKey *next;	//remove entirely, use HashTable[x+1] or whatever
	//listKey *&start;
	listKey(){
		itemKey = NULL;
		itemPtr = NULL;
		next = NULL;
	}
};

class HTable
{
private:
	static const int tableSize = 1; //size of the hash table (Or max size the table can be) This will need to be changed to accept a "change-able" value to allow the hash table to be editted

	item** HashTable;
	//item* HashTable[tableSize]; //the hash table essentially; an array of items

	int hashFcn(const std::string& key/*, const ListItem* newItem*/); //Function that will take in string key and change it to an int that will become the index number in the hash table of an element 

public:
	HTable(); //construct
	~HTable(); //destruct

							
	ListItem *search(std::string name); //searches the hash table with the name of the item and displays the index id found

	void addItem(ListItem* newItem); //Function that will add items into the hash table

	bool removeItem(const std::string name); //Removes items and indexes depending on what name is passed to it

	int countItems(int index); //This function will count the number of items in an index (element) in the hash table. (Will be used in the display functions)

	void display(); //Displays the hash table;

	void displayItems(int index); //Displays the items of a particular index

	void PrintEff(); //Prints out the Efficiency

	//for the comparing linked list

	bool empty(listKey *start)//checks to see if the list is empty
	{
		if (start == NULL || start->itemKey == NULL) //if the first element has nothing
		{
			return true; //we can assume that the rest of the list is empty as well
		}
		else
		{//if not,
			return false;
		}
	}

	void firstNode(int index)//sets up the first node in the linked list
	{
		//set up first node
		listKey *temp = new listKey;
		temp->itemKey = index;
		temp->next = NULL;
	}

	bool searchList(listKey *start, int index)// searches through the list to detect key doubles
	{
		//listKey *node = start; //set the first node to the first element in the list


		//traverse the list with the node
		while (start != NULL && start->itemKey != NULL) //while the node has something in it,
		{

			if (start->itemKey == index) //check to see if there's a match
			{
				return true; //return the node
			}

			else //if it doesn't match,
			{
				//move on to the next one
				start = start->next;
			}
		}
		//if nothing matched, return NULL
		return false;
	}


	void addToList(int index) //adds the index to the list, but checks for double indexes first
	{
		listKey *newKeys = new listKey;

		//create the first node in the list if none exists yet;
		if (empty(newKeys))//if there's nothing in the list,
		{
			//create the first node
			firstNode(index);
		}
		//if it isn't empty, it should just skip the first if statement a start comparing
		//compare with the linked list
		/*else if (searchList(newKeys, index))
		{
			keyOverFlow *flow = new keyOverFlow;

			//retrieve the first occurrence from the table
			flow = HashTable[index]->overflow; //and add the second key occurrence to the overflow list

		}*/
		else if(!searchList(newKeys, index)) //if the index isn't used yet, add it to the list
		{ 
			newKeys->itemKey = index; //set the value to the node
			newKeys->next = NULL;// and set the next node to NULL
		}
	}


	void removeFromList(int index) //removes an index from the list (if the index can be found
	{
		listKey *keys = new listKey;
		listKey *del = NULL; //delete

		if (empty(keys))//if the list is empty,
			{
				return; //just return
			}
		else if (searchList(keys, index)) //if found,
		{
			//delete it
			del = keys;
			keys = del->next;
			delete del;
		}
		else //if the list isn't empty AND the index wasn't found in the list
		{
			return; //just return
		}
	}

};

#endif 