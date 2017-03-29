#include "item.h"


Item::Item(string inDescription, int inValue, float inWeightKG, string funfact){
//    assert(inValue > 0);
    setWeight(inWeightKG);
    setValue(inValue);
    description = inDescription;
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
    value = inValue;
}

string Item::shortDescription()
{
    return description;
}

int Item::getValue(){
    return value;
}

string Item::longDescription()
{

    short mask = -1;    //all bits are 1
    mask<<=8;           //filled with 8x0s from << (right to left)
    mask = ~mask;       //turn 0->1 and 1->0

    //mask is 255dec // shiftleft is nothing less than multiplying by 2

    short w = (short)getWeight();
    float weight = getWeight() - w;
    weight*=100.f;
    short eight = (short)weight;

    //extend to float
    return "value " + to_string(getValue()) + "\nweight " + to_string(w) + "," + to_string(eight) + " kg\n" + getFunfact();

}

Item Item::operator=(Item other){

    value = other.value;
    setWeight(other.weightKG);
//    longDescription = strcpy(new char [strlen(other.longDescription) + 1], other.longDescription;
//    description = strcpy(new char[strlen(other.description)+1], other.description);
//    durability = other.durability;
    return *this;
}

string Item::getFunfact() const{
    return this->funfact;
}

bool Item::operator!=(Item& other){
    return description.compare(other.description) == 0;
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
