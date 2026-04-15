#include "gamescene.h"
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <QGraphicsView>
#include <QDebug>

GameScene::GameScene(QObject *parent) : QGraphicsScene(parent)
{
    // 初始化参数
    resource = 100;   // 起始圣水
    enemiesReached = 0;
    startPos = QPointF(0, 300);
    endPos = QPointF(800, 300);   // 假设场景宽800

    // 设置场景大小（根据视图大小动态设置，这里简单固定）
    setSceneRect(0, 0, 800, 600);

    // 定时器：每2秒增加圣水
    resourceTimer = new QTimer(this);
    connect(resourceTimer, &QTimer::timeout, this, &GameScene::addResource);
    resourceTimer->start(2000);

    // 定时器：每3秒生成一个敌人
    spawnTimer = new QTimer(this);
    connect(spawnTimer, &QTimer::timeout, this, &GameScene::spawnEnemy);
    spawnTimer->start(3000);

    // 游戏主循环：每50ms更新一次（移动敌人、塔攻击）
    gameLoopTimer = new QTimer(this);
    connect(gameLoopTimer, &QTimer::timeout, this, &GameScene::updateGame);
    gameLoopTimer->start(50);
}

void GameScene::addResource()
{
    resource += 10;
    // 可以在这里更新UI显示，后续添加
    qDebug() << "Resource:" << resource;
}

void GameScene::spawnEnemy()
{
    Enemy *enemy = new Enemy(startPos);
    enemies.append(enemy);
    addItem(enemy);
}

void GameScene::updateGame()
{
    // 1. 移动所有敌人
    for (int i = 0; i < enemies.size(); ++i) {
        Enemy *e = enemies[i];
        e->moveTowards(endPos);   // 敌人自己实现移动逻辑
        if (e->pos().x() >= endPos.x()) { // 到达终点
            enemiesReached++;
            removeItem(e);
            enemies.removeAt(i);
            delete e;
            i--;
            if (enemiesReached >= MAX_ENEMIES) {
                gameover();
                return;
            }
        }
    }

    // 2. 塔攻击（简化：每个塔攻击最近的一个敌人）
    for (Tower *t : towers) {
        t->attack(enemies);
    }

    // 3. 移除死亡敌人
    for (int i = 0; i < enemies.size(); ++i) {
        if (enemies[i]->isDead()) {
            removeItem(enemies[i]);
            delete enemies[i];
            enemies.removeAt(i);
            i--;
        }
    }
}

void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF pos = event->scenePos();
    if (canPlaceTower(pos)) {
        addTower(pos);
    }
    QGraphicsScene::mousePressEvent(event);
}

bool GameScene::canPlaceTower(const QPointF &pos)
{
    // 简单检查：不能放在路径上（y=300附近，误差30像素）
    if (qAbs(pos.y() - 300) < 30) return false;
    // 检查是否与已有塔重叠
    for (Tower *t : towers) {
        if (t->collidesWithItem(t)) return false; // 需要tower有boundingRect
    }
    return resource >= 50;   // 塔花费50圣水
}

void GameScene::addTower(const QPointF &pos)
{
    resource -= 50;
    Tower *tower = new Tower(pos);
    towers.append(tower);
    addItem(tower);
}

void GameScene::checkAttack()
{
    // 实际上在updateGame里调用tower->attack，这里可以省略
}

void GameScene::gameover()
{
    resourceTimer->stop();
    spawnTimer->stop();
    gameLoopTimer->stop();
    QMessageBox::information(nullptr, "Game Over", "You lost!");
    // 可以添加重启逻辑，但MVP先简单结束
}


//3.23  disunderstand
//3.25