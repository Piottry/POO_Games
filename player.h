#ifndef PLAYER_H
#define PLAYER_H


#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>

class Player: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event);


public slots:
    void spawn();
private:
    int player_width=20;
    int player_height=20;
    bool etat_score=false;

};

#endif // PLAYER_H
