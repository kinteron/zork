#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Parser.h"
#include "Room.h"
#include "weapon.h"
#include <vector>
#include <cstdlib>
#include <QObject>
#include <iostream>
#include <random>

#define RAND rand()

/**
 * @brief The ZorkUL class
 * gains the 'ability' to work as a (thread)
 */

class ZorkUL : public QObject{ //in order to provide slots

    Q_OBJECT    //macro which declares its own signals and slots

private:

    const string goPrompt = "go";
    const string takePrompt = "take";
    const string equipPrompt = "equip";
    const string attackPrompt = "attack";

    //game specific variables
    vector<Room*> m_rooms;    //collect rooms and iterate over list
    //static_cast<char*>(vp);
    Item *items[20];

//  Character character;
    Parser parser;
	Room *currentRoom;


	void createRooms();
    void printWelcome();
	bool processCommand(Command command);
	void printHelp();
    void goRoom(const Command command);

    bool unique(string name, vector<Item> list, int index);    //check if it's just available once

    //generate
    void generateItems();

private slots:
    void going(const QString btnName);
    void teleport(void);
    void attack(void);
    void equip(const QString);
    void takeItem();


//    void createItems(void);
//    void displayItems(void);


public:
    ZorkUL(QObject *parent = 0);    //Threads are operating with QObjects, by default the parent is currently this class (has no parents)
    void play();    //calls game routine    //should emit the signal whenever the thread is done
	string go(string direction);
    ~ZorkUL();  //destructor    //can be called at any time

    signals:    //to trigger an event for other objects within this game/application
        void playingGame();   //as the program is staying in the loop, we could call smt
        // can call them with emit methodName


};

#endif /*ZORKUL_H_*/
