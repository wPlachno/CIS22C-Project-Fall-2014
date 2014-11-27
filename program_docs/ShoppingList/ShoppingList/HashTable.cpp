/*Nicolette Hart
22C Data Structures
Team 5
Goel
*/


#include <iostream>
#include <string>
#include <vector>
#include "HashTable.h"
#include "ListItem.h"

//default values

std::string dfS = "";
int dfI = 0;
double dfD = 0.00;

HTable::HTable()
{
	HashTable = new item*[tableSize];
	for (int i = 0; i < tableSize; i++) //runs through the hash table
	{//D.A. all indexes of the hash table
		HashTable[i] = new item;
		
		//HashTable[i + 1] = NULL; //what it points to for the next item.
	}
}

/*hashFcn(): Function that will take in a string value named key
and changing it to an int and then set it to the remainder of the 
 converted string (hash) divided by the size of the table  
(The remainder is the index)
*/
int HTable::hashFcn(const std::string& key/*, const ListItem* newItem*/)
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
ListItem *HTable::search(std::string name)
{
	//const ListItem *temp = new ListItem;
	int index = hashFcn(name/*, temp*/); //finds the hash value of that particular name and sets index equal to it


	bool found = false; //bool for if found/if not found
	//string product;

	item *tablePtr = HashTable[index]; //create a pointer to the hash table
	while (tablePtr != NULL && tablePtr->list != NULL && !found) //go through the table as long as there is an item
	{
		if (tablePtr->list->getKey() == name || tablePtr->overflow->itemPtr->getKey() == name) //if the pointer is pointing at the name that is equal to the string passsed to it,
		{
			found = true; //it has been found
		
		}
		else
		{
			tablePtr = tablePtr->next; //moves to the next item to check
		}
	}

	if (found) //if the item was found.
	{
		return tablePtr->list;
	}
	else//if it wasn't found
	{	
		return NULL;
	}

}

