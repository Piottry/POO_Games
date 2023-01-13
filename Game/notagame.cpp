#include "notagame.h"


#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>


notagame::notagame(QWidget *parent){

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,900,700);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,700);


    QGraphicsRectItem *thing= new QGraphicsRectItem();  //le contour qui empeche les points de sortir
    thing->setRect(0,0,400,600);
    thing->setPos(scene->width()/2 - 400/2 ,scene->height()/2 - 600/2);
    scene->addItem(thing);


    goal= new QGraphicsRectItem();  //l'objectif a atteindre
    goal->setRect(0,0,10,10);
    goal->setPos(scene->width()/2,scene->height()/2 - 600/2 + 50);
    scene->addItem(goal);

    square=new mur(); //le mur du milieu
    square->setPos(scene->width()/2 - square->width/2,scene->height()/2 - square->height/2);
    scene->addItem(square);


    for (int i=0;i<pop.pop_size_return();i++){
        scene->addItem(pop.mypop[i]);               //on initialise ici pour eviter les probléme avec les parents
    }


}



