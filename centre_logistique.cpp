#include "centre_logistique.h"
#include <cstdlib>
#include <math.h>

centre_logistique::centre_logistique(int size)
{
    direction.resize(size); //on resize en fonction du nb de point
    random_();  //au debut les points vont dans des directions random
}

void centre_logistique::random_()
{
    for(int i=0;i<direction.size();i++){
        float directionrandom = rand()%360; //angle
        direction[i]= directionrandom;
    }

}



void centre_logistique::mutate(){   //mutation du vecteur direction
    step=0;
    float a=0.006;   //n'arrive que tres rarement
    for (int i=0;i<direction.size();i++){
        float r3 =static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.5)));
        if(r3<a){
            float randomangle = rand()%360;
            direction[i]= randomangle;
        }
    }
}
