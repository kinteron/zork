#include "ZorkUL.h"
/**
 * http://en.cppreference.com/w/cpp/numeric/random
 * random()
 */


ZorkUL::ZorkUL(QObject *parent)     //called by MainThread
    : QObject(parent), character(new Character("Alfred", 1, 0)){  //like super() call

    createRooms();
    generateItems();
}


ZorkUL::~ZorkUL(){
//    delete items;
    cout << "zorkUl destructor is called" << endl;
}

bool ZorkUL::unique(string name, vector<Item*> list, int index){
    int size = index;
    for(int i = 0; i < size; ++i){
        if(name.compare(list.at(i)->shortDescription()) == 0){
            return false;
        }
    }
    return true;
}

bool ZorkUL::isEnemyPresent() const{
    return true;
}

QString ZorkUL::getCurrentRoomText() const{
    string s = "Room " + currentRoom->shortDescription();
    return QString(s.c_str());
}

QString ZorkUL::getEnemyDescription() const{
    if(isEnemyPresent())
    return QString(currentRoom->getEnemy()->longDescription().c_str());
}

//saves stack pushes due to inline
inline int random(int const start, int const end){  //const not allowed
    std::random_device r;
    std::default_random_engine engine(r());
    std::uniform_int_distribution<int> uniform_dist(start, end);
    int mean = uniform_dist(engine);
    return mean;
}

void ZorkUL::generateItems(){
    //create item list
    //add items to rooms

    vector<Item *> tempList;

    /*
     * because strings are char*
     * the pointer will be destroyed on the stack after this scope
     * so description is pointing to nowhere and we lose access to the string
     * int and float values are copied in the constructor call
     * don't forget to delete[] items
     *
     */
    //weapons       //allocates strings on heap
    items[0] = new Weapon("feather", 1, 999);
    items[1] = new Weapon("beater", 30, 999, 2.8f);
    items[2] = new Weapon("stick", 15, 999, 1.f, "it's a heavy stick");
    items[3] = new Weapon("hammer", 20, 999, 1.4f, "maybe to fix the doors");
    items[4] = new Weapon("iron-fist", 40, 50, 6.2f, "if it hits you it'll probably hurt");
    items[5] = new Weapon("claymore", 55, 40, 12.4f, "a beautiful sword");
    items[14] = new Weapon("crowbar", 15, 999, 3.4f, "that hurts"); //das zwiebelt
    items[15] = new Weapon("selfmade weapon", 25, 30, 8.3f, "whoever created this weapon, he's a fucking genius putting a rock and a chain together");
    items[16] = new Weapon("terminator 9999", 99, 5, 55.56f, "where did you find this murderous weapon?\nthe enemy which can withstand THIS weapon has to be born yet\nyou can beat the endboss like nothing\ngood lu... just win!");

    //normal items
    items[6] = new Item("old wrinkled book");
    items[7] = new Item("toothbrush", 0, .05f, "you should use it though");
    items[8] = new Item("slime");
    items[9] = new Item("toiletpaper", 1, 0.01f, "seriously?");
    items[10] = new Item("lighter", 2, .01f);
    items[11] = new Item("dead mouse", 1, 1.f, "I could maybe... no!");
    items[12] = new Item("useless dil**, WTF...");
    items[13] = new Item("sketches", 0, 0.3f, "they look really nice...\nooh, look at this!");

    //keys
    items[17] = new Item("key-1", -1, .0f, "you need 3 of those");
    items[18] = new Item("key-2", -2, .0f, "you need 3 of those");
    items[19] = new Item("master-key", -3, .0f, "just kidding!\nyou still need all three to get to enter the top floor");
    items[20] = new Item("small potion", 10, 0.6f, "regains 10 HP");
    items[21] = new Item("potion", 30, 0.8f, "regains 30 HP");
    //if item added, change itemSize

    int size = 0;

    for(int i = 0; i < 20; ++i){
        int rand = random(0, 19);   //items 0-19
        if(unique(items[rand]->shortDescription(), tempList, size)){
            Item *item = items[rand];
            tempList.push_back(item);
            size++;
            // add item to room
            m_rooms[random(0,8)]->addItem(item);     //rooms 0-8
        }
    }
}


void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *boss;

    a = new Room("a");
    b = new Room("b");

    //add new Rooms
    c = new Room("c");
    d = new Room("d");
    e = new Room("e");
    f = new Room("f");
    g = new Room("g");
    h = new Room("h");
    i = new Room("i");
    //boss room
    boss = new Room("boss");

    //add rooms to list
    m_rooms.push_back(a);
    m_rooms.push_back(b);
    m_rooms.push_back(c);
    m_rooms.push_back(d);
    m_rooms.push_back(e);
    m_rooms.push_back(f);
    m_rooms.push_back(g);
    m_rooms.push_back(h);
    m_rooms.push_back(i);
    m_rooms.push_back(boss);


