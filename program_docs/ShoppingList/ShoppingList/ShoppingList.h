
#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include <string>
#include "ListItem.h"
#include "BSTree.h"
#include "HashTable.h"

class ShoppingList
{

private:
    int itemCount;
    BSTree bstree;
    HashTable htable;


    //std::string fileName; //in a gui app this would be a better configuration


    ListItem* findRecordPtr(const std::string& name);
public:
    ShoppingList();
    ~ShoppingList();

    // bool setFileName(const std::string& newFileName);
    // std::string getFileName();
    //int loadFromFile();//const std::string& fileName);
    //int writeToFile();//const std::string& fileName);

    int loadFromFile(const std::string& fileName);
    int writeToFile(const std::string& fileName);


    int addRecord(const ListItem& listItem); //copy the data into a new allocated item
    int removeRecord(const std::string& name);
    ListItem findRecord(const std::string& name) const; //this might change


    //print methods... separate?
    void displayItem(const std::string& item) const;
    void printTree() const;
    void printListHashSeq() const;
    void printListByName() const;

    //group defiined
    void printByStore(const std::string& storeName);



};




#endif
