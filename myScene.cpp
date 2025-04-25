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



//计分板
ScoreBoard::ScoreBoard(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
    : QGraphicsRectItem(x, y, width, height, parent)
{
    // 边框样式
    QPen pen(QColor(100, 55, 10));
    pen.setWidth(7);
    setPen(pen);

    // 设置背景颜色
    QBrush brush(QColor(155, 132, 90));
    setBrush(brush);



    // 创建分数文本项
    scoreText = new QGraphicsTextItem(this);
    scoreText->setFont(QFont("微软雅黑", 14, QFont::Bold));
    scoreText->setDefaultTextColor(Qt::black);

    // 初始化分数显示
    updateScore(0);
}




void ScoreBoard::updateScore(int s)
{
    score = s;
    scoreText->setPlainText(QString("Score: %1").arg(score));

    // 计算文本居中位置
    QRectF textRect = scoreText->boundingRect();
    scoreText->setPos(x() + (rect().width() - textRect.width()) / 2,
                      y() + (rect().height() - textRect.height()) / 2);
}

int ScoreBoard::getScore()
{
    return score;
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

    //计分板
    scoreBoard = new ScoreBoard(0,0,150,100);
    addItem(scoreBoard);
}



GameScene::~GameScene()
{
    delete backGround;
    delete backGround2;
    delete scoreBoard;
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




