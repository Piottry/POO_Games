#include "player.h"

#include "bullet.h"
#include "enemy.h"
#include "mygame.h"

#include <QMediaPlayer>
#include <QGraphicsScene>

extern MyGame * game;

Player::Player()
{
    setPixmap(QPixmap(":/image/plane.png"));    //le joueur est une image
}


void Player::keyPressEvent(QKeyEvent *event)    //detecte les evenements de touche
{

    if(event->key()==Qt::Key_Left){
        if(x()>0){
            setPos(x()-10,y());
        }
    }
    else if(event->key()==Qt::Key_Right){
        if(x()< game->scene->width() - player_width){
            setPos(x()+10,y());
        }
    }
    else if(event->key()==Qt::Key_Space){
        if(game->score->score_return()<30){ //si le score et <30 on tire une seule balle
        Bullet * bullet = new Bullet(); //on crée la balle
        bullet->setPos(x() +player_width/2,y()-player_height/2);    //on la positionne
        game->scene ->addItem(bullet);  //ajout a la scene
        }
        else if(game->score->score_return()>=30){   //on tire 2 balles
        Bullet * bullet1 = new Bullet();
        Bullet * bullet2 = new Bullet();
        bullet1->setPos(x(),y());
        bullet2->setPos(x() + player_width ,y()-player_height);
        game->scene ->addItem(bullet1);
        game->scene ->addItem(bullet2);
        }
    }
    else if(event->key()==Qt::Key_Escape){
        game->close();
    }

}

void Player::spawn()
{
    Enemy *enemy=new Enemy();
    game->scene->addItem(enemy);

    if(game->score->score_return()%10==0 && etat_score==false && game->score->score_return()!=0){   //tout les 10 de score on augmente la vitesse des ennemis de 1
        game->speed_enemy++;
        etat_score=true;
    }
    else if(game->score->score_return()%10!=0){
        etat_score=false;
    }
}

