#include "stdafx.h"
#include <iostream>
#include <string>
//rhoyer - unneccessary comments (not all of them just some)
//rhoyer - namespace std?
//rhoyer - 

using namespace std; //take this out and place std:: in front of every string for file consistency

#ifndef HASHTABLE_H
#define HASHTABLE_H

//Question: Will all the variables of the items be of type string? Ex. ID is string rather than int.
class Hashing
{
private:
	static const int tableSize = 25; //size of the hash table (Or max size the table can be) This will need to be changed to accept a "change-able" value to allow the hash table to be editted

	//default values
	static const string dfS = "";
	static const int dfI = 0;
	static const double dfD = 0.00;
	//rhoyer there should be only two things here
	
	
	struct item //struct named item that will be held in the hash table (this will act like the items)
	{ //what the items contain
		/*int ID; //item's id (might just be considered key. May have to take this out later
		string name; //name of the item
		double cost; //cost of the item
		int quanity; //quanity needed of the item
		string store; //prefered store to use for the item
		string dueDate; //date in which the item is needed*/
		// types may change depending on later decisions
		item* listItem; //
		item* next; // pointer that allows the item to point to another item
	};

	item* HashTable[tableSize]; //the hash table essentially; an array of items

public:
	Hashing();
	//i think this should be private or protected.  No one outside of this class will be using it
	int hashFcn(const string& key); //Function that will take in string key and change it to an int that will become the index number in the hash table of an element 
	//rhoyer - this should return a pointer to the data not print						
	void search(string name); //searches the hash table with the name of the item and displays the index id found
	//rhoyer - change this to take one argument (const ListItem* -- or whatever we decide on during the meeting)
	void addItem(int ID, string name, double cost, int quanity, string store, string dueDate); //Function that will add items into the hash table
	//rhoyer - this should return a pointer to the removed item
	void removeItem(const string& name); //Removes items and indexes depending on what name is passed to it
		//Set all 'deleted' to NULL instead - rhoyer actually just remove the node from the list at the table location

	int countItems(int index); //This function will count the number of items in an index (element) in the hash table. (Will be used in the display functions)
	//rhoyer - how does this differ from the displayKeySeq method?
	void display(); //Displays the hash table;

	void displayKeySeq(); //Displays the hash table using the hashing key sequence
	//rhoyer - is this necessary? - I think this would be best implemented outside of this class
	void displayItems(int index); //Displays the items of a particular index


};

#endif 
