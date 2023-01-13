#ifndef MYGAME_H
#define MYGAME_H


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

#include "player.h"
#include "hud.h"


class MyGame: public QGraphicsView{
public:
    MyGame(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * square;
    HUD * score;
    int speed_enemy=1;


};

#endif // MYGAME_H