/*addItem(): Function that will take in 6 strings (ID, name, cost, quanity, store and dueDate)
and use these strings to add a new item/ element into the hash table or write over an existing
item with the same index. This will probably need to get changed to use the collision requirements instead.
*/
void HTable::addItem(ListItem* newItem)
{
	int index = hashFcn(newItem->getKey()/*, newItem*/); //Index will be set to the hashed value of the ID (ID is being used as the key here)


	//Info Check!

	if (search(/*HashTable[index]->list->getName()*/newItem->getKey()) != NULL)//if the item at the index can be found in the table already,
	{
		//then it's a duplicate of the same item

		//don't add it again
		std::cout << "This item already exists" << std::endl;

	}
	else //if the item wasn't found in the table...
	{//add a new item

		addToList(index); //add the index to the list


		//add to the hash table
		item* tablePtr = HashTable[index]; // //
		item* newPtr = new item; //points to a new item to place the info

		if (HashTable[index]->list == NULL) //if hashTable list is empty
		{
			HashTable[index]->list = newItem; //set the new item's values to that particular element
		}
		else //if the index of the HashTable is NULL
		{
			ListItem* data;	// a temp object pointer of ListItem
			string s = newItem->getKey(); //a temp string to hold the new item's name value

			if (s < HashTable[index]->list->getKey()) //if the new name is smaller than the name that's already in the index,
			{
				data = HashTable[index]->list; //data will hold the the element that's already in that index of the HashTable

				if (HashTable[index]->overflow == NULL)// if the overflow list of that index is empty,
				{
					keyOverFlow* flow = new keyOverFlow; //create a new keyOverFlow pointer object,
					flow->itemPtr = data; // set the itemPtr equal to data (which still holds the element) 
					flow->overflow = NULL; //and set the new object's (flow) overflow equal to NULL
					HashTable[index]->list = newItem; //set the HashTable of that index with the values of the new item, (it overwrites what's already in there; don't worry, it's saved in data!)
					HashTable[index]->overflow = flow; //Then set the HashTable of the index's (the one we just overwrote with the new item's values) overflow list equal to the object flow (the item that was previously in that hashTable's index!)
				}
				else //if the overflow list isn't empty,
				{
					keyOverFlow* head = HashTable[index]->overflow;	//create temp object pointer called head to hold everything that's inside the element's overflow
					keyOverFlow* follow = NULL;	//and another temp object pointer named follow (Will be used to hold the values of the element before the "head")
					do //do ...
					{
						if (head->itemPtr->getKey() < data->getKey()) //if the name stored in head is less than the new name that was passed to data,
						{
							follow = head; //follow now moves up one, (head's values)
							head = head->overflow; //and head now equals the values in it's overflow
						}
						else if (head->itemPtr->getKey() > data->getKey()) //if the name stored in head is GREATER than the new name that was passed to data,
						{
							break; //don't do anything (It's fine the way it is)
						}

					} while (head != NULL); //...while head has something in it

					if (follow == NULL) //if follow is empty (meaning head is at the very beginning of the list)
					{
						keyOverFlow* added = new keyOverFlow;	//create a new temp object pointer named added
						added->overflow = head; //the overflow list of added is equal to the values of head
						added->itemPtr = data; //added's itemPtr now equals data's info
						HashTable[index]->overflow = added; //The overflow of the index is then equal to the info of added
						HashTable[index]->list = newItem; //and HashTable list now equals the new element info
					}
					else //if follow isn't empty
					{
						keyOverFlow* added = new keyOverFlow; //create added again
						follow->overflow = added; //set follow's overflow equal to added (making an empty space in the overflow)
						added->overflow = head; //added's overflow equals head
						added->itemPtr = data; //and added's itemPtr equals data
						HashTable[index]->list = newItem; //Lastly, set HashTAble list equal to the new info
					}
				}
			}
			else if (s > HashTable[index]->list->getKey()) //If the new name is bigger that the one in the index already, uses the same algorithm as the first if statement, but only modifies the overflow list, NOT the HashTable[index]->list item
			{
				data = newItem; //data equals the new element

				if (HashTable[index]->overflow == NULL)// if the overflow list of that index is empty,
				{
					keyOverFlow* flow = new keyOverFlow; //create a new keyOverFlow pointer object,
					flow->itemPtr = data; // set the itemPtr equal to data (which still holds the new element) 
					flow->overflow = NULL; //and set the new object's (flow) overflow equal to NULL
					//HashTable[index]->list = newItem; //set the HashTable of that index with the values of the new item, (it overwrites what's already in there; don't worry, it's saved in data!)
					HashTable[index]->overflow = flow; //Then set the HashTable of the index's overflow list equal to the object flow (the new item!)
				}
				else //if the overflow list isn't empty,
				{
					keyOverFlow* head = HashTable[index]->overflow;	//create temp object pointer called head to hold everything that's inside the element's overflow
					keyOverFlow* follow = NULL;	//and another temp object pointer named follow (Will be used to hold the values of the element before the "head")
					do //do ...
					{
						if (head->itemPtr->getKey() < data->getKey()) //if the name stored in head is less than the new name that was passed to data,
						{
							follow = head; //follow now moves up one, (head's values)
							head = head->overflow; //and head now equals the values in it's overflow
						}
						else if (head->itemPtr->getKey() > data->getKey()) //if the name stored in head is GREATER than the new name that was passed to data,
						{
							break; //don't do anything (It's fine the way it is)
						}

					} while (head != NULL); //...while head has something in it

					if (follow == NULL) //if follow is empty (meaning head is at the very beginning of the list)
					{
						keyOverFlow* added = new keyOverFlow;	//create a new temp object pointer named added
						added->overflow = head; //the overflow list of added is equal to the values of head
						added->itemPtr = data; //added's itemPtr now equals data's info (the new info)
						HashTable[index]->overflow = added; //The overflow of the index is then equal to the info of added
						//HashTable[index]->list = newItem; //and HashTable list now equals the new element info
					}
					else //if follow isn't empty (meaning head is not at the beginning of the list)
					{
						keyOverFlow* added = new keyOverFlow; //create added still
						follow->overflow = added; //set follow's overflow equal to added (making an empty space in the overflow)
						added->overflow = head; //added's overflow equals head
						added->itemPtr = data; //and added's itemPtr equals data
						HashTable[index]->overflow = added; //Lastly, set HashTable's overflow equal to the new info (added)
					}
				}
			}

			/*//set the double and int values for assignment
			double Dtemp = newItem->getCost();
			int Itemp = newItem->getQuantity();

			//pass the new info to the new item with newPtr
			//newPtr->list->ID = newItem->ID; Not doing ID?
			newPtr->list->getKey() = newItem->getKey();
			Dtemp = newPtr->list->getCost(); // = newItem->getCost();   //setting up the double and int values before assignment seemed to have fixed the error...
			Itemp = newPtr->list->getQuantity();
			newPtr->list->getStore() = newItem->getStore();
			newPtr->list->getDate() = newItem->getDate();*/

			newPtr->next = NULL; //next one has a pointer pointing to nothing

			//Now we need to add the new item to the end of the table
			while (tablePtr->next->list != NULL)//while the next pointer in the hash table isn't pointing to nothing,
			{
				tablePtr = tablePtr->next; //This will make the pointer go through the table until it gets to the last element to be able to point to it. (This is just to get tablePtr to point to the last element)
			}
			tablePtr->next = newPtr; //Link last element of the table to the new info. (Adding the new info to the back of the table)
		}
	}
}


