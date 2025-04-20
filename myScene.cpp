#include "myScene.h"

StartScene::StartScene(QObject *parent)
    : QGraphicsScene{parent}
{

    setSceneRect({0,0,Gsettings::screenWidth,Gsettings::screenHeight});
    addPixmap(QPixmap(":/scene/src/scene/startScene.png"));



    //按钮样式
    gameStartBtn = new QToolButton();
    gameStartBtn->setIcon(QIcon(":/items/src/Items/gameStartButton.png"));
    gameStartBtn->move(Gsettings::screenWidth/2, Gsettings::screenHeight/2);
    gameStartBtn->setIconSize({100,100});
    gameStartBtn->setAutoRaise(true);
    gameStartBtn->setStyleSheet(""
                                "QToolButton{"
                                " border:none;"
                                " background:transparent;"
                                "}");
    addWidget(gameStartBtn);

}

StartScene::~StartScene()
{
    delete gameStartBtn;
}



//游戏场景类
GameScene::GameScene(QObject *parent)
    : QGraphicsScene{parent}
{

    setSceneRect({0,0,Gsettings::screenWidth,Gsettings::screenHeight});

    //默认背景
    backGround = new QGraphicsPixmapItem(QPixmap(":/scene/src/scene/scene2.png"));
    backGround2 = new QGraphicsPixmapItem(QPixmap(":/scene/src/scene/scene2.png"));

    //第二张图设在scene的右侧不可见区域
    backGround2->setPos(Gsettings::screenWidth,0);
    addItem(backGround);
    addItem(backGround2);
}



GameScene::~GameScene()
{
    delete backGround;
    delete backGround2;
}



void GameScene::move()
{
    if(Gsettings::backgroundMovable){

        backGround->moveBy( -Gsettings::backgroundMoveSpeed , 0 );
        backGround2->moveBy( -Gsettings::backgroundMoveSpeed , 0);

        //超出窗口边界时移到窗口右侧
        if (backGround->sceneBoundingRect().right() < 0) {
            backGround->setX( backGround2->sceneBoundingRect().right() );
        }
        if (backGround2->sceneBoundingRect().right() < 0) {
            backGround2->setX( backGround->sceneBoundingRect().right() );
        }
    }
}
