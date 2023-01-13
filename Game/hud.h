#ifndef HUD_H
#define HUD_H

#include <QGraphicsTextItem>


class HUD:public QGraphicsTextItem
{
public:
    HUD(QGraphicsItem * parent=0);
    void score_update();
    int score_return();
private:
    int score;
};

#endif // HUD_H
