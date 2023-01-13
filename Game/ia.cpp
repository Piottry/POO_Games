#include "ia.h"
#include "mainwindow.h"
#include "notagame.h"

#include <QGraphicsScene>
#include <QTimer>


extern MainWindow * mymainwindow;
extern notagame * secondgame;
ia::ia()
{
    setRect(0,0,5,5);
    cerveau = new centre_logistique(size);
    pos.resize(2);
    pos = {450,600};    //position sur la scene
    setPos(pos[0],pos[1]);
    vel.resize(2);
    vel={0,0};      //vitesse
    acc.resize(2);
    acc={0,0};      //acceleration

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);

}


void ia::move(){
    if(sqrt( (x() - secondgame->goal->x())*(x() - secondgame->goal->x()) + (y() - secondgame->goal->y())*(y() - secondgame->goal->y()) ) <8){   //si l'objectif est touché
        reachgoal=true;
    }
    if( x()< 450 + secondgame->square->width/2 && x()> 450 - secondgame->square->width/2 && y()> 350-secondgame->square->height/2 && y()<350 +secondgame->square->height/2){    //si le gros carré/rectangle  est touché
        dead=true;
    }

    if(x()>450-200 && x()<450+200 && y()>350-300 && y()<350+300+5 && reachgoal==false && dead==false){
        if (cerveau->direction.size() > cerveau->step ){ //temps qu'il reste des directions a lire
            acc[0]=cos(cerveau->direction[cerveau->step] * M_PI /180);
            acc[1]=sin(cerveau->direction[cerveau->step] * M_PI /180);
            cerveau->step++;
        }
        for (int i=0;i<2;i++){
            vel[i] += acc[i];

            if(vel[i]>=2){
                vel[i]-=acc[i];
            }
            pos[i] += vel[i];
        }
        acc[0]=0;
        acc[1]=0;
        update_pos();

    }
    else{
        fitness();  //si le point ne se deplace plus alors on calcul ca fitness et on le tue
        dead=true;
    }

}

void ia::update_pos(){
    setPos(pos[0],pos[1]);

}


void ia::fitness(){
    if(reachgoal){  //le fait que l'objectif est ete atteind est plus important
        fitnes = 1.0/10 + 1000.0/(float)(cerveau->step * cerveau->step );
    }
    else{
        float dist_to_goal= sqrt(   (x() - secondgame->goal->x())*(x()-secondgame->goal->x()) + (y() - secondgame->goal->y())*(y()-secondgame->goal->y())    );// distance entre un point et l'objectif
        fitnes = 1 /(dist_to_goal*dist_to_goal); //acause du carré les points les plus proches auront bcp plus de chance d'etre selectionné
    }
}

void ia::repos(){   //on reset tout
    vel[0]=0;
    vel[1]=0;
    acc[0]=0;
    acc[1]=0;
    pos[0] = 450;
    pos[1]=  600;
    setPos(pos[0],pos[1]);
    dead= false;
    reachgoal=false;
}
