#ifndef ITEM_H_
#define ITEM_H_

#include "includes.h"

#include <map>
#include <string>
#include <iostream>

using namespace std;

class Item {

    //any assignment operator has to be a member function
    //breaks the convention of encapsulation

    friend Item &operator+(const Item& weapon1, const Item& weapon2);

private:
    string description; //stack no delete
    string funfact;

    float weightKG;
    int value;    //used for healing items



public:

    //default

    Item(string description = "empty", int inValue = 0, float inWeight = .001f, string funfact = "");  //healing items
    //healing stuff

    string shortDescription();
    string longDescription();

    float getWeight();
    void setWeight(float weightKG);
    int getValue();
    void setValue(int value);


    //operator overloading
    Item &operator=(Item& other);
    bool operator!=(Item& two);

};

#endif /*ITEM_H_*/
