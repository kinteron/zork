#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "item.h"
#include "weapon.h"
#include "includes.h"
#include "enemy.h"

#include <string>

#include <vector>
using namespace std;


static const string STORY = "wants upon a time... save this sh**\nsome guy just fell down a mountain and he wakes up in a cave-like dungeon";
static const string TRIGGER = "it looks like the keys can be combined somehow...";

class Character {

private:

    //key combination
    string keyCombination;
    int keyCount = 0;

    //char*
    string description; //player's name

    vector <Item> inventory;    //maxValue
    unsigned int lvl;   //growing int
    float health;   //calculated
    float exp;
    unsigned int attack;    //same
    Item *equipped = 0;  //reference should be accessed: pointer to 'nowhere'

    const int MAX_ITEMS = 13;    //unchangeable variable

    //intern methods

    char* printComparison(const bool comparison_between_Types); //print different things

//    bool evaluateItem(int value);

public:
    //default constructor with preset values
    Character(const string description = "hero", const int lvl = 1);
    string shortDescription() const;    //getter
    string longDescription();
    string getKeyCombination();

    void increaseHealth(const float value);   //when lvlUp()
    //getter
    Item *getInventoryAsArray() const;    //used as an array pointer to first element, later jump with pointer to next element
    vector<Item> getInventory() const;
    int getMaxItems() const;
    float getHealth() const;
    unsigned int getAttack() const;
    int getLvl() const;
    Item *getEquippedItem() const;

    //setter
    bool equipItem(Item *item = 0);     //value to equipped (pointer)
    bool equipItem(Weapon &weapon, int bonus = 0); //overloaded function

    Item *fromInventory(string name);
    //template 'overloading'
    //when enemy does action
    template <typename Type> void joust(Type attribute){    //can have a return type too
        //compare two types with eachother
        printComparison(item_t > own_t);    //his e.g. is bigger than yours
    }

    void damage(Enemy *foe);

    void setKeyCombination(string combination);

    bool addItem(const Item item);    //maybe pointer or reference    //add to inventory, not const might be changed (resetted)

//    void setMaxItems(int capacity);   //alpha version
    void setAttack(); //might be changed
    void lvlUp();   //several member-value changes

    void attackOn(Enemy * enemy);

    int countKeys();

//    Item transformName(string const name) const;//?

};

#endif //CHARACTER_H_
