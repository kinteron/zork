#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "item.h"
#include "includes.h"

#include <string>

#include <vector>
using namespace std;

class Character {

private:
	string description;

    vector <Item> inventory;    //maxValue
    unsigned int lvl;
    float health;
    unsigned int attack;
    Item equipped;

    const int MAX_ITEMS = 4;

    //intern methods
    void increaseHealth(float value);   //when lvlUp()

public:
    Character(string description = "hero", int lvl = 1);
	string shortDescription();
	string longDescription();

    //getter
    Item *getInventoryAsArray();    //used as an array pointer to first element, later jump with pointer to next element
    vector<Item> getInventory();
    int getMaxItems();
    float getHealth();
    unsigned int getAttack();
    int getLvl();
    Item* getEquippedItem(string itmName);

    //setter
    bool equipItem(Item *item);
    void addItem(Item& itmName);

//    void setMaxItems(int capacity);   //alpha version
    void setAttack(int attack);
    void lvlUp();

    Item transformName(string name);

};

#endif //CHARACTER_H_
