#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "HashTable.h"

using namespace std;

Hashing::Hashing()
{
	for (int i = 0; i < tableSize; i++) //runs through the hash table
	{//D.A. all indexes of the hash table
		HashTable[i] = new item;
		HashTable[i]->ID = dfI; //And sets the default values given to it. Will change this but for now, just making up variables to fill the table
		HashTable[i]->name = dfS;
		HashTable[i]->cost = dfD;
		HashTable[i]->quanity = dfI;
		HashTable[i]->store = dfS;
		HashTable[i]->dueDate = dfS;
		HashTable[i]->next = NULL; //what it points to for the next item.
	}
}

/*hashFcn(): Function that will take in a string value named key
and changing it to an int and then set it to the remainder of the 
 converted string (hash) divided by the size of the table  
(The remainder is the index)
*/
int Hashing::hashFcn(string key)
{
	int hash = 0; //the converted string into int (using ASCII)
	int index; //index of the key

	index = key.length(); //gives index a value


	for(int count = 0; count < key.length(); count++)
	{
		hash = hash + (int)key[count]; //(int)key converts the characters of the string into ASCII
	}

	index = hash % tableSize; //making the index

		return index;
}

/*search(): This function takes in a value (the name of an item)
and search the hash table for it. If the item was found, the function
will print out that the item was found.
Else, if it wasn't found, the function simply states that the item wasn't
found in the hash table.
*/
void Hashing::search(string name)
{
	int index = hashFcn(name); //finds the hash value of that particular name and sets index equal to it

	bool found = false; //bool for if found/if not found
	//string product;

	item *tablePtr = HashTable[index]; //create a pointer to the hash table

	while (tablePtr != NULL) //go through the table as long as there is an item
	{
		if (tablePtr->name == name)//if the pointer is pointing at the name that is equal to the string passsed to it,
		{
			found = true; //it has been found
			//product = tablePtr->ID;
		}
		tablePtr = tablePtr->next; //moves to the next item to check
	}
	if (found) //if the item was found.
	{
		cout << "Item found." << endl;
		cout << "Id: " << tablePtr->ID << endl;
		cout << "Name: " << tablePtr->name << endl;
		cout << "Cost: " << tablePtr->cost << endl;
		cout << "Quanity: " << tablePtr->quanity << endl;
		cout << "Preferred Shop: " << tablePtr->store << endl;
		cout << "Due Date: " << tablePtr->dueDate << endl;
	}
	else//if it wasn't found
	{
		cout << "Item " << name << " was not found." << endl;
	}

}


/*addItem(): Function that will take in 6 strings (ID, name, cost, quanity, store and dueDate)
and use these strings to add a new item/ element into the hash table or write over an existing
item with the same index. This will probably need to get changed to use the collision requirements instead.
*/
void Hashing::addItem(int ID, string name, double cost, int quanity, string store, string dueDate)
{
	int index = hashFcn(name); //Index will be set to the hashed value of the ID (ID is being used as the key here)

	//Info Check!
	
	if (HashTable[index]->ID == dfI) //if the index is the same...
	{//override it with the new information !!!!!!!!!!!!!!!!!!!!!!!!!!!!!This will need to be changed for the collision check requirement
		HashTable[index]->ID = ID;
		HashTable[index]->name = name;
		HashTable[index]->cost = cost;
		HashTable[index]->quanity = quanity;
		HashTable[index]->store = store;
		HashTable[index]->dueDate = dueDate;
	}
	else //if the index is not the same...
	{//add a new item
		item* tablePtr = HashTable[index];
		item* newPtr = new item; //points to a new item to place the info

		//pass the new info to the new item with newPtr
		newPtr->ID = ID;
		newPtr->name = name;
		newPtr->cost = cost;
		newPtr->quanity = quanity;
		newPtr->store = store;
		newPtr->dueDate = dueDate;

		newPtr->next = NULL; //next one has a pointer pointing to nothing

		//Now we need to add the new item to the end of the table
		while (tablePtr->next != NULL)//while the next pointer in the hash table isn't pointing to nothing,
		{
			tablePtr = tablePtr->next; //This will make the pointer go through the table until it gets to the last element to be able to point to it. (This is just to get tablePtr to point to the last element)
		}
		tablePtr->next = newPtr; //Link last element of the table to the new info. (Adding the new info to the back of the table)
	}
}


