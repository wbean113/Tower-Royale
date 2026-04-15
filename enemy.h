#ifndef ENEMY_H
#define ENEMY_H
#pragma once
#include <QGraphicsEllipseItem>
class Enemy:public QGraphicsEllipseItem{
public:
    Enemy(const QPointF &startPos);
    void moveTowards(const QPointF &target);
    void takeDamage(int damage);
    bool isDead()const{return hp <=0;}

private:
    int hp;
    qreal speed;
};//done 3.23

#endif // ENEMY_H
