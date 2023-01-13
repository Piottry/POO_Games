#include "newpop.h"

#include <QGraphicsScene>
#include <QTimer>
#include "ia.h"




newpop::newpop()
{
    for(int i=0;i<size_pop;i++){
        mypop.push_back(new ia());  //on rempli le vecteur
    }

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(myfonc()));
    timer->start(10);
}






void newpop::myfonc()
{

    if(alldead()){
        testminstep();
        naturalselec();
    }
    for(int i=0;i<mypop.size();i++){    //si on depasse minstep tue le point
        if(mypop[i]->cerveau->step>minstep){
            mypop[i]->dead=true;
        }
    }
}



int newpop::pop_size_return()
{
    return size_pop;
}

//verifie que tous les points sont morts
bool newpop::alldead(){
    for(int i=0;i<size_pop;i++){
        if(!mypop[i]->dead){
            return false;
        }
    }
    return true;
}


//calcule la somme de la fitness
void newpop::fitnessumfonc()
{
    fitnessum=0;
    for(int i=0;i<mypop.size();i++){
        fitnessum+=mypop[i]->fitnes;
    }
}

//calcule le minimum d'etape pour aller jusqu'a l'objectif et garde en memoire le point avec la plsu grande fitness
void newpop::testminstep()
{
    float max=0;
    int indicesave;
    minstep=1000;
    for(int i=0;i<mypop.size();i++){
        if(mypop[i]->cerveau->step<minstep && mypop[i]->reachgoal==true ){
            minstep= mypop[i]->cerveau->step;
        }
        if(mypop[i]->fitnes>max){
            max=mypop[i]->fitnes;
            my_best_dot=mypop[i];
            indicesave=i;
        }
    }
    mypop[indicesave]->fitnes+= 1;
    my_best_dot->fitnes += 1;


}

void newpop::naturalselec(){
    selectparent(); //on selectionne le parent
    //le meilleur point est conservé
    mypop[0]->cerveau->direction = my_best_dot->cerveau->direction;
    mypop[0]->cerveau->step=0;

    for(int i=1;i<mypop.size();i++){
        mypop[i]->cerveau->direction = my_dot_saved->cerveau->direction;    //on transforme le vecteur direction de tous les points
        mypop[i]->cerveau->mutate();    //transformation aleatoire du vecteur direction

    }
    //appel de la fonction reset pour tous les points
    for(int i=0;i<mypop.size();i++){
        mypop[i]->repos();
    }

}


//chaque point a une fitness en fonction de ses performance + le nombre et grand mieux c'est
//grace a sum on met bout a bout ces fitness et ensuite r3 nous donne un nombre aleatoire
//ainsi les point avec une plsu grande fitness ont plus de chance d'etre selectionné pour etre parent



void newpop::selectparent(){
    fitnessumfonc();
    float r3 =static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(fitnessum)));
    float sum=0;
    for(int i=0;i<mypop.size();i++){
        sum+=mypop[i]->fitnes;
        if(sum>r3){
            my_dot_saved=mypop[i];
            break;
        }
    }
}










