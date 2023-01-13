#include "hud.h"
#include "qfont.h"


HUD::HUD(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{

    score = 0;
    setPlainText(QString("Score:") + QString::number(score));
    setDefaultTextColor(Qt::blue);  //couleur
    setFont(QFont("times",16)); //police
}

void HUD::score_update()    //on refresh le score
{
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
}

//to get the score in case of an event
int HUD::score_return()
{
    return score;
}
