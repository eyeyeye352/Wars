#ifndef GAMESYS_H
#define GAMESYS_H


#include "myScene.h"
#include "bullet.h"
#include "musicsys.h"
#include "role.h"
#include "Gsettings.h"
#include "gobjectpool.h"

class Gamesys : public QWidget
{
    Q_OBJECT

public:
    Gamesys(QWidget *parent = nullptr);
    ~Gamesys();

    void init();

    //按键事件设定keyPressingList移动玩家
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;

public slots:

    void gameStart();

    void moveBackground();
    void movePlayer();
    void playerShootBullet();
    void createEnemy();
    void moveBullet();
    void moveEnemy();

    void gameover();


    void checkIfCollide();

private:

    GameScene * scene;
    StartScene * startScene;
    QGraphicsView *view;
    Player * player;


    QTimer * backgroundMoveTimer;
    QTimer * playerMoveTimer;
    QTimer * shootTimer;
    QTimer * createEnemyTimer;
    QTimer * bulletMoveTimer;
    QTimer * enemyMoveTimer;


    QList<Bullet*> bulletList;
    QList<Enemy*> enemyList;
    QList<int> keyPressing;



    //audios
    MusicSys * Msys;
};
#endif // GAMESYS_H
