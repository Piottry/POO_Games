#include "mygame.h"

#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>



MyGame::MyGame(QWidget *parent){

    scene = new QGraphicsScene();   //creation de la scene
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/image/screen.png")));
    setScene(scene);    //on dit que notre scene est bien las scene
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //interdit les bares verticales et horizontales
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   //
    setFixedSize(800,600);

    square = new Player();  //creation du joueur
    square->setPos(scene->width()/2 - 10,scene->height() - 30); //placement du joueur dans la scene

    //rend le joueur focusable permet d'utiliser les QKey_Event
    square->setFlag(QGraphicsItem::ItemIsFocusable);
    square->setFocus();
    //ajoute le joueur a la scene
    scene->addItem(square);

    // creation du score
    score = new HUD();
    scene->addItem(score);




    //on fait spawn les ennemis
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),square,SLOT(spawn())); //on connecte le timer et le type de signal (timeout = vrai toute les 2000ms) a une classe et une de ces fonctions
    timer->start(2000);

    show();
}
