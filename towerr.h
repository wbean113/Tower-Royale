#ifndef TOWERR_H
#define TOWERR_H
#pragma once
#include <QGraphicsRectItem>
#include <QTimer>
#include "enemy.h"
class Tower:public QGraphicsRectItem{
public:
    Tower(const QPointF &Pos);
    void attack(QList<Enemy*>&enemies);
    QRectF boundingRect() const override;


private:
    int range;
    int damage;
    //QTimer *attackTimer;
    //QList<Enemy*>*enemiesList;
};//done 3.23
#endif // TOWERR_H
