#ifndef ROOM_H_
#define ROOM_H_

//#include "item.h"
#include "includes.h"
#include "Command.h"
#include "item.h"
#include "enemy.h"

#include <map>
#include <string>
#include <vector>

using std::vector;

class Room {

    friend Item* mapNameToItem(string itemName);

private:
    string name;
    map<string, Room*> exits;   //each string points to a different room
    string exitString();        //displays exiting room
    vector <Item> itemsInRoom;
    int limit;    //for items
    Enemy *enemy;


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
    bool removeItemFromRoom(string itemName);
    void addEnemy(string name, int lvl);
    vector<Item> getItemsInRoom() const;
    Enemy *getEnemy() const;

};

#endif
