#include "gamesys.h"

Gamesys::Gamesys(QWidget *parent)
    : QWidget(parent)
{

    //窗口设置
    setFixedSize(Gsettings::screenWidth,Gsettings::screenHeight);
    setWindowIcon(QIcon(":/items/src/Items/wp_enemy.png"));

    init();

}

Gamesys::~Gamesys() {
    delete player;
}


void Gamesys::init(){



    //初始化成员
    scene = new GameScene(this);
    startScene = new StartScene(this);
    view = new QGraphicsView(this);
    player = new Player();
    Msys = new MusicSys(this);
    gObjectPool::Instance()->init();

    scene->addItem(player);
    view->setSceneRect({0,0,Gsettings::screenWidth,Gsettings::screenHeight});
    view->setScene(startScene);


    //计时器处理
    backgroundMoveTimer = new QTimer(this);
    playerMoveTimer  = new QTimer(this);
    shootTimer  = new QTimer(this);
    createEnemyTimer  = new QTimer(this);
    bulletMoveTimer  = new QTimer(this);
    enemyMoveTimer  = new QTimer(this);

    connect(backgroundMoveTimer,&QTimer::timeout,this,&Gamesys::moveBackground);
    connect(playerMoveTimer,&QTimer::timeout,this,&Gamesys::movePlayer);
    connect(shootTimer,&QTimer::timeout,this,&Gamesys::playerShootBullet);
    connect(createEnemyTimer,&QTimer::timeout,this,&Gamesys::createEnemy);
    connect(bulletMoveTimer,&QTimer::timeout,this,&Gamesys::moveBullet);
    connect(enemyMoveTimer,&QTimer::timeout,this,&Gamesys::moveEnemy);



    //开始游戏按钮关联
    connect(startScene->gameStartBtn,&QToolButton::clicked,this,&Gamesys::gameStart);

    view->show();
}


void Gamesys::gameStart()
{
    view->setScene(scene);

    backgroundMoveTimer->start(Gsettings::screenUpdateInterval);
    playerMoveTimer->start(Gsettings::screenUpdateInterval);
    shootTimer->start(Gsettings::playerShootInterval);
    createEnemyTimer->start(Gsettings::enemyGenerateInterval);
    bulletMoveTimer->start(Gsettings::screenUpdateInterval);
    enemyMoveTimer->start(Gsettings::screenUpdateInterval);

    Msys->bgm->play();
    Msys->shootSound->play();
}




void Gamesys::keyPressEvent(QKeyEvent *event)
{
    //点击键盘时将键位存至player的keyPressinglist，player类内部遍历该容器进行移动。
    switch(event->key()){
    case Qt::Key_W:
    case Qt::Key_Up:
    case Qt::Key_S:
    case Qt::Key_Down:
    case Qt::Key_A:
    case Qt::Key_Left:
    case Qt::Key_D:
    case Qt::Key_Right:
        keyPressing.append(event->key());
        break;
    }
}

void Gamesys::keyReleaseEvent(QKeyEvent *event)
{
    if(keyPressing.contains(event->key())){
        keyPressing.removeOne(event->key());
    }
}



void Gamesys::moveBackground()
{
    scene->move();
}


void Gamesys::movePlayer()
{
    player->move(keyPressing);
}


void Gamesys::playerShootBullet()
{


    //在玩家位置创建子弹
    QPointF shootPos = QPointF(player->sceneBoundingRect().right(),player->sceneBoundingRect().center().y());

    Bullet * bullet = gObjectPool::Instance()->takeBullet();
    bullet->setPos(shootPos);
    bullet->setType(BulletType::P);

    bulletList.append(bullet);

    //添加到场景
    scene->addItem(bullet);

}

void Gamesys::createEnemy()
{
    //随机生成enemy
    int rand = QRandomGenerator::global()->bounded(0,550);
    QPointF generatePos = QPointF(scene->sceneRect().right(),rand);

    Enemy * enemy = gObjectPool::Instance()->takeEnemy();
    enemy->setPos(generatePos);

    enemyList.append(enemy);

    //添加到场景
    scene->addItem(enemy);

}

//?
void Gamesys::moveBullet()
{
    for (Bullet * b : bulletList) {
        b->move();

        //越界
        if(b->x() >= Gsettings::screenWidth){
            gObjectPool::Instance()->recycle(b);
            scene->removeItem(b);
            bulletList.removeOne(b);
        }
    }

    checkIfCollide();
}

//?
void Gamesys::moveEnemy()
{
    for (Enemy * e : enemyList) {
        e->move();

        if(e->sceneBoundingRect().right() < 0){
            gObjectPool::Instance()->recycle(e);
            scene->removeItem(e);
            enemyList.removeOne(e);
        }
    }
}

void Gamesys::checkIfCollide()
{


    for (Bullet* b : bulletList) {
        for (Enemy * e : enemyList) {
            if(b->collidesWithItem(e)){
                scene->removeItem(e);
                scene->removeItem(b);

                gObjectPool::Instance()->recycle(b);
                gObjectPool::Instance()->recycle(e);

                bulletList.removeOne(b);
                enemyList.removeOne(e);
            }
        }
    }
}




