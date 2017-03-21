#include "Character.h"

static const string STORY = "story";

inline static const string storyLine(){
    return STORY;
}

Character::Character(string description, int lvl){
    this->description = description;

    const float factor = 25.f;
    const float power = 2.f;
    //fixed values
    this->lvl = lvl;
    increaseHealth(lvl+factor);
    setAttack(lvl*factor/power);
}

void Character::addItem(Item& item) {
    if(inventory.size() < MAX_ITEMS)
        inventory.push_back(item);
}

string Character::longDescription()
{
  string ret = this->description + "\nlevel: " + to_string(lvl) + "\nhealth: " + to_string((int)health) +"\nattack: " + to_string(attack) + "\ninventory: ";
  for (vector<Item>::iterator i = inventory.begin(); i != inventory.end(); i++)
    ret += "\t"+ (*i).longDescription() + "\n";
  return ret;
}

unsigned int Character::getAttack(){
    return attack;
}

void Character::setAttack(int value){
    attack = value + equipped.getValue();
}

float Character::getHealth(){
    return health;
}

void Character::increaseHealth(float value){
    health = value / .25f;

}

vector<Item> Character::getInventory(){
    return inventory;
}

Item *Character::getEquippedItem(string name){
    for(int i = 0; i < inventory.size(); ++i){
        Item item = (Item)(inventory.at(i));
        if(item.shortDescription().compare(name) == 0)  //true?
            return &inventory.at(i);
    }
    return NULL;
}

Item Character::transformName(string name){
    for(int i = 0; i < inventory.size(); ++i){
        if((inventory.at(i)).shortDescription().compare(name) == 0){    //true?
            return inventory.at(i);
        }
    }
    return NULL;
}

bool Character::equipItem(Item *item){
    if(item!=NULL){
        equipped = *item;
        cout << item->shortDescription() + " equipped!" << endl;
        return true;
    }
    return false;
}

int Character::getLvl(){
    return lvl;
}

