#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Room.h"
#include "parser.h"
#include "weapon.h"
#include "Character.h"
#include <vector>
#include <cstdlib>
#include <QObject>
#include <random>

using namespace std;

#define RAND rand()

/**
 * @brief The ZorkUL class
 * gains the 'ability' to work as a (thread)
 */
class ZorkUL : public QObject{ //in order to provide slots

    Q_OBJECT    //macro which declares its own signals and slots

    static const int itemArraySize = 22;

private:

    const string goPrompt = "go";
    const string takePrompt = "take";
    const string equipPrompt = "equip";
    const string attackPrompt = "attack";

//    //game specific variables
    vector<Room*> m_rooms;    //collect rooms and iterate over list
//    //static_cast<char*>(vp);
    Item *items[itemArraySize];

    Character *character;   //pointing to a new reference
    Parser parser;
    Room *currentRoom;  //points to a room


    void createRooms();

    bool processCommand(Command &command);
    void goRoom(const Command command);
    void printHelp();
    void spawnEnemy();

public:

    void printWelcome();


    bool unique(string name, vector<Item*> list, int index);    //check if it's just available once

//    //generate
    void generateItems();

private slots:
    void going(const QString btnName);
    void teleport(void);
//    void attack(void);
//    void equip(const QString);
    void takeItem();

//    void createItems(void);
//    void displayItems(void);


public:
    ZorkUL(QObject *parent = 0);    //Threads are operating with QObjects, by default the parent is currently this class (has no parents)
//    void play();    //calls game routine    //should emit the signal whenever the thread is done
//	string go(string direction);
    ~ZorkUL();  //destructor    //can be called at any time

//    signals:    //to trigger an event for other objects within this game/application
//        void playingGame();   //as the program is staying in the loop, we could call smt
//        // can call them with emit methodName


};

#endif /*ZORKUL_H_*/
