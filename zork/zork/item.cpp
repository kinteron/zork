#include "item.h"


Item::Item (string inDescription, int inValue, float inWeightKG, string funfact){
//    assert(inValue > 0);
    description = inDescription;
    setWeight(inWeightKG);
    setValue(inValue);
    this->funfact = funfact;
}

void Item::setWeight(float inWeightKG)
{
    if (inWeightKG > 9999.f || inWeightKG < .0f)
       cout << "weight invalid, must be 0<weight<9999" ;
    else
       weightKG = inWeightKG;
}

float Item::getWeight(){
    return weightKG;
}

void Item::setValue(int inValue)
{
    if (inValue > 9999 || inValue < -4)
       cout << "value invalid, must be 0<value<9999" ;
    else
       value = inValue;
}

string Item::shortDescription()
{
    return description;
}

string Item::longDescription()
{
    string weight = to_string(weightKG);
    string val = to_string(value);
    return description + "\nvalue: " + val + "\nweight: " + weight + "\n" + funfact;
}

int Item::getValue(){
    return value;
}

Item& Item::operator=(Item& other){
//    if(weapon1.getWeaponCheck())  //should be handled in assigning-method
//        return;
    value = other.getValue();
    setWeight(other.getWeight());
//    longDescription = strcpy(new char [strlen(other.longDescription) + 1], other.longDescription;
//    description = strcpy(new char[strlen(other.description)+1], other.description);
//    durability = other.durability;
    return *this;
}

bool Item::operator!=(Item& other){
    return description.compare(other.description);
}

//Item &operator+(const Item& other){

//    durability = other.getDurability() * rand()+1;  //assures that, the crafted weapon has at least the durability of 1
//    attackValue = other.attackValue;
//    int randomLength = rand()*getShortDescription().length();
//    int randomStart = rand()*other.getShortDescription().length();
//    string combination = append(description.substr(0,randomLength), other.description.substr(randomStart, other.description.length()));
//    strcpy(description, combination); //saves second argument to first string

//    string longi = substr(other.description.length(), other.longDescription.length());
//    strcpy(longi, append(description, longi));
//    strcpy(longDescription, longi);  //copied description 1 + 2
//}
