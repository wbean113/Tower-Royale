#include"gameview.h"
#include<QResizeEvent>

GameView::GameView(QGraphicsScene *scene,QWidget *parent):QGraphicsView(scene,parent){
    setRenderHint(QPainter::Antialiasing);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);//?
}

void GameView::resizeEvent(QResizeEvent *event){
    fitInView(sceneRect(),Qt::KeepAspectRatio);
    QGraphicsView::resizeEvent(event);
}//视图适应（AI）
