#include "Character.h"

static const string STORY = "story";

inline static const string storyLine(){
    return STORY;
}

Character::Character(const string description, int const lvl, const int attack){

    this->description = description;
    const float factor = 25.f;
    const float power = 2.f;
    //fixed values
    this->lvl = lvl;
    increaseHealth(lvl+factor);
    this->attack = attack;
}

void Character::addItem(const Item item){
    if(inventory.size() < MAX_ITEMS)
        inventory.push_back(item);
}

string Character::shortDescription() const {
    return description;
}

string Character::longDescription()
{
  string name = shortDescription();
  cout << name;
  string ret = "\nlevel: " + to_string(lvl) + "\nhealth: " + to_string((int)health) +"\nattack: " + to_string(attack) + "\ninventory: ";
  for (vector<Item>::iterator i = inventory.begin(); i != inventory.end(); i++)
    ret += (*i).shortDescription() + "\t";
  ret += "\n";
  return ret;
}

unsigned int Character::getAttack() const{
    return attack;
}

void Character::setAttack(int value){
    attack = value + equipped->getValue();
}

float Character::getHealth() const{
    return health;
}

void Character::increaseHealth(float value){
    health = value / .25f;

}

vector<Item> Character::getInventory() const{
    return inventory;
}

Item *Character::getEquippedItem(const string name){
    for(int i = 0; i < inventory.size(); ++i){
        Item item = (Item)(inventory.at(i));
        if(item.shortDescription().compare(name) == 0)  //true?
            return &inventory.at(i);
    }
    return &inventory[0];
}

//Item *Character::transformName(const string name) const{
//    for(int i = 0; i < inventory.size(); ++i){
//        if(((Item&)inventory.at(i)).shortDescription().compare(name) == 0){    //true?
//            return inventory[i];
//        }
//    }
//    return std::nullptr_t;    //also 0
//}

bool Character::equipItem(Item item){  //is an alias for the value that comes in, so if a pointer holds the adress of a value, then it is changed
    const Item * ptr = &item;
    if(ptr != NULL){
        equipped = &item;
        cout << item.shortDescription() + " equipped!" << endl;
        return true;
    }

    return false;
}

//overloaded
bool Character::equipItem(Weapon &weapon, int bonus){
    return equipItem(weapon);

}

int Character::getLvl() const{
    return lvl;
}

