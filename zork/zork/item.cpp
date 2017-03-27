#include "item.h"


Item::Item(string inDescription, int inValue, float inWeightKG, string funfact){
//    assert(inValue > 0);
    setWeight(inWeightKG);
    setValue(inValue);
    penis = inDescription;
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
    return penis;
}

int Item::getValue(){
    return value;
}

string Item::longDescription()
{
    string weight = to_string(weightKG);
    string val = to_string(value);
    return penis + "\nvalue: " + val + "\nweight: " + weight + "\n" + funfact;
}

Item& Item::operator=(Item& other){

    value = other.value;
    setWeight(other.weightKG);
//    longDescription = strcpy(new char [strlen(other.longDescription) + 1], other.longDescription;
//    description = strcpy(new char[strlen(other.description)+1], other.description);
//    durability = other.durability;
    return *this;
}

bool Item::operator!=(Item& other){
    return penis.compare(other.penis) == 0;
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
