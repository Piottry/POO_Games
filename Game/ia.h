#ifndef IA_H
#define IA_H


#include <QGraphicsRectItem>
#include <QObject>

#include "centre_logistique.h"

class ia:public QObject, public QGraphicsRectItem
{
Q_OBJECT
public:
    ia();
    ia operator= ( const ia & ) = delete;

    std::vector<double> pos,vel,acc;

    centre_logistique *cerveau;

    void update_pos();

    void baby();

    ia *mysavedbaby;

    void fitness();
    float fitnes=0;
    bool dead=false;
    bool reachgoal=false;
    void repos();
    int size=500;

public slots:
    void move();

private:


};

#endif
