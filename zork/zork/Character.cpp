#include "Character.h"

inline static const string storyLine(){
    return STORY;
}

Character::Character(const string description, int const lvl){
    this->description = description;
    this->lvl = lvl;
    setAttack();
    health = GAME_FACTOR*lvl*100;
}

bool Character::addItem(const Item item){
    if(inventory.size() < MAX_ITEMS){
        inventory.push_back(item);
        return true;
    }
    return false;
}

string Character::shortDescription() const {
    return description;
}

int Character::countKeys(){
    return ++keyCount;
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

void Character::attackOn(Enemy *enemy){
    //quick and dirty

    int damage;
    if(enemy->getHealth() <= 0 ){   //feature calculations
        damage = 0;
        enemy->~Enemy();
        enemy = NULL;
    } else{
        damage = enemy->getHealth()-getAttack();
        enemy->setHealth(damage);
    }
}

void Character::setAttack(){
    if(equipped == NULL){
        attack = 6;
        return;
    }
    const float power = GAME_FACTOR * lvl / 0.2f * lvl;
    //fixed values
    attack = equipped->getValue() + power;
}

float Character::getHealth() const{
    return health;
}

void Character::increaseHealth(float value){
    value = GAME_FACTOR * value / 100.f;
    health += value / GAME_FACTOR;
}

void Character::decreaseHealth(float value){
    health -= value;
}

vector<Item> Character::getInventory() const{
    return inventory;
}

Item *Character::getEquippedItem() const{
    return this->equipped;
}

//Item *Character::transformName(const string name) const{
//    for(int i = 0; i < inventory.size(); ++i){
//        if(((Item&)inventory.at(i)).shortDescription().compare(name) == 0){    //true?
//            return inventory[i];
//        }
//    }
//    return std::nullptr_t;    //also 0
//}

bool Character::equipItem(Item *item){  //is an alias for the value that comes in, so if a pointer holds the adress of a value, then it is changed
    const Item * ptr = item;
    if(ptr != NULL){
        equipped = item;    //gets lost?
        setAttack();
        return true;
    }

    return false;
}

void Character::setKeyCombination(string combination){
    //careful cheat!
    this->keyCombination = combination;
}

string Character::getKeyCombination(){
    return this->keyCombination;
}

Item *Character::checkCombination(string combination){
    if(keyCombination.compare(combination)){   //trimming would be nice
        return &Item("master-key", -5, 1.f, "good luck!");
    }
    return 0;
}

Item *Character::fromInventory(string name){
    for(int i = 0; i < inventory.size(); ++i){
        Item *it = &(inventory.at(i));
        if(it->shortDescription().compare(name) == 0){
            return it;
        }
    }
    return 0;
}

Character::~Character(){
    delete equipped;
}

//overloaded
bool Character::equipItem(Weapon &weapon, int bonus){
    return equipItem(&weapon);
}

int Character::getLvl() const{
    return lvl;
}

