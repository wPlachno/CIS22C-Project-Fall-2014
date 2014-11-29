//Created by Andrew Light
#ifndef LISTITEM_H
#define LISTITEM_H
#include <string>

class ListItem
{
	public:
		/*
				ListItem()
				Postcondition: ListItem has been initialized with default values
				NOTE: you should not use this constructor in normal operation, as the name value cannot be changed
		*/
		ListItem();
		/*
			ListItem(string n)
			Postcondition: ListItem has been initialized with name set to n
			bare minimum constructor, you should always at least have a user-set name for sorting
		*/
		ListItem(std::string n);
		/*
			ListItem(const ListItem& l)
			Postcondition: ListItem has been initialized, copied from l
		*/
		ListItem(const ListItem& l);
		/*
			ListItem(name, cost store, quantity, date)
			Postcondition: convenience constructor, ListItem has been initialized with all variables set in the order listed above
		*/
		ListItem(std::string n, double c, std::string st, int q, std::string d);
		/*
			operator<,>,>=,<=,==
			Purpose: comparison operators
			Postcondition: returns true if comparison is true, returns false if comparision is false
			note that comparisons are done with "name" and not "key" (see getKey() for details)
		*/
		bool operator<(const ListItem& right);
		bool operator>(const ListItem& right);
		bool operator>=(const ListItem& right);
		bool operator<=(const ListItem& right);
		bool operator==(const ListItem& right);
		/*
			std::string getKey()
			Postcondition: returns the "key" which is the name converted to all capital letters (to catch collisions in table, bst)
		*/
		std::string getKey();
		/*
			int compareKey
			Postcondition: returns a value < 0 if b is less than key, returns value > 0 if b is greater than key, returns 0 if b == key
		*/
		int compareKey(const std::string& b);
		/*
			operator=()
			Postcondition: this has been set equal to right
		*/
		ListItem operator=(const ListItem& right);
		/*
			getVars() and setVars() (getters and setters)
			Precondition: none, variables can be set to any value that is valid for datatype
			Postcondition: returns variable or sets variable to value provided
			Note: name cannot be modified in order to preserve ordering of BST and hashtable overflow lists, so there is no setName() function
		*/
		std::string getName();
		double getCost();
		void setCost(double d);
		std::string getStore();
		void setStore(const std::string& val);
		int getQuantity();
		void setQuantity(int val);
		std::string getDate();
		void setDate(const std::string& val);
	protected:
	private:
		std::string name;	//name cannot be modified once the object has been created, to preserve accuracy of ordering
		double cost;
		std::string store;
		int quantity;
		std::string date;
};


#endif
