
#include <string>

//temporary
class BSTree;
class HTable;
class ListItem;

class ShoppingList
{
private:
	int itemCount;
	BSTree* tree;
	HTable* table; 


	//std::string fileName; //in a gui app this would be a better configuration


	ListItem* findItemPtr(const std::string& name); //this could be public for update commands
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
	ListItem findRecord(const std::string& name);


	//print methods... separate?
	bool displayItem(const std::string& item);	
	void printTree(); 
	void printListHashSeq();
	void printListByName();

	//group defiined
	void printByStore(const std::string& storeName);

};

