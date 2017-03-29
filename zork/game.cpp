#include "game.h"
#include "ui_game.h"



Game::Game(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Game),zork(new ZorkUL(parent))
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
    QPlainTextEdit *txtItem = ui->editItem;

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
//    mapper->setMapping(equip, txtItem->textCursor().block().text());   //parameter

    //sender, signal, receiver, slot
    //directions go...
    connect(north, SIGNAL(released()), mapper, SLOT(map()));
    connect(east, SIGNAL(released()), mapper, SLOT(map()));
    connect(west, SIGNAL(released()), mapper, SLOT(map()));
    connect(south, SIGNAL(released()), mapper, SLOT(map()));
//    connect(equip, SIGNAL(released()), mapper, SLOT(map()));

    //connect signal to evaluateClick() from zork
    connect(mapper, SIGNAL(mapped(QString)), &zork, SLOT(going(QString)));
    connect(teleport, SIGNAL(released()), &zork, SLOT(teleport()));

    itemList->selectionModel()->connect(itemList, SIGNAL(clicked(QModelIndex)), this, SLOT(on_itemClicked(QModelIndex)));
    itemList->selectionModel()->connect(itemList, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_itemDoubleClicked(QModelIndex)));

    //enemy
    foeStatus->selectionModel()->connect(itemList, SIGNAL(clicked(QModelIndex)), this, SLOT(on_itemClicked(QModelIndex)));
    foeStatus->connect(&zork, SIGNAL(updateListView()), this, SLOT(update()));

    //weapon
//    connect(equip, SIGNAL(released()), &zork, SLOT(equipItem(QString)));
    //calc health (enemy, character)
    connect(weapon, SIGNAL(released()), &zork, SLOT(fight()));
    //and update view
    connect(weapon, SIGNAL(released()), this, SLOT(update()));
    connect(equip, SIGNAL(released()), this, SLOT(onEquip()));

    QListWidgetItem item = QListWidgetItem();
    //enemyStats onClick
}

void Game::onEquip(){
    QString s = ui->editItem->textCursor().block().text();
    zork.equipItem(s);
    ui->lblEquipped->setText("Weapon " + zork.getItemName());
    ui->lblAttack->setText("attack " + zork.getItemValue());
    ui->lblDur->setText("durability " + zork.getItemDurability());
}

void Game::update(){
    ui->enemyStats->clear();
    QStringList list;
    if(zork.isEnemyPresent()){
        ui->lblEnemy->setText(zork.getEnemyName());  //value of pointer
        ui->enemyStats->addItem(zork.getEnemyDescription());
    } else{
        ui->listItems->selectionModel()->blockSignals(zork.fillList(list)); //call by reference
        ui->lblEnemy->setText(QString(""));
    }
    model->setStringList(list);
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
