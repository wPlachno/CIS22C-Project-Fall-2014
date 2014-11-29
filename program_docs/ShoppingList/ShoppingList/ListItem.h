//Created by Andrew Light
#ifndef LISTITEM_H
#define LISTITEM_H
#include <string>
using namespace std;
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
		ListItem(string n);
		/*
			ListItem(const ListItem& l)
			Postcondition: ListItem has been initialized, copied from l
		*/
		ListItem(const ListItem& l);
		/*
			ListItem(name, cost store, quantity, date)
			Postcondition: convenience constructor, ListItem has been initialized with all variables set in the order listed above
		*/
		ListItem(string n, double c, string st, int q, string d);
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
			string getKey()
			Postcondition: returns the "key" which is the name converted to all capital letters (to catch collisions in table, bst)
		*/
		string getKey();
		/*
			int compareKey
			Postcondition: returns a value < 0 if b is less than key, returns value > 0 if b is greater than key, returns 0 if b == key
		*/
		int compareKey(const string& b);
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
		string getName();
		double getCost();
		void setCost(double d);
		string getStore();
		void setStore(const string& val);
		int getQuantity();
		void setQuantity(int val);
		string getDate();
		void setDate(const string& val);
	protected:
	private:
		string name;	//name cannot be modified once the object has been created, to preserve accuracy of ordering
		double cost;
		string store;
		int quantity;
		string date;
};


#endif
