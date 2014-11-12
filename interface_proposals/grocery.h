#pragma once
#ifndef GROCERY_H
#define GROCERY_H
#include <string>
using namespace std; //rhoyer - should we be doing this?    AL- lazy implementation, so i don't have to deal with going std::string a bunch, will modify later
//rhoyer - why are there implementations in the header?  Are these the implementations you plan on useing? AL- not in the slightest, they're just for testing purposes
//rhoyer - use const in functions and params
//rhoyer - string params should be const references
//rhoyer - should this be named grocery? 
//rhoyer - string params should be const references AL- noted

class grocery
{
public:
    grocery();
    virtual ~grocery();
    string Getname() { return name; }
    void Setname(string val) { name = val; }
    double Getcost() { return cost; }
    void Setcost(double val) { cost = val; }
    string Getstore() { return store; }
    void Setstore(string val) { store = val; }
    int Getquantity() { return quantity; }
    void Setquantity(int val) { quantity = val; }
    string Getdate() { return date; }
    void Setdate(string val) { date = val; }
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