/*removeItem(): This function is designed to remove items
from the hash table. However, before this function removes
anything, it will go through many if statements to try to
find the item first. If the item was found, it's information 
will be removed. 
*/
void Hashing::removeItem(string name)
{
	int index = hashFcn(name); //set the index equal to the hash value of the name

	item* remPtr; //removePointer
	item* itemPtr1;
	item* itemPtr2;

	//If the index is empty
	if (HashTable[index]->name == "Name") //if the name in hash table index is the default one (means nothing is there)
	{
		cout << "Item was not found." << endl;
	}

	//Index only contains 1 item and and it has a matching name
	else if (HashTable[index]->name == name && HashTable[index]->next == NULL) //if the name in the hash table matchs the name passed to the function AND there is not next item,
	{
		//set the index equal to default
		HashTable[index]->ID == dfI;
		HashTable[index]->name == dfS;
		HashTable[index]->cost == dfD;
		HashTable[index]->quanity == dfI;
		HashTable[index]->store == dfS;
		HashTable[index]->dueDate == dfS;

		cout << "Removal was successful." << endl;
	}

	//The match is located in the first item in the index but there are more items in the index

	else if (HashTable[index]->name == name) //Last 'if' checked to see if the next item was nothing so this 'if' is designed to already assume that
	{										//the index has nore than one item in it.
		remPtr = HashTable[index]; //have remPtr point to that particular index of the hash table
		HashTable[index] = HashTable[index]->next; //And then have HashTable[index] actually be the next item in the list

		delete remPtr; //removes the index from the hashtable

		cout << "Removal was successful." << endl;

	}

	//Index contains items but the first item doesn't match
	else
	{
		itemPtr1 = HashTable[index]->next; //Make the first pointer point to the second item in the index. (Becasue from the other 'ifs', we can assume that there is more than one item)
		itemPtr2 = HashTable[index]; //Make the second pointer point to the first item in the index

		while (itemPtr1 != NULL && itemPtr1->name != name) //while itemPtr1 has something and that something doesn't equal the name that was passed to the function
		{//move both pointers along the index list
			itemPtr2 = itemPtr1;
			itemPtr1 = itemPtr1->next;
			//is is just to step through the entire list of the index to look though everything for a match
		}

		//if it wasn't found,
		if (itemPtr1 == NULL)
		{
			cout << "Item was not found." << endl;
		}

		//if it was found
		else
		{
			//remove the info
			remPtr = itemPtr1;
			itemPtr1 = itemPtr1->next;
			itemPtr2->next = itemPtr1;

			delete remPtr;

			cout << "Removal was successful." << endl;
		}

	}
}

/*countItems(): Takes in an index passed to it and calculates the 
number of items within that particular index using the variable count
and then returning that variable. (This function is later used in the 
display functions)
*/
int Hashing::countItems(int index)
{
	int count = 0;

	//Looking at the first item of the index.
	if (HashTable[index]->ID == dfI) //If the first item is just a default form,
	{
		return count; //returns nothing (zero; nothing has been set to that index yet)
	}
	else
	{
		count++;
		item* tablePtr = HashTable[index]; //points to the first item in the index

		while (tablePtr->next != NULL)//while the next item in the index is not nothing,
		{
			count++;
			tablePtr = tablePtr->next; //move it down the list of items in the index
		}
	}
}

/*display(): Displays the contents (items of the indexes) and number of items for each index
of the hash table using for loops and the function countItems().
*/
void Hashing::display()
{
	int num; //variable used to hold the number of items in each index/element

	for (int i = 0; i < tableSize; i++)
	{
		num = countItems(i); //set num equal to the number of items for this index

		//Display the contains of this index
		cout << "index: " << i << endl;
		cout << "ID: " << HashTable[i]->ID << endl;
		cout << "Name: " << HashTable[i]->name << endl;
		cout << "Cost: " << HashTable[i]->cost << endl;
		cout << "Quanity: " << HashTable[i]->quanity << endl;
		cout << "Prefered Store: " << HashTable[i]->store << endl;
		cout << "Due Date: " << HashTable[i]->dueDate << endl;
		//cout << "Number of items for this index: " << num << endl;

	} 
}

