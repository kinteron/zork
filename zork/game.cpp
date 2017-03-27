#include "game.h"
#include "ui_game.h"



Game::Game(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Game), zork(ZorkUL(parent))
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

    QListView *itemList = ui->listItems;
    QListWidget *foeStatus = ui->enemyStats;
    itemList->setUniformItemSizes(true); //every item has the same size

    //for the listview
    model = new QStringListModel(this);    //this?
    QStringList list;
    list << "that" << "sucks" << "bla";
    model->setStringList(list);
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

    //sender, signal, receiver, slot
    connect(north, SIGNAL(released()), mapper, SLOT(map()));
    connect(east, SIGNAL(released()), mapper, SLOT(map()));
    connect(west, SIGNAL(released()), mapper, SLOT(map()));
    connect(south, SIGNAL(released()), mapper, SLOT(map()));

    //connect signal to evaluateClick() from zork
    connect(mapper, SIGNAL(mapped(QString)), &zork, SLOT(going(QString)));
    connect(teleport, SIGNAL(released()), &zork, SLOT(teleport()));
    connect(pick, SIGNAL(released()), &zork, SLOT(takeItem()));

    itemList->selectionModel()->connect(itemList, SIGNAL(clicked(QModelIndex)), this, SLOT(on_itemClicked(QModelIndex)));
    itemList->selectionModel()->connect(itemList, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_itemDoubleClicked(QModelIndex)));

    QListWidgetItem item = QListWidgetItem();
    //enemyStats onClick

    zork.printWelcome();

}

void Game::on_listWidget_itemDoubleClicked(QListWidgetItem *item){
    item->setTextColor(Qt::red);
    cout << item->text().toStdString() << endl;
}

void Game::on_itemDoubleClicked(QModelIndex index){
    model->removeRows(ui->listItems->currentIndex().row(),1);
    cout << "wurde entfernt" << endl;
    QStringList ficken;
    ficken << "errfas";
//    model->setStringList(ficken);
}

void Game::on_itemClicked(QModelIndex index){
    cout << "did it work" << endl;
    QVariant stringData = model->data(index, 0);  //displayRole 0 for QString text



//    cout << stringData.toString().toStdString() << " was deleted " << endl;
}

Game::~Game()
{

}