/*removeItem(): This function is designed to remove items
from the hash table. However, before this function removes
anything, it will go through many if statements to try to
find the item first. If the item was found, it's information 
will be removed. Depending if the removal was successful,
this function will return a true or false bool
*/
bool HTable::removeItem(const std::string name)
{
	const ListItem *temp = new ListItem;
	int index = hashFcn(name/*, temp*/); //set the index equal to the hash value of the name

	bool done = false; //bool to will be returned from this function to specify whether removal was a success
	//true: success
	//false: failed/wasn't found

	item* remPtr; //removePointer
	item* itemPtr1;
	item* itemPtr2;

	//If the index is empty
	if (HashTable[index]->list->getKey() == dfS) //if the name in hash table index is the default one (means nothing is there)
	{
		//if there's nothing in the element, the same can be said for the overflow list

		//reason for not having a removeFromList function here is if the element wasn't found in the hash Table, it won't be in the list either.
		done = false;
		return done;
	}

	//Index only contains 1 item and and it has a matching name
	else if (HashTable[index]->list->getKey() == name || HashTable[index]->overflow->itemPtr->getKey() == name /*the overflow list*/&& HashTable[index]->next == NULL) //if the name in the hash table matchs the name passed to the function AND there is not next item,
	{
		if (HashTable[index]->overflow->itemPtr->getKey() == name) //if the match is in the overflow list
		{
			HashTable[index]->overflow->itemPtr = NULL; //set the item in the overflow list to NULL
		}
		else
		{
			HashTable[index]->list = NULL; //removes the item from the list
			removeFromList(index); //removes from the index list

			done = true;
			return done;
		}
	}

	//The match is located in the first item in the index but there are more items in the index

	else if (HashTable[index]->list->getKey() == name || HashTable[index]->overflow->itemPtr->getKey() == name /*the overflow list*/) //Last 'if' checked to see if the next item was nothing so this 'if' is designed to already assume that
	{										//the index has nore than one item in it.

		if (HashTable[index]->overflow->itemPtr->getKey() == name) //the overflow list
		{
			HashTable[index]->overflow->itemPtr = NULL; //set the item in the overflow list to NULL
		}
		else
		{
			remPtr = HashTable[index]; //have remPtr point to that particular index of the hash table
			HashTable[index] = HashTable[index + 1]; //And then have HashTable[index] actually be the next item in the list

			delete remPtr; //removes the index from the hashtable
			removeFromList(index); //removes from the index list

			done = true;
			return done;
		}

	}

	//Index contains items but the first item doesn't match
	else
	{
		itemPtr1 = HashTable[index + 1]; //Make the first pointer point to the second item in the index. (Becasue from the other 'ifs', we can assume that there is more than one item)
		itemPtr2 = HashTable[index]; //Make the second pointer point to the first item in the index

		while (itemPtr1 != NULL && itemPtr1->list->getKey() != name) //while itemPtr1 has something and that something doesn't equal the name that was passed to the function
		{//move both pointers along the index list
			itemPtr2 = itemPtr1;
			itemPtr1 = itemPtr1->next;
			//is is just to step through the entire list of the index to look though everything for a match
		}

		//if it wasn't found,
		if (itemPtr1 == NULL)
		{
			done = false;
			return done;
		}

		//if it was found
		else
		{
			//remove the info
			remPtr = itemPtr1;
			itemPtr1 = itemPtr1->next;
			itemPtr2->next = itemPtr1;

			delete remPtr;
			removeFromList(index);//removes from the index list

			done = true;
			return done;
		}

	}
}

