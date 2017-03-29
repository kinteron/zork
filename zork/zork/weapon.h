#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"
#include "includes.h"


class Weapon : public Item{

public:
    //default
    Weapon(string description = "fists", int inValue = 0, int durability = 100, float inWeight = .0f, string funfact = "");
    int getDurability() const;
    void setDurability(int value);
    int decreaseDurability();

private:
    int durability;
};


#endif // WEAPON_H


