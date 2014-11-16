//ListItem interface, there will always be at least these functions so code using them, and let me know if i need more

#ifndef LISTITEM_H
#define LISTITEM_H
#include <string>
using namespace std;
class ListItem
{
	public:
		//add convenience constructor, comparison operators (based on key)
		ListItem();
		ListItem(string n);	//bare minimum constructor, you should always at least have a user-set name for sorting
		ListItem(const ListItem& l);
		ListItem(string n, double c, string st, int q, string d);
		bool operator<(const ListItem& right);
		bool operator>(const ListItem& right);
		bool operator>=(const ListItem& right);
		bool operator<=(const ListItem& right);
		bool operator==(const ListItem& right);
		ListItem operator=(const ListItem& right);
		virtual ~ListItem();
		string getName();	//anyone think any of the variables need to be safed?
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
		double cost;	//also, the name is the key value, so nicci use getName for your hash function i suppose
		string store;
		int quantity;
		string date;
};


#endif