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

void Room::addEnemy(){
    Enemy e("fleaman", 20.f, 8);
    this->enemy = &e;
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
        tempString = "no items in room";
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + itemsInRoom[x].shortDescription() + "  " ;
            x++;
            }
        }
    return tempString;
    }

int Room::numberOfItems() {
    return itemsInRoom.size();
}

void Room::removeItemFromRoom(){
    itemsInRoom.clear();
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

