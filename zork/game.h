#ifndef GAME_H
#define GAME_H

#include "zork/ZorkUL.h"
#include <QMainWindow>
#include <QtWidgets>
#include <iostream>
#include <QSignalMapper>
#include <QMainWindow>
#include <QStringListModel>
#include <QStringList>
#include <QModelIndex>

namespace Ui{
class Game;
}
class Game : public QMainWindow
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();

private slots:
//    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_itemClicked(QModelIndex index);
    void on_itemDoubleClicked(QModelIndex index);
    void update();
    void onEquip();

private:
    Ui::Game *ui;
    ZorkUL zork;
    QSignalMapper *mapper;

    QStringListModel *model;
};
#endif // GAME_H
