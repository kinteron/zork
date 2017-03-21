#ifndef GAME_H
#define GAME_H

#include "zork/ZorkUL.h"
#include <QMainWindow>
#include <QtWidgets>
#include <iostream>
#include <QSignalMapper>
#include <QMainWindow>

namespace Ui{
class Game;
}
class Game : public QMainWindow
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();

private:
    Ui::Game *ui;
    ZorkUL zork;
    QSignalMapper *mapper;
};
#endif // GAME_H
