#ifndef NEWPOP_H
#define NEWPOP_H



#include "ia.h"

class newpop:public QObject
{
Q_OBJECT
public:
    newpop();
    std::vector<ia*> mypop;


    bool alldead();
    void naturalselec();

    void selectparent();
    ia *my_dot_saved;
    ia *my_best_dot;

    void fitnessumfonc();
    float fitnessum;

    void testminstep();


    int pop_size_return();
    int gen=1;

private slots:
    void myfonc();
private:
    int size_pop=1000;
    int minstep=1000;

};

#endif // NEWPOP_H