/*countItems(): Takes in an index passed to it and calculates the 
number of items within that particular index using the variable count
and then returning that variable. (This function is later used in the 
display functions)
*/
int HTable::countItems(int index)
{
	int count = 0;

	//Looking at the first item of the index.
	if (HashTable[index]->list->getKey() == dfS) //If the first item is just a default form,
	{
		return count; //returns nothing (zero; nothing has been set to that index yet)
	}
	else
	{
		count++;
		item* tablePtr = HashTable[index]; //points to the first item in the index

		while (tablePtr->next != NULL)//while the next item in the index is not nothing,
		{
			if (tablePtr->overflow->itemPtr != NULL) //if there'ssomething in the overflow list,
			{
				count++; //add one to the count 
			}
			else
			{
				count++;
				tablePtr = tablePtr->next; //move it down the list of items in the index
			}
		}
	}
	return count;
}

/*display(): Displays the contents (items of the indexes) and number of items for each index
of the hash table using for loops and the function countItems().
*/
void HTable::display()
{
	int num; //variable used to hold the number of items in each index/element

	for (int i = 0; i < tableSize; i++)
	{
		//num = countItems(i); //set num equal to the number of items for this index

		//Display the contains of this index
		std::cout << "index: " << i << std::endl;
		std::cout << "Name: " << HashTable[i]->list->getKey() << std::endl;
		std::cout << "Cost: " << HashTable[i]->list->getCost() << std::endl;
		std::cout << "Quanity: " << HashTable[i]->list->getQuantity() << std::endl;
		std::cout << "Prefered Store: " << HashTable[i]->list->getStore() << std::endl;
		std::cout << "Due Date: " << HashTable[i]->list->getDate() << std::endl;

	} 
}

/*displayItems(): Displays only the items in a particular index.
*/
void HTable::displayItems(int index)
{
	item* tablePtr = HashTable[index]; //points to the index of hash table

	if (tablePtr->list->getKey() == dfS) //check to see if the index is empty (default),
	{ //This method assumes that only ID needs to change to be considered not empty, may need to come back to fix this 
		std::cout << "Info for index: " << index << std::endl;
		std::cout << "This index is empty" << std::endl;
	}
	else
	{
		std::cout << "Info for index: " << index << std::endl;

		while (tablePtr != NULL) //While the index does have something
		{
			std::cout << "Name: " << tablePtr->list->getKey() << std::endl;
			std::cout << "Cost: " << tablePtr->list->getCost() << std::endl;
			std::cout << "Quanity: " << tablePtr->list->getQuantity() << std::endl;
			std::cout << "Prefered Store: " << tablePtr->list->getStore() << std::endl;
			std::cout << "Due Date: " << tablePtr->list->getDate() << std::endl;

			tablePtr = tablePtr->next;//points to the next item
		}
	}
}

/*PrintEff(): Function that will show the efficiency of the hash table
by using the load factor
*/
void HTable::PrintEff()
{
	float loadFactor; //the load factor
	int count; //to help calculate the number of elements in the table

	item *tablePtr = HashTable[0]; //create a pointer to the hash table pointing to the first element of the table

	while (tablePtr->list != NULL) //while it isn't empty
	{
		if (tablePtr->overflow->itemPtr != NULL) //while there's something in the overflow list,
		{
			count++; //add one to the count
		}

		else
		{
			count++;
			tablePtr = tablePtr->next; //move to the next item
		}

	}
	
	loadFactor = count /*number of items in the table*/ / tableSize; //max size of the table

	float successSearch = (1 / 2) * (1 + (1 / (1 - loadFactor))); //using the linear probing algorithm
	float failSearch = (1 / 2) * (1 + (1 / (1 - (loadFactor * loadFactor)))); //loadFactor squared

	std::cout << "Success Efficiency : " << successSearch << std::endl;
	std::cout << "Fail Efficiency : " << failSearch << std::endl;
}

/*~HTable(): The destructor of the class
*/
HTable::~HTable()
{

}

