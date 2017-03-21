#include "game.h"
#include "ui_game.h"


Game::Game(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Game)
{
    ui->setupUi(this);

    //setup Controls

    QPushButton *north = ui->btnNorth;  //pointer = &  -> can be handed as a parameter in connect()
    QPushButton *east = ui->btnEast;
    QPushButton *south = ui->btnWest;
    QPushButton *west = ui->btnSouth;
    QPushButton *teleport = ui->btnTeleport;
    QPushButton *weapon = ui->btnWeapon;
    QPushButton *pick = ui->btnPick;
    QPushButton *equip = ui->btnEquip;

    //in order to use different signals such as different buttons and send them to the same slot
    mapper = new QSignalMapper();        //heap
    //specify the argument
    mapper->setMapping(north, QString(north->text()));
    mapper->setMapping(east, QString(east->text()));
    mapper->setMapping(west, QString(west->text()));
    mapper->setMapping(south, QString(south->text()));

    //sender, signal, receiver, slot
    connect(north, SIGNAL(released()), mapper, SLOT(map()));
    connect(east, SIGNAL(released()), mapper, SLOT(map()));
    connect(west, SIGNAL(released()), mapper, SLOT(map()));
    connect(south, SIGNAL(released()), mapper, SLOT(map()));

    //connect signal to evaluateClick() from zork
    connect(mapper, SIGNAL(mapped(QString)), &zork, SLOT(going(QString)));
    connect(teleport, SIGNAL(released()), &zork, SLOT(teleport()));
    connect(pick, SIGNAL(released()), &zork, SLOT(takeItem()));
}

Game::~Game()
{

}
