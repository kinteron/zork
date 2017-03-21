#ifndef ROOM_H_
#define ROOM_H_

#include "item.h"
#include "includes.h"
#include "Command.h"

#include <map>
#include <string>
#include <vector>

using std::vector;

class Room {

private:
	string description;
    map<string, Room*> exits;   //each string points to a different room
    string exitString();        //displays exiting room
    vector <Item> itemsInRoom;
    int limit;    //for items

//    Enemy enemy;    //calls default constructor if the class uses it

public:
    int numberOfItems();
	Room(string description);
	void setExits(Room *north, Room *east, Room *south, Room *west);
	string shortDescription();
	string longDescription();
	Room* nextRoom(string direction);
    void addItem(Item *inItem);
    string displayItem();
    Item *isItemInRoom(string inString);
    void removeItemFromRoom(int location);

};

#endif
