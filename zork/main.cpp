#include "game.h"
//#include "zork/ZorkUL.h"
#include <QApplication>


/***
 * other threads can start event loops with QThread::exec()
 * control with exit(int) and quit()
 * connect signals from any threads to slots of a specific thread.
 * */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //single GUI-Application
    Game w(a.activeWindow());
    w.show();

    return a.exec();    // inits event loop

}
