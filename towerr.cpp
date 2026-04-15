#include"towerr.h"
#include <QBrush>
#include<QObject>
#include<QTimer>
#include<QLineF>

Tower::Tower(const QPointF &pos):QGraphicsRectItem(-20,-20,40,40)
{
    setPos(pos);
    setBrush(Qt::blue);
    range=100;
    damage=1;
    //attackTimer = new QTimer(this);//update 来出发tower的攻击

}
void Tower::attack(QList<Enemy*>&enemies){
    Enemy *target =nullptr;
    qreal minDist =range;
    for(Enemy *e:enemies){
        qreal dist = QLineF(pos(),e->pos()).length();
        if(dist<range&&dist<minDist){
            minDist=dist;
            target=e;
            //zainei logic
        }
    }
    if(target){
        target->takeDamage(damage);
    }
}

QRectF Tower::boundingRect() const{
    return QRectF(-20,-20,40,40);//这里用于。。。
}
//uncompleted 3.23
//3.25  既然attackTimer这块老是报错，干脆注释掉了