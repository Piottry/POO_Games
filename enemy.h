#ifndef ENEMY_H
#define ENEMY_H


#include <QGraphicsRectItem>
#include <QObject>

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy();
    void score_board_update();

public slots:
    void move();

private:
    int elapsed_time=10;
    QTimer * timer;


};

#endif
