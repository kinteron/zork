/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QWidget *centralWidget;
    QGraphicsView *mapView;
    QWidget *gridLayoutWidget;
    QGridLayout *gridButtons;
    QPushButton *btnEast;
    QPushButton *btnSouth;
    QPushButton *btnWest;
    QPushButton *btnNorth;
    QPushButton *btnTeleport;
    QPushButton *btnWeapon;
    QLabel *lblDur;
    QLabel *lblAttack;
    QPushButton *btnPick;
    QPushButton *btnEquip;
    QListView *listItems;
    QLabel *lblEnemy;
    QLabel *lblRoom;
    QTextEdit *editWeapon;
    QListWidget *enemyStats;
    QMenuBar *menuBar;
    QMenu *menuZork;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QStringLiteral("Game"));
        Game->resize(455, 355);
        centralWidget = new QWidget(Game);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mapView = new QGraphicsView(centralWidget);
        mapView->setObjectName(QStringLiteral("mapView"));
        mapView->setGeometry(QRect(10, 0, 241, 181));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(250, 0, 209, 135));
        gridButtons = new QGridLayout(gridLayoutWidget);
        gridButtons->setSpacing(6);
        gridButtons->setContentsMargins(11, 11, 11, 11);
        gridButtons->setObjectName(QStringLiteral("gridButtons"));
        gridButtons->setContentsMargins(0, 0, 0, 0);
        btnEast = new QPushButton(gridLayoutWidget);
        btnEast->setObjectName(QStringLiteral("btnEast"));
        btnEast->setMaximumSize(QSize(50, 30));

        gridButtons->addWidget(btnEast, 1, 0, 1, 1);

        btnSouth = new QPushButton(gridLayoutWidget);
        btnSouth->setObjectName(QStringLiteral("btnSouth"));
        btnSouth->setMaximumSize(QSize(50, 30));

        gridButtons->addWidget(btnSouth, 2, 1, 1, 1);

        btnWest = new QPushButton(gridLayoutWidget);
        btnWest->setObjectName(QStringLiteral("btnWest"));
        btnWest->setMaximumSize(QSize(50, 30));

        gridButtons->addWidget(btnWest, 1, 2, 1, 1);

        btnNorth = new QPushButton(gridLayoutWidget);
        btnNorth->setObjectName(QStringLiteral("btnNorth"));
        btnNorth->setMaximumSize(QSize(50, 30));

        gridButtons->addWidget(btnNorth, 0, 1, 1, 1);

        btnTeleport = new QPushButton(gridLayoutWidget);
        btnTeleport->setObjectName(QStringLiteral("btnTeleport"));
        btnTeleport->setMaximumSize(QSize(50, 30));

        gridButtons->addWidget(btnTeleport, 1, 1, 1, 1);

        btnWeapon = new QPushButton(centralWidget);
        btnWeapon->setObjectName(QStringLiteral("btnWeapon"));
        btnWeapon->setGeometry(QRect(250, 170, 81, 71));
        lblDur = new QLabel(centralWidget);
        lblDur->setObjectName(QStringLiteral("lblDur"));
        lblDur->setGeometry(QRect(330, 220, 71, 21));
        lblAttack = new QLabel(centralWidget);
        lblAttack->setObjectName(QStringLiteral("lblAttack"));
        lblAttack->setGeometry(QRect(330, 200, 71, 21));
        btnPick = new QPushButton(centralWidget);
        btnPick->setObjectName(QStringLiteral("btnPick"));
        btnPick->setGeometry(QRect(250, 140, 81, 31));
        btnEquip = new QPushButton(centralWidget);
        btnEquip->setObjectName(QStringLiteral("btnEquip"));
        btnEquip->setGeometry(QRect(250, 240, 81, 31));
        listItems = new QListView(centralWidget);
        listItems->setObjectName(QStringLiteral("listItems"));
        listItems->setGeometry(QRect(120, 180, 131, 91));
        lblEnemy = new QLabel(centralWidget);
        lblEnemy->setObjectName(QStringLiteral("lblEnemy"));
        lblEnemy->setGeometry(QRect(10, 270, 55, 16));
        lblRoom = new QLabel(centralWidget);
        lblRoom->setObjectName(QStringLiteral("lblRoom"));
        lblRoom->setGeometry(QRect(120, 270, 55, 16));
        editWeapon = new QTextEdit(centralWidget);
        editWeapon->setObjectName(QStringLiteral("editWeapon"));
        editWeapon->setGeometry(QRect(330, 240, 81, 31));
        enemyStats = new QListWidget(centralWidget);
        enemyStats->setObjectName(QStringLiteral("enemyStats"));
        enemyStats->setGeometry(QRect(10, 180, 111, 91));
        Game->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Game);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 455, 26));
        menuZork = new QMenu(menuBar);
        menuZork->setObjectName(QStringLiteral("menuZork"));
        Game->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Game);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Game->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Game);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Game->setStatusBar(statusBar);

        menuBar->addAction(menuZork->menuAction());

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QMainWindow *Game)
    {
        Game->setWindowTitle(QApplication::translate("Game", "Game", Q_NULLPTR));
        btnEast->setText(QApplication::translate("Game", "east", Q_NULLPTR));
        btnSouth->setText(QApplication::translate("Game", "south", Q_NULLPTR));
        btnWest->setText(QApplication::translate("Game", "west", Q_NULLPTR));
        btnNorth->setText(QApplication::translate("Game", "north", Q_NULLPTR));
        btnTeleport->setText(QApplication::translate("Game", "teleport", Q_NULLPTR));
        btnWeapon->setText(QApplication::translate("Game", "use weapon", Q_NULLPTR));
        lblDur->setText(QApplication::translate("Game", "durability ", Q_NULLPTR));
        lblAttack->setText(QApplication::translate("Game", "attack", Q_NULLPTR));
        btnPick->setText(QApplication::translate("Game", "pick item", Q_NULLPTR));
        btnEquip->setText(QApplication::translate("Game", "equip", Q_NULLPTR));
        lblEnemy->setText(QApplication::translate("Game", "enemy", Q_NULLPTR));
        lblRoom->setText(QApplication::translate("Game", "room", Q_NULLPTR));
        menuZork->setTitle(QApplication::translate("Game", "Zork", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
