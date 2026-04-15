#include "mainwindow.h"
#include "gameview.h"
#include "gamescene.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    GameScene *scene = new GameScene(this);
    GameView *view = new GameView(scene,this);
    setCentralWidget(view);
    resize(800,600);
}//done 3.23