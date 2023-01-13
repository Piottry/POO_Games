#include "bullet.h"
#include "enemy.h"
#include "mygame.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QMediaPlayer>


extern MyGame * game;

Bullet::Bullet(){
    setPixmap(QPixmap(":/image/bullet.png"));
    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(10);


}

void Bullet::move(){
    setPos(x(),y()-2);  //la balle monte
    if(pos().y()+ 8<0){
        game->scene->removeItem(this);
        delete this;
    }
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i =0,n = colliding_items.size();i<n;i++){
        if(typeid(*(colliding_items[i]))==typeid(Enemy)){

            game->score->score_update();



            game->scene->removeItem(colliding_items[i]);
            game->scene->removeItem(this);
            delete colliding_items[i];
            delete this;
        }

    }


}


