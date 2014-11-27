
#include <iostream>
#include <string>
#include <vector>
#include "HashTable.h"
#include "ListItem.h"


Hashing::Hashing()
{


	for (int i = 0; i < tableSize; i++) //runs through the hash table
	{//D.A. all indexes of the hash table
		HashTable[i] = new item;
		
		HashTable[i]->next = NULL; //what it points to for the next item.
	}
}

/*hashFcn(): Function that will take in a string value named key
and changing it to an int and then set it to the remainder of the 
 converted string (hash) divided by the size of the table  
(The remainder is the index)
*/
int Hashing::hashFcn(const std::string& key, const ListItem* newItem)
{
	int hash = 0; //the converted string into int (using ASCII)
	int index; //index of the key

	index = key.length(); //gives index a value


	for(int count = 0; count < key.length(); count++)
	{
		hash = hash + (int)key[count]; //(int)key converts the characters of the string into ASCII
	}

	index = hash % tableSize; //making the index

	listKey *keys;

	//create the first node in the list if none exists yet;
	if (empty(keys->start))//if there's nothing in the list,
	{
		//create the first node
		firstNode(index);
	}
	//if it isn't empty, it should just skip the first if statement a start comparing
	//compare with the linked list
	else if (searchList(keys->start, index))
	{
		keyOverFlow *flow = new keyOverFlow;

		//retrieve the first occurrence from the table
		flow = HashTable[index]->overflow; //and add the second key occurrence to the overflow list
	}

		return index;
}

/*search(): This function takes in a value (the name of an item)
and search the hash table for it. If the item was found, the function
will print out that the item was found.
Else, if it wasn't found, the function simply states that the item wasn't
found in the hash table.
*/
item *Hashing::search(std::string name)
{
	const ListItem *temp;
	int index = hashFcn(name, temp); //finds the hash value of that particular name and sets index equal to it

	bool found = false; //bool for if found/if not found
	//string product;

	item *tablePtr = HashTable[index]; //create a pointer to the hash table

	while (tablePtr != NULL) //go through the table as long as there is an item
	{
		if (tablePtr->list->getName() == name)//if the pointer is pointing at the name that is equal to the string passsed to it,
		{
			found = true; //it has been found
			//product = tablePtr->ID;
		}
		tablePtr = tablePtr->next; //moves to the next item to check
	}
	if (found) //if the item was found.
	{

		return tablePtr;

	}
	else//if it wasn't found
	{
		std::cout << "Item " << name << " was not found." << std::endl;
		
		return NULL;
	}

}


