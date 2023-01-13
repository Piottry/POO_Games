#include "mainwindow.h"
#include "mygame.h"
#include "notagame.h"



#include <QDialog>
#include <QApplication>

#include <stdlib.h>
#include <fstream>


MyGame *game;   //mon premier jeu
notagame *secondgame;   //mon second jeu
QString pseudo; //pour demander le pseudo
MainWindow *mymainwindow; //ma Mainwindow (permet d'y acceder dans les classes)


int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    mymainwindow = new MainWindow();
    mymainwindow->show();





    return a.exec();
}

