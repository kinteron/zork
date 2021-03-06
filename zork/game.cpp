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
    QPushButton *equip = ui->btnEquip;

    QListView *itemList = ui->listItems;
    QListWidget *foeStatus = ui->enemyStats;
    itemList->setUniformItemSizes(true); //every item has the same size

    //for the listview
    model = new QStringListModel(this);    //this?

    //model can be applied to any view, in order to update all views
    itemList->setModel(model);
    QModelIndex currentIndex = itemList->selectionModel()->currentIndex();

    //in order to use different signals such as different buttons and send them to the same slot
    mapper = new QSignalMapper();        //heap
    //specify the argument
    mapper->setMapping(north, QString(north->text()));
    mapper->setMapping(east, QString(east->text()));
    mapper->setMapping(west, QString(west->text()));
    mapper->setMapping(south, QString(south->text()));
//    mapper->setMapping(&zork, zork.isEnemyPresent());   //parameter

    //sender, signal, receiver, slot
    connect(north, SIGNAL(released()), mapper, SLOT(map()));
    connect(east, SIGNAL(released()), mapper, SLOT(map()));
    connect(west, SIGNAL(released()), mapper, SLOT(map()));
    connect(south, SIGNAL(released()), mapper, SLOT(map()));

    //connect signal to evaluateClick() from zork
    connect(mapper, SIGNAL(mapped(QString)), &zork, SLOT(going(QString)));
    connect(teleport, SIGNAL(released()), &zork, SLOT(teleport()));
//    connect(mapper, SIGNAL(mapped(int)), this, SLOT(updateRoom(int)));

    itemList->selectionModel()->connect(itemList, SIGNAL(clicked(QModelIndex)), this, SLOT(on_itemClicked(QModelIndex)));
    itemList->selectionModel()->connect(itemList, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_itemDoubleClicked(QModelIndex)));
    foeStatus->selectionModel()->connect(itemList, SIGNAL(clicked(QModelIndex)), this, SLOT(on_itemClicked(QModelIndex)));
    foeStatus->connect(&zork, SIGNAL(updateListView()), this, SLOT(update()));

    QListWidgetItem item = QListWidgetItem();
    //enemyStats onClick
}

void Game::update(){
    ui->enemyStats->clear();
    if(zork.isEnemyPresent()){
        ui->lblEnemy->setText(zork.getEnemyName());  //value of pointer
        ui->enemyStats->addItem(zork.getEnemyDescription());
    } else{
        QStringList list;
        ui->listItems->selectionModel()->blockSignals(zork.fillList(list)); //call by reference
        model->setStringList(list);
    }
    ui->lblRoom->setText(zork.getCurrentRoomText());
}

void Game::on_itemDoubleClicked(QModelIndex index){

    zork.takeItem(model->data(index, 0).toString());//0 for string
    model->removeRows(ui->listItems->currentIndex().row(),1);
}

void Game::on_itemClicked(QModelIndex index){
    QVariant stringData = model->data(index, 0);  //displayRole 0 for QString text
    ui->enemyStats->clear();
    ui->enemyStats->addItem(zork.getItemDescription(stringData.toString().toStdString()));
}

Game::~Game()
{

}
