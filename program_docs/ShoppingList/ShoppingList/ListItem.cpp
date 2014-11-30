//created by Andrew Light
#include "ListItem.h"

ListItem::ListItem(){
	name = "EMPTY OBJECT";
	cost = -1;
	store = "EMPTY OBJECT";
	quantity = -1;
	date = "EMPTY OBJECT";
}
ListItem::ListItem(std::string n){
	name = n;
	cost = -1;
	store = "EMPTY STORE";
	quantity = 1;
	date = "EMPTY DATE";
}
ListItem::ListItem(const ListItem& l){
	name = l.name;
	cost = l.cost;
	store = l.store;
	quantity = l.quantity;
	date = l.date;
}
ListItem::ListItem(std::string n, double c, std::string st, int q, std::string d){
	name = n;
	if(c <= 0) cost = -1
	else cost = c;
	if(st == "_") store = "EMPTY STORE";
	else store = st;
	if(q <= 0) quantity = 1;
	else quantity = q;
	if(d == "_") date = "EMPTY DATE"
	else date = d;
}
bool ListItem::operator<(const ListItem& right){
	if (name < right.name) return true;
	return false;
}
bool ListItem::operator>(const ListItem& right){
	if (name > right.name) return true;
	return false;
}
bool ListItem::operator>=(const ListItem& right){
	if (*this > right || (name == right.name)) return true;
	return false;
}
bool ListItem::operator<=(const ListItem& right){
	if (*this < right || name == right.name) return true;
	return false;
}
bool ListItem::operator==(const ListItem& right){
	if (name == right.name && cost == right.cost && store == right.store && quantity == right.quantity && date == right.date) return true;
	return false;
}
ListItem ListItem::operator=(const ListItem& right){
	name = right.name;
	cost = right.cost;
	store = right.store;
	quantity = right.quantity;
	date = right.date;
	return *this;
}
std::string ListItem::getName(){
	return name;
}
double ListItem::getCost(){
	return cost;
}
void ListItem::setCost(double d){	//if there is a negative cost, cost is set to the error value of -1
	if (d <= 0) cost = -1;
	else cost = d;
}
std::string ListItem::getStore(){
	return store;
}
void ListItem::setStore(const std::string& val){
	if (val == "_") store = "EMPTY STORE";
	else store = val;
}
int ListItem::getQuantity(){
	return quantity;
}
void ListItem::setQuantity(int val){	//you will always want at least one of an object
	if (val <= 0) quantity = 1;
	else quantity = val;
}
std::string ListItem::getDate(){
	return date;
}
void ListItem::setDate(const std::string& val){
	if (val == "_") date = "EMPTY DATE";
	else date = val;
}
std::string ListItem::getKey(){
	std::string tmp = "";
	for (int i = 0; i < name.length(); i++){
		tmp += toupper(name[i]);	//converts all characters in name to uppercase
	}
	return tmp;	//returns uppercase version of name
}
int ListItem::compareKey(const std::string& b){
	std::string tmp = "";
	for (int i = 0; i < b.length(); i++){	//converting second key to uppercase, ensuring that the keys are properly compared
		tmp += toupper(b[i]);
	}
	return getKey().compare(tmp);
}