/*displayItems(): Displays only the items in a particular index.
*/
void Hashing::displayItems(int index)
{
	item* tablePtr = HashTable[index]; //points to the index of hash table

	if (tablePtr->ID == dfI) //check to see if the index is empty (default),
	{ //This method assumes that only ID needs to change to be considered not empty, may need to come back to fix this 
		cout << "Info for index: " << index << endl;
		cout << "This index is empty" << endl;
	}
	else
	{
		cout << "Info for index: " << index << endl;

		while (tablePtr != NULL) //While the index does have something
		{

			cout << "ID: " << tablePtr->ID << endl;
			cout << "Name: " << tablePtr->name << endl;
			cout << "Cost: " << tablePtr->cost << endl;
			cout << "Quanity: " << tablePtr->quanity << endl;
			cout << "Prefered Store: " << tablePtr->store << endl;
			cout << "Due Date: " << tablePtr->dueDate << endl;

			tablePtr = tablePtr->next;//points to the next item
		}
	}
}

/*displayKeySeq(): This function will display the hash table's
contents only after it has been sorted by 'key' order. The one 
with the smallest hash key will be the first to be displayed. 
*/
void Hashing::displayKeySeq()//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!This function is messy, gross and doesn't work properly and I know it.  
{		
																		//Could I get some help in making it run more logically?/Actually do what it's meant to do?
	
	int keys[tableSize]; //array of keys
	item *ptr; //pointer of item type


	for (int i = 0; i < tableSize; i++)//fill the array
	{
		ptr = HashTable[i];

		keys[i] = hashFcn(ptr->name); //start filling the keys array
	}

	//now sort the array
	int i, j, imin, temp;
	
	for (j = 0; j < tableSize; j++)
	{
		imin = j;
		for (i = j + 1; i < tableSize; i++)
		{
			if (keys[i] < keys[imin])
			{
				imin = i;
			}
		}
		if (imin != j)
		{
			temp = keys[j];
			keys[j] = keys[imin];
			keys[imin] = temp;
		}
	}
	//just a selection sort

	for (int i = 0; i < tableSize; i++)
	{
		int index = keys[i];

		cout << "ID: " << HashTable[index]->ID << endl;
		cout << "Name: " << HashTable[index]->name << endl;
		cout << "Cost: " << HashTable[index]->cost << endl;
		cout << "Quanity: " << HashTable[index]->quanity << endl;
		cout << "Prefered Store: " << HashTable[index]->store << endl;
		cout << "Due Date: " << HashTable[index]->dueDate << endl;
		cout << "-----------------------------" << endl;
		
	}
	
	
	/*item *Ptr;
	for (int i = 1; i < tableSize; i++)
	{
		Ptr = HashTable[i]; //set it to point to the table

		int keyVal1; //key values
		int keyVal2;

		for (int j = i; (j > 0); j--)
		{
			keyVal1 = hashFcn(HashTable[j - 1]->name); //set the key values 
			keyVal2 = hashFcn(Ptr->name);

			if (keyVal1 < keyVal2) //if key 1 is greater than key 2
			{
				HashTable[j] = HashTable[j - 1];  //set it back one

				HashTable[j] = Ptr; //assign new value to the pointer
				
			}
		}
			//display
			cout << "index: " << i << endl;
			cout << "ID: " << Ptr->ID << endl;
			cout << "Name: " << Ptr->name << endl;
			cout << "Cost: " << Ptr->cost << endl;
			cout << "Quanity: " << Ptr->quanity << endl;
			cout << "Prefered Store: " << Ptr->store << endl;
			cout << "Due Date: " << Ptr->dueDate << endl;
		
	}*/

}
