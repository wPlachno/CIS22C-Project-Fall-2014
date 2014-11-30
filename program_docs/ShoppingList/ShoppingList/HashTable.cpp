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
	}
}

HTable::HTable(int tS)
{
	if (tS < 0) //if the number passed to the construct is neg,
	{
		tS = tS * -1; //times it by negative
	}
	tableSize = tS;
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
	int index = hashFcn(name); //finds the hash value of that particular name and sets index equal to it


	bool found = false; //bool for if found
	
		if (HashTable[index]->list == NULL) //if it's empty to begin with, there's nothing there
		{
			found = false; //found should stay as false
		}
		else if (HashTable[index]->list->getKey() == name)//if the names match,
		{
			found = true; //it's been found
		}
		else if (HashTable[index]->list->getKey() != name && HashTable[index]->overflow != NULL) //if the names don't match AND the item's overflow list isn't empty,
		{
			keyOverFlow *temp = new keyOverFlow; //make a temp object
			temp = HashTable[index]->overflow; //to hold the values of the overflow of the index

			while (temp != NULL && !found) //while the overflow list isn't empty AND a match hasn't been found yet
			{
				//check the name in the overflow list
				if (temp->itemPtr->getKey() == name) //if than name in the overflow matches the name passed
				{
					found = true;
					return temp->itemPtr;
				}
				//if it doesn't match,
				temp = temp->overflow; //helps move to the next item in the overflow
			}
		}
	
	if (found) //if the item was found.
	{
		return HashTable[index]->list;
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
		else //if the index of the HashTable isn't NULL
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

			newPtr->next = NULL; //next one has a pointer pointing to nothing
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
ListItem *HTable::removeItem(const std::string name)
{
	const ListItem *temp = new ListItem;
	int index = hashFcn(name/*, temp*/); //set the index equal to the hash value of the name

	item* remPtr; //removePointer
	item* itemPtr1;
	item* itemPtr2;

	//If the index is empty
	if (HashTable[index]->list->getKey() == dfS) //if the name in hash table index is the default one (means nothing is there)
	{
		//if there's nothing in the element, the same can be said for the overflow list

		//reason for not having a removeFromList function here is if the element wasn't found in the hash Table, it won't be in the list either.
		
		return NULL;
	}

	else if (HashTable[index]->list->getKey() == name /*|| HashTable[index]->overflow->itemPtr->getKey() == name the overflow list && HashTable[index + 1] == NULL*/) //if the name in the hash table matchs the name passed to the function,
	{
		ListItem *move = new ListItem; //a temp that will be used to help move the ifo from the overlist to the place of the deleted index
		keyOverFlow *flow = new keyOverFlow;//and a temp to move the overflow up one as well
		if (HashTable[index]->overflow != NULL) //And there's something in the overflow list,
		{
			move = HashTable[index]->overflow->itemPtr; //move will hold the overflow
			flow = HashTable[index]->overflow->overflow;
			HashTable[index]->list = move; //overwrites whatever was there before

			while (flow != NULL)//loop to go through the overflow list
			{
				HashTable[index]->overflow = flow; //moves the overflow list up one in the list
				
				flow = flow->overflow; //moves one through the list
			}
			return HashTable[index]->list;
		}
		else
		{
			HashTable[index]->list = NULL; //set it to nothing
			return HashTable[index]->list;
		}

	}
	else if (HashTable[index]->list->getKey() != name) //if the name in the index doesn't match the name passed into the function,
	{ //check the overflow
		if (HashTable[index]->overflow != NULL) //if there's something in the overflow list
		{
			keyOverFlow *data = HashTable[index]->overflow; //create new object pointer and set it equal to that index's overflow

			if (data->itemPtr->getKey() == name) //if the name in the overflow is the same as the name passed to the function,
			{
				data->itemPtr = NULL; //set it to nothing
				delete data; //delete the pointer
				return HashTable[index]->list;
			}
			else //if the names don't match
			{//check the overflow within the overflow struct
				if (data->overflow != NULL)
				{
					keyOverFlow *remove = data->overflow; //have remove equal that overflow (ran out of names...)

					if (remove->itemPtr->getKey() == name) //if THAT equals the name passed to it.
					{
						remove->itemPtr = NULL;
						delete remove;
						return HashTable[index]->list;
					}
					else //IF the name passed doesn't match, the name in the index, the index's overflow or the overflow's overflow,
					{
						return NULL; //it doesn't exist
					}
				}
			}
		}
		else //if the name doesn't match and there's nothing in the index's overflow,
		{
			return NULL; //it doesn't exist
		}

		return NULL;
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
void const HTable::display()
{
	int num; //variable used to hold the number of items in each index/element


	for (int i = 0; i < tableSize; i++)
	{
		if (HashTable[i]->list != NULL) //if that particular index doesn't equal NULL (the default string)
		{
			//Display the contains of this index
			std::cout << "index: " << i << std::endl;
			std::cout << "Name: " << HashTable[i]->list->getKey() << std::endl;
			std::cout << "Cost: " << HashTable[i]->list->getCost() << std::endl;
			std::cout << "Quanity: " << HashTable[i]->list->getQuantity() << std::endl;
			std::cout << "Prefered Store: " << HashTable[i]->list->getStore() << std::endl;
			std::cout << "Due Date: " << HashTable[i]->list->getDate() << std::endl;
			cout << "-----------------------------" << endl;

			if (HashTable[i]->overflow != NULL) //if the index's overflow isn't empty,
			{
				keyOverFlow *temp = new keyOverFlow; //again, make a temp object
				temp = HashTable[i]->overflow; //have the temp object hold the overflow
				
				while (temp != NULL) //if the overflow has something, 
				{
					//dsplay the overflow
					std::cout << "index: " << i << std::endl;
					std::cout << "Name: " << temp->itemPtr->getKey() << std::endl;
					std::cout << "Cost: " << temp->itemPtr->getCost() << std::endl;
					std::cout << "Quanity: " << temp->itemPtr->getQuantity() << std::endl;
					std::cout << "Prefered Store: " << temp->itemPtr->getStore() << std::endl;
					std::cout << "Due Date: " << temp->itemPtr->getDate() << std::endl;
					cout << "-----------------------------" << endl;

					temp = temp->overflow; //check the next overflow
				}
			}
		}
		else //if it is NULL, it should just be skipped
		{

		}
	} 
}

/*displayItems(): Displays only the items in a particular index.
*/
void const HTable::displayItems(std::string name)
{
	int index = hashFcn(name);
	//item* tablePtr = HashTable[index]; //points to the index of hash table

	if (search(name) != NULL) //if the name passed to to function is found in the hashtable
	{//check the first info in the index
		if (HashTable[index]->list->getKey() == name) //if the index's name matches the name passed to the function,
		{
			std::cout << "Name: " << HashTable[index]->list->getKey() << std::endl;
			std::cout << "Cost: " << HashTable[index]->list->getCost() << std::endl;
			std::cout << "Quanity: " << HashTable[index]->list->getQuantity() << std::endl;
			std::cout << "Prefered Store: " << HashTable[index]->list->getStore() << std::endl;
			std::cout << "Due Date: " << HashTable[index]->list->getDate() << std::endl;
			cout << "-----------------------------" << endl;
		}
		else if (HashTable[index]->overflow != NULL) //if there's something in the hashTable
		{
			keyOverFlow *temp = new keyOverFlow; //create a temp object,
			temp = HashTable[index]->overflow; // and set it to the overflow of the index

			while (HashTable[index]->overflow != NULL)//while the item's overflow isn't empty
			{
				if (temp->itemPtr->getKey() == name)//if the overflow name matches the name that was passed,
				{//display the item
					std::cout << "Name: " << temp->itemPtr->getKey() << std::endl;
					std::cout << "Cost: " << temp->itemPtr->getCost() << std::endl;
					std::cout << "Quanity: " << temp->itemPtr->getQuantity() << std::endl;
					std::cout << "Prefered Store: " << temp->itemPtr->getStore() << std::endl;
					std::cout << "Due Date: " << temp->itemPtr->getDate() << std::endl;
					cout << "-----------------------------" << endl;
					break; //and break the loop (because you already found what you're looking for
				}
				
					temp = temp->overflow; //go to the next item in the overflow
			}
		}
		else //if the name wasn't found in the HashTable
		{
			std::cout << "Error: Item was not found." << std::endl;
			cout << "-----------------------------" << endl;
		}
	}
}

/*PrintEff(): Function that will show the efficiency of the hash table
by using the load factor
*/
void const HTable::PrintEff()
{
	double loadFactor; //the load factor
	int count = 0; //to help calculate the number of elements in the table
	int index = 0;

	while (index < tableSize) //while it isn't empty
	{
		if (HashTable[index]->list != NULL) //if the index isn't empty
		{
			count++;

			if (HashTable[index]->overflow != NULL) //while there's something in the overflow list,
			{
				keyOverFlow *key = new keyOverFlow;
				key = HashTable[index]->overflow;

				while (key != NULL) //while the overflow has something;
				{
					count++; //add one to the count
					key = key->overflow; //move down the overflow list
				}
			}
		}
			index++;
	}
	
	//change ints to doubles
	double dCount = count;
	double dTableSize = tableSize;

	loadFactor = dCount /*number of items in the table*/ / dTableSize; //max size of the table

	double successSearch = (1.0 / 2.0) * (1.0 + (1.0 / (1.0 - loadFactor))); //using the linear probing algorithm
	double failSearch = (1.0 / 2.0) * (1.0 + (1.0 / (1.0 - (loadFactor * loadFactor)))); //loadFactor squared

	std::cout << "Success Efficiency : " << successSearch << std::endl;
	std::cout << "Fail Efficiency : " << failSearch << std::endl;
}


/*displayKeySeq(): This function will display the hash table's
contents only after it has been sorted by 'key' order. The one
with the smallest hash key will be the first to be displayed.
*/
void const HTable::displayKeySeq()
{
	int *keys = new int[tableSize]; //array of keys
	item *ptr; //pointer of item type
	for (int i = 0; i < tableSize; i++)//fill the array
	{
		ptr = HashTable[i];
		keys[i] = hashFcn(ptr->list->getKey()); //start filling the keys array
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
			temp = keys[j]; //set temp equal to the index
			keys[j] = keys[imin]; //set that index to the smallest
			keys[imin] = temp; //set the smallest equal to temp (the larger one)
		}
	}
	//print out the array
	for (int i = 0; i < tableSize; i++)
	{
		int index = keys[i];

		cout << "Name: " << HashTable[index]->list->getKey() << endl;
		cout << "Cost: " << HashTable[index]->list->getCost() << endl;
		cout << "Quanity: " << HashTable[index]->list->getQuantity() << endl;
		cout << "Prefered Store: " << HashTable[index]->list->getStore() << endl;
		cout << "Due Date: " << HashTable[index]->list->getDate() << endl;
		cout << "-----------------------------" << endl;

		if (HashTable[index]->overflow != NULL) //if there's something in the index's overflow
		{
			keyOverFlow *temp = new keyOverFlow; //make a temp object
			temp = HashTable[index]->overflow; //to hold the values of the overflow of the index

			while (temp != NULL) //while the overflow has something in it
			{
				//print out the overflow
				cout << "Name: " << temp->itemPtr->getKey() << endl;
				cout << "Cost: " << temp->itemPtr->getCost() << endl;
				cout << "Quanity: " << temp->itemPtr->getQuantity() << endl;
				cout << "Prefered Store: " << temp->itemPtr->getStore() << endl;
				cout << "Due Date: " << temp->itemPtr->getDate() << endl;
				cout << "-----------------------------" << endl;

				temp = temp->overflow;
			}
		}
	}
}



/*~HTable(): The destructor of the class
*/
HTable::~HTable()
{

}

