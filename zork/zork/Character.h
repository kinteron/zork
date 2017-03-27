#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "item.h"
#include "weapon.h"
#include "includes.h"

#include <string>

#include <vector>
using namespace std;

class Character {

private:
    //char*
    string description; //player's name

    vector <Item> inventory;    //maxValue
    unsigned int lvl;   //growing int
    float health;   //calculated
    unsigned int attack;    //same
    Item *equipped;  //reference should be accessed: pointer to some &Item

    const int MAX_ITEMS = 4;    //unchangeable variable

    //intern methods
    void increaseHealth(const float value);   //when lvlUp()

    char* printComparison(const bool comparison_between_Types); //print different things

public:
    //default constructor with preset values
    Character(const string description = "hero", const int lvl = 1, const int attack = 0);
    string shortDescription() const;    //getter
    string longDescription();

    //getter
    Item *getInventoryAsArray() const;    //used as an array pointer to first element, later jump with pointer to next element
    vector<Item> getInventory() const;
    int getMaxItems() const;
    float getHealth() const;
    unsigned int getAttack() const;
    int getLvl() const;
    Item *getEquippedItem(const string itmName);

    //setter
    bool equipItem(Item item);     //value to equipped (pointer)
    bool equipItem(Weapon &weapon, int); //overloading function


    //template 'overloading'
    //when enemy does action
    template <typename Type> void joust(Type item_t){    //can have a return type too
        //compare two types with eachother
        printComparison(item_t > own_t);    //his e.g. is bigger than yours
    }

    void addItem(const Item item);    //maybe pointer or reference    //add to inventory, not const might be changed (resetted)

//    void setMaxItems(int capacity);   //alpha version
    void setAttack(int attack); //might be changed
    void lvlUp();   //several member-value changes

//    Item transformName(string const name) const;//?

};

#endif //CHARACTER_H_
