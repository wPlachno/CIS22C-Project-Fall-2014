#pragma once
#ifndef GROCERY_H
#define GROCERY_H
#include <string>
using namespace std;


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
        string Getid() { return id; }
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