//             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
    boss->setExits(NULL,NULL,NULL,NULL);

    printWelcome();
    nextRoom(a);
}

///**
// *  Main play routine.  Loops until end of play.
// */


void ZorkUL::going(const QString btnName){  //call by value -> copy of variable


//  assert(processCommand(Command(goPrompt, btnName.toStdString())));
    processCommand(Command(goPrompt, btnName.toStdString()));
}

//void ZorkUL::equip(const QString itemName){
//    processCommand(Command(equipPrompt, itemName.toStdString()));
//}

bool ZorkUL::takeItem(QString itemName){
    return processCommand(Command(takePrompt, itemName.toStdString())); //global used variable not local scope
}

void ZorkUL::printWelcome() {
    cout << "start"<< endl;
    cout << "info for help"<< endl;
}

///**
// * Given a command, process (that is: execute) the command.
// * If this command ends the ZorkUL game, true is returned, otherwise false is
// * returned.
// */

bool ZorkUL::processCommand(Command command) {

    string commandWord = command.getCommandWord();

    if (commandWord.compare("info") == 0)
        printHelp();

    else if (commandWord.compare("map") == 0)
        {
            cout << "[h] --- [f] --- [g]" << endl;
            cout << "         |         " << endl;
            cout << "         |         " << endl;
            cout << "[c] --- [a] --- [b]" << endl;
            cout << "         |         " << endl;
            cout << "         |         " << endl;
            cout << "[i] --- [d] --- [e]" << endl;
            cout << "-------------------" << endl;
            cout << "-[final room]-" << endl;
        }
    if(commandWord.compare("go") == 0){
        goRoom(command);
        spawnEnemy();
    }

    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord()) {
            cout << "incomplete input"<< endl;
        } else if (command.hasSecondWord()) {
            Item* item = currentRoom->isItemInRoom(command.getSecondWord());
            if(item == NULL){
                cout << "item not found" << endl;
            } else {
                character->addItem(*item); //change
                cout << character->longDescription() << endl;    //check if he has a weapon
                cout << "item " + item->shortDescription() + " added to inventory" << endl;
                if(currentRoom->removeItemFromRoom(command.getSecondWord())){

                }
            }
        }
    }

    else if(commandWord.compare("attack") == 0){
        cout << "are you sure?" << endl;
    }

    else if (commandWord.compare("equip") == 0)
    {
        if(command.hasSecondWord()){
//            return character->equipItem(character.transformName(command.getSecondWord()));
            return true;
        } else{
            cout << "no such item" << endl;
        }
    }

    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
        else
            return true; /**signal to quit*/
    }
    return false;
}

QString ZorkUL::getItemDescription(string itemName) const{
    QString temp = QString("");
    for(int i = 0; i < currentRoom->getItemsInRoom().size(); ++i){
        if(itemName.compare(currentRoom->getItemsInRoom().at(i).shortDescription()) == 0)
            temp = QString(currentRoom->getItemsInRoom()[i].longDescription().c_str());
    }
    return temp;
}

bool ZorkUL::fillList(QStringList &list){

    if(currentRoom->getItemsInRoom().size() > 0){
        for(int i = 0; i < currentRoom->getItemsInRoom().size(); ++i){
            Item item = currentRoom->getItemsInRoom().at(i);
            list << item.shortDescription().c_str();
        }
        return false;
    } else{
        list << "no items\nin this room";
        return true;
    }
}

void ZorkUL::spawnEnemy(){
    //normal enemy
    currentRoom->addEnemy();
}


///** COMMANDS **/
void ZorkUL::printHelp() {
    cout << "valid inputs are; " << endl;
    parser.showCommands();
}

void ZorkUL::goRoom(Command command) {
    if (!command.hasSecondWord()) {
        cout << "undefined input"<< endl;
        return;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* next = currentRoom->nextRoom(direction);
    nextRoom(next);
}

void ZorkUL::nextRoom(Room* nextRoom){
    if (nextRoom == NULL)
        cout << "no exit here"<< endl;
    else {
        currentRoom = nextRoom;
        cout << currentRoom->longDescription() << endl;
        //trigger
        updateListView();
    }
}

void ZorkUL::teleport(){
    //room between 0 and 8
    Room* next = m_rooms.at(random(0,8));
    nextRoom(next);
}
