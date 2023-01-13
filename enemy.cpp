#include "enemy.h"
#include "player.h"
#include "mygame.h"
#include "mainwindow.h"

#include <QMainWindow>

#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <fstream>





extern QString pseudo;
extern MyGame *game;
extern MainWindow *mymainwindow;

Enemy::Enemy(){
    int rand_num= rand() % 700;
    int rand_skin=rand()%2;
    //chaque ennemi peut avoir un skin aleatoire
    if(rand_skin==0){
        setPixmap(QPixmap(":/image/UFO.png")); //toutes les images ont ete faite a la main
    }
    else{
        setPixmap(QPixmap(":/image/UFO2.png"));
    }
    setPos(rand_num,0); //on fait commencer l'ennemi a un endroit aleatoire

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(elapsed_time);
}

void Enemy::move(){
    setPos(x(),y()+game->speed_enemy);  //chute de l'ennemi
    QList<QGraphicsItem *> colliding = collidingItems();    //liste de tout les ellements qui entre en contact avec un ennemi
    if(pos().y()>600-20){   //si l'ennemi touche le bas de la fenetre
        if(game->score->score_return()!=0){
            score_board_update();
        }
        //on supprime tout comme il faut
        scene()->removeItem(this);
        delete this;
        delete game->scene;
        delete game;
        mymainwindow->show();
    }
    for (int i =0,n = colliding.size();i<n;i++){
        if(typeid(*(colliding[i]))==typeid(Player)){ //si parmis les differents collidingItems() un est un PLayer alors
            if(game->score->score_return()!=0){
                score_board_update();
            }
            game->scene->removeItem(colliding[i]);
            game->scene->removeItem(this);
            delete colliding[i];
            delete this;
            delete game->scene;
            delete game;
            mymainwindow->show();   //on affiche l'ecrant d'acceuil
        }
    }

}



void Enemy::score_board_update(){

    std::ofstream fichier;
    fichier.open("score.txt", std::ios::app);  // on ouvre le fichier en lecture
    if(fichier.is_open())  // si l'ouverture a réussi
    {
        fichier<< pseudo.toStdString().c_str() <<"\n"<<game->score->score_return()<<"\n";   //on ecrit dans la fichier
        fichier.close();  // on ferme le fichier
    }
    else  // sinon
        qDebug()<<"Impossible d'ouvrir le fichier !";

}



