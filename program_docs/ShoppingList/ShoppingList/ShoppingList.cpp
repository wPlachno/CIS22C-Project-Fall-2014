/******************************************************************************
 Implemenation of ShoppingList class.

 Author: Robert Hoyer
 ******************************************************************************/

#include "ShoppingList.h"
#include <fstream>
#include <iostream>
#include <functional>

//todo: which has faster times for various actions: tree or hash table?  the one with faster time will be used for retrieval

/** Prints a ListItem's name to stdout.  Intended for use with tree traversals.
@param item The ListItem to be printed.
 */

void printItemName(ListItem& item);
{
    std::cout << item.getName() << std::endl;
}


/** Prints a ListItem to stdout if it has a specific store assigned to it.  Intended for use with tree traversals.
@param item The ListItem to be tested and possibly printed.
@param storeName The name of the store the ListItem must be assigned to to be printed.
 */

void printIfStore(ListItem& item, const std::string& storeName)
{
    if(item.getStore() == storeName)
    {
        std::cout << item.getName() << std::endl;
    }
}


ShoppingList::ShoppingList():
itemCount(itemCount),
htable(), //todo: double check if this is right for initializer lists
bstree()
{}


ShoppingList::~ShoppingList()
{}


/** Find a record in the list and return it by pointer.
@param name The name of the record to be retrieved.
@return A pointer to the found record.  Returns nullptr if the record is not found.
 */

ListItem* ShoppingList::findRecordPtr(const std::string& name)
{
    return htable.search(name); 
}


//int ShoppingList::loadFromFile(const std::string& fileName)
//{
//    std::ifstream inFile;
//
//    inFile.open(fileName);
//
//    if (!inFile.is_open())
//        return 0;
//
//    return 1;
//}
//
//
//
//int ShoppingList::writeToFile(const std::string& fileName)
//{
//    std::ofstream outFile;
//
//    outFile.open(fileName);
//
//    if (!inFile.open(fileName))
//        return 0;
//
//    return 1;
//}


/** Add a record to the list.
@param toAdd ListItem to add to the list.
@return true if the item could be added, false an item with a matching key already exists in the list.
 */

bool ShoppingList::addRecord(const ListItem& toAdd)
{
   ListItem* newItem = new ListItem(toAdd);


   //before we add to the hash table make sure that the item is unique in the bstree
   if(!bstree.insert(newItem))
        return false;
   htable.addItem(newItem);

   return true;
}


/** Remove a record from the list.
@param The name of the record to be removed.
@return true if the record was removed, false if the record could not be found.
*/


bool ShoppingList::removeRecord(const std::string& name)
{
   ListItem* toDeleteTable, *toDeleteTree;


   toDeleteTable = htable.removeItem(name);
   toDeleteTree  = bstree.remove(name);

   if (toDeleteTree && toDeleteTable)
   {
       delete toDeleteTree;
       return false;
   }
   else if(!toDeleteTree && !toDeleteTable)
        return false;
   else
   {
        // we should never get here... this means that the table and the tree are out of sync.
        assert(0); 
        //if we do get here in production, handle this as gracefully as possible.
        if(toDeleteTree)
            delete toDeleteTree;
        else
            delete toDeleteTable;

        return true; //todo: should this be true or false?  or should we throw an out of sync error
                      
   }

}


/** Finds and retrieves a record from the list.
 @param name The name of the record to be found.
 @param found Will contain the data of the found record if it is found.
 @return true if the record was found, false otherwise.
 */

bool ShoppingList::findRecord(const std::string& name, ListItem& found)
{
   ListItem* pFound = findRecordPtr(name);

   if(pFound)
   {
        found = *pFound;
        return true; 
   }
   else
        return false;

}



//print methods... separate?
//void ShoppingList::displayItem(const std::string& item)
//{
//    ListItem* found = findRecordPtr(name);
//
//    if (found)
//    {
//        //display item
//    }
//    else
//    {
//        //print error
//    }
//
//
//    return true;
//}


/** Print the list as an indented tree.
 */

void ShoppingList::printTree()
{
    bstree.printTree();
}


/** Print the list in hash key sequence to stdout.
 */

void ShoppingList::printListHashSeq() const
{
    htable.displayKeySeq();
}



/** Print the list in alphabetical order.
 */

void ShoppingList::printListByName() const
{
    tree.inorderTraversal(printItemName);
}


/** Print each record in the list that has a given store assigned to it.
@param storeName The name of the store to be searched for.
 */

void ShoppingList::printByStore(const std::string& storeName)
{
    auto visitFunc = std::bind(printIfStore, std::placeholders::_1, storeName);

    tree.inorderTraversal(visitFunc);
    //tree.breadthFirstTraversal(visitFunc);

}





