#include "Room.h"

Room::Room(string description){
    //calls Item
    this->name = description;

}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
	if (north != NULL)
        exits["north"] = north;
	if (east != NULL)
		exits["east"] = east;
	if (south != NULL)
		exits["south"] = south;
	if (west != NULL)
		exits["west"] = west;
}

void Room::addEnemy(int lvl){
    //current used enemy
    float factor = 2.f;
    enemy = new Enemy("fleaman", 20, 8.f);
    float attack =lvl*enemy->getAttack() / factor / GAME_FACTOR;
    int health = (int)(lvl*enemy->getHealth()/factor / GAME_FACTOR);
    enemy->setHealth(health);
    enemy->setAttack(attack);
//    this->enemy = &e;   //will loose enemy reference after method }
}

Enemy *Room::getEnemy() const{
    return this->enemy;
}

string Room::shortDescription() {
    return name;
}

string Room::longDescription() {
    return "room = " + shortDescription() + ".\n" + displayItem() + exitString();
}

string Room::exitString() {
	string returnString = "\nexits =";
	for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
		// Loop through map
		returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
	return returnString;
}

Room* Room::nextRoom(string direction) {
	map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
		return NULL; // if exits.end() was returned, there's no room in that direction.
	return next->second; // If there is a room, remove the "second" (Room*)
				// part of the "pair" (<string, Room*>) and return it.
}

void Room::addItem(Item *inItem) {
    itemsInRoom.push_back(*inItem);
}

string Room::displayItem() {
    string tempString = "items in room = ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
            tempString = "no items in room "  + this->shortDescription();
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + itemsInRoom[x].shortDescription() + ";  " ;
            x++;
            }
        }
    return tempString;
    }

int Room::numberOfItems() {
    return itemsInRoom.size();
}

bool Room::removeItemFromRoom(string itemName){
    for (vector<Item>::iterator i = itemsInRoom.begin(); i != itemsInRoom.end(); ++i){
        Item item = ((Item )*i);    //iterator points to object
        if(item.shortDescription().compare(itemName) == 0){
            itemsInRoom.erase(i);
            return true;
        }
    }
    return false;
}

vector<Item> Room::getItemsInRoom() const{
    return this->itemsInRoom;
}

Item* Room::isItemInRoom(string inString)
{
    for(int i = 0; i < itemsInRoom.size(); ++i){
        if(inString.compare(itemsInRoom.at(i).shortDescription()) == 0){
            return &itemsInRoom[i];
        }
    }
    cout << "item is not in room" << endl;
    return NULL;
}

