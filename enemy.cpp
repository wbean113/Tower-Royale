#include "enemy.h"
#include <QBrush>

Enemy::Enemy(const QPointF &startPos):QGraphicsEllipseItem(-15,-15,30,30){
    setPos(startPos);
    setBrush(Qt::red);
    hp=3;
    speed=2.0;
}
void Enemy::moveTowards(const QPointF &target){
    QPointF dir = target -pos();
    if(dir.manhattanLength()<speed){
        setPos(target);
    }else{
        dir =dir/dir.manhattanLength();//这里用了mamhattAn距离，主义三个元音都是a
        setPos(pos()+dir*speed);
    }
}
void Enemy::takeDamage(int damage){
    hp-=damage;
    if(hp<=0){//die 的 mark
    }
}//done 3.23