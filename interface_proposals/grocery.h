#pragma once
#ifndef GROCERY_H
#define GROCERY_H
#include <string>
using namespace std; //rhoyer - should we be doing this?    AL- lazy implementation, so i don't have to deal with going std::string a bunch, will modify later
//rhoyer - string params should be const references
//rhoyer - string params should be const references AL- noted
//rhoyer - have a method getkey that's a wrapper for name
class grocery //rwh243 - change to ListItem
{
public:
    //add convenience constructor, comparison operators (based on key)
    grocery();
    virtual ~grocery();
    string Getname() { return name; }
    void Setname(const string& val) { name = val; }
    double Getcost() { return cost; }
    void Setcost(double val) { cost = val; }
    string Getstore() { return store; }
    void Setstore(const string& val) { store = val; }
    int Getquantity() { return quantity; }
    void Setquantity(int val) { quantity = val; }
    string Getdate() { return date; }
    void Setdate(const string& val) { date = val; }
    string Getid() { return id; } //rhoyer - id is name AL- noted, will remove
    void Setid(string val) { id = val; } 
protected:
private:
    string name;
    double cost;
    string store;
    int quantity;
    string date;
    string id;
};

#endif // GROCERY_H
