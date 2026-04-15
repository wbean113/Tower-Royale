#ifndef GAMESCENE_H
#define GAMESCENE_H


#pragma once
#include<QGraphicsScene>
#include<QTimer>
#include<QList>
#include"enemy.h"
#include"towerr.h"

class GameScene:public QGraphicsScene
{
    Q_OBJECT

public:
    explicit GameScene(QObject *parent=nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent *event)override;

public slots:
    void addResource();
    void spawnEnemy();
    void updateGame();
    void gameover();

private:
    QTimer *resourceTimer;
    QTimer *spawnTimer;
    QTimer *gameLoopTimer;

    QList<Enemy*>enemies;
    QList<Tower*>towers;

    int resource;//圣水
    int enemiesReached;//到站
    const int MAX_ENEMIES = 10;

    QPointF startPos;
    QPointF endPos;

    bool canPlaceTower(const QPointF &pos);//bu die fang
    void addTower(const QPointF &pos);
    void checkAttack();

};//done 3,23

#endif // GAMESCENE_H
