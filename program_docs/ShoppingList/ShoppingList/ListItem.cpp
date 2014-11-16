
#include "ListItem.h"

ListItem::ListItem(){
	name = "EMPTY OBJECT";
	cost = -1;
	store = "EMPTY OBJECT";
	quantity = -1;
	date = "EMPTY OBJECT";
}
ListItem::ListItem(string n){
	name = n;
	cost = -1;
	store = "EMPTY STORE";
	quantity = -1;
	date = "EMPTY DATE";
}
ListItem::ListItem(const ListItem& l){
	name = l.name;
	cost = l.cost;
	store = l.store;
	quantity = l.quantity;
	date = l.date;
}
ListItem::ListItem(string n, double c, string st, int q, string d){
	name = n;
	cost = c;
	store = st;
	quantity = q;
	date = d;
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
string ListItem::getName(){
	return name;
}
double ListItem::getCost(){
	return cost;
}
void ListItem::setCost(double d){
	cost = d;
}
string ListItem::getStore(){
	return store;
}
void ListItem::setStore(const string& val){
	store = val;
}
int ListItem::getQuantity(){
	return quantity;
}
void ListItem::setQuantity(int val){
	quantity = val;
}
string ListItem::getDate(){
	return date;
}
void ListItem::setDate(const string& val){
	date = val;
}
ListItem::~ListItem()
{
}