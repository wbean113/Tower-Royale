#ifndef GAMEVIEW_H
#define GAMEVIEW_H


#pragma once
#include <QGraphicsView>

class GameView : public QGraphicsView
{
 Q_OBJECT
public:
 explicit GameView(QGraphicsScene *scene,QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent *event)override;

};//done 3.23





#endif // GAMEVIEW_H