/*addItem(): Function that will take in 6 strings (ID, name, cost, quanity, store and dueDate)
and use these strings to add a new item/ element into the hash table or write over an existing
item with the same index. This will probably need to get changed to use the collision requirements instead.
*/
void Hashing::addItem(ListItem* newItem)
{
	int index = hashFcn(newItem->getName(), newItem); //Index will be set to the hashed value of the ID (ID is being used as the key here)


	//Info Check!
	
	if (search(HashTable[index]->list->getName()) != NULL )//if the item at the index can be found in the table already,
	{
		//then it's a duplicate of the same item
		
		//don't add it again
		std::cout << "This item already exists" << std::endl;

	}
	else //if the item wasn't found in the table...
	{//add a new item


		//add to the hash table
		item* tablePtr = HashTable[index];
		item* newPtr = new item; //points to a new item to place the info

		//set the double and int values for assignment
		double Dtemp = newPtr->list->getCost();
		int Itemp = newPtr->list->getQuantity();

		//pass the new info to the new item with newPtr
		newPtr->list->getName() = newItem->getName();
		Dtemp = newItem->getCost();   //setting up the double and int values before assignment seemed to have fixed the error...
		Itemp = newItem->getQuantity(); 
		newPtr->list->getStore() = newItem->getStore();
		newPtr->list->getDate() = newItem->getDate();

		newPtr->next = NULL; //next one has a pointer pointing to nothing

		//Now we need to add the new item to the end of the table
		while (tablePtr->next->list != NULL)//while the next pointer in the hash table isn't pointing to nothing,
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
item* Hashing::removeItem(const std::string name)
{
	const ListItem *temp;
	int index = hashFcn(name, temp); //set the index equal to the hash value of the name

	item* remPtr; //removePointer
	item* itemPtr1;
	item* itemPtr2;

	//If the index is empty
	if (HashTable[index]->list->getName() == dfS) //if the name in hash table index is the default one (means nothing is there)
	{
		std::cout << "Item was not found." << std::endl;
	}

	//Index only contains 1 item and and it has a matching name
	else if (HashTable[index]->list->getName() == name && HashTable[index]->next == NULL) //if the name in the hash table matchs the name passed to the function AND there is not next item,
	{
		
		HashTable[index]->list == NULL; //removes the item from the list
		

		std::cout << "Removal was successful." << std::endl;
	}

	//The match is located in the first item in the index but there are more items in the index

	else if (HashTable[index]->list->getName() == name) //Last 'if' checked to see if the next item was nothing so this 'if' is designed to already assume that
	{										//the index has nore than one item in it.
		remPtr = HashTable[index]; //have remPtr point to that particular index of the hash table
		HashTable[index] = HashTable[index]->next; //And then have HashTable[index] actually be the next item in the list

		delete remPtr; //removes the index from the hashtable

		std::cout << "Removal was successful." << std::endl;

	}

	//Index contains items but the first item doesn't match
	else
	{
		itemPtr1 = HashTable[index]->next; //Make the first pointer point to the second item in the index. (Becasue from the other 'ifs', we can assume that there is more than one item)
		itemPtr2 = HashTable[index]; //Make the second pointer point to the first item in the index

		while (itemPtr1 != NULL && itemPtr1->list->getName() != name) //while itemPtr1 has something and that something doesn't equal the name that was passed to the function
		{//move both pointers along the index list
			itemPtr2 = itemPtr1;
			itemPtr1 = itemPtr1->next;
			//is is just to step through the entire list of the index to look though everything for a match
		}

		//if it wasn't found,
		if (itemPtr1 == NULL)
		{
			std::cout << "Item was not found." << std::endl;
		}

		//if it was found
		else
		{
			//remove the info
			remPtr = itemPtr1;
			itemPtr1 = itemPtr1->next;
			itemPtr2->next = itemPtr1;

			delete remPtr;

			std::cout << "Removal was successful." << std::endl;
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
	if (HashTable[index]->list->getName() == dfS) //If the first item is just a default form,
	{
		return count; //returns nothing (zero; nothing has been set to that index yet)
	}
	else
	{
		count++;
		item* tablePtr = HashTable[index]; //points to the first item in the index

		while (tablePtr->next->list != NULL)//while the next item in the index is not nothing,
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
		std::cout << "index: " << i << std::endl;
		std::cout << "Name: " << HashTable[i]->list->getName() << std::endl;
		std::cout << "Cost: " << HashTable[i]->list->getCost() << std::endl;
		std::cout << "Quanity: " << HashTable[i]->list->getQuantity() << std::endl;
		std::cout << "Prefered Store: " << HashTable[i]->list->getStore() << std::endl;
		std::cout << "Due Date: " << HashTable[i]->list->getDate() << std::endl;

	} 
}

/*displayItems(): Displays only the items in a particular index.
*/
void Hashing::displayItems(int index)
{
	item* tablePtr = HashTable[index]; //points to the index of hash table

	if (tablePtr->list->getName() == dfS) //check to see if the index is empty (default),
	{ //This method assumes that only name needs to change to be considered not empty, may need to come back to fix this 
		std::cout << "Info for index: " << index << std::endl;
		std::cout << "This index is empty" << std::endl;
	}
	else
	{
		std::cout << "Info for index: " << index << std::endl;

		while (tablePtr != NULL) //While the index does have something
		{

			std::cout << "Name: " << tablePtr->list->getName() << std::endl;
			std::cout << "Cost: " << tablePtr->list->getCost() << std::endl;
			std::cout << "Quanity: " << tablePtr->list->getQuantity() << std::endl;
			std::cout << "Prefered Store: " << tablePtr->list->getStore() << std::endl;
			std::cout << "Due Date: " << tablePtr->list->getDate() << std::endl;

			tablePtr = tablePtr->next;//points to the next item
		}
	}
}

