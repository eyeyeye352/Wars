#ifndef MYSCENE_H
#define MYSCENE_H


#include "Gsettings.h"


//游戏起始场景
class StartScene : public QGraphicsScene
{
public:

    StartScene(QObject *parent = nullptr);
    ~StartScene();

    QToolButton * gameStartBtn;
};




class ScoreBoard : public QGraphicsRectItem{
public:

    ScoreBoard(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
    void updateScore(int score);
    int getScore();

private:
    QGraphicsTextItem *scoreText;
    int score;
};




//游戏场景
class GameScene : public QGraphicsScene
{

public:

    GameScene(QObject *parent = nullptr);
    ~GameScene();

    //交替场景播放
    void move();

    ScoreBoard* scoreBoard;

private:

    //场景循环播放设置（若 movable == true）
    QGraphicsPixmapItem * backGround, * backGround2;


};



#endif // MYSCENE_H
