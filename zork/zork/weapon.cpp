#include "weapon.h"
#include "item.h"


Weapon::Weapon(string inDescription, int inValue, int durability, float inWeight, string funfact):Item(inDescription, inValue, inWeight, funfact){  //healing items{
    this->durability = durability;
}

int Weapon::getDurability() const
{
    return durability;
}

void Weapon::setDurability(int value)
{
    durability = value;
}

int Weapon::decreaseDurability(){
    return durability--;
}
