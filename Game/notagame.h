#ifndef NOTAGAME_H
#define NOTAGAME_H



#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <vector>
#include <QObject>

#include "mur.h"
#include "newpop.h"


class notagame:public QGraphicsView
{
public:
    notagame(QWidget * parent=0);

    QGraphicsScene * scene;
    QGraphicsRectItem * goal ;
    newpop pop;
    mur *square;

};

#endif
