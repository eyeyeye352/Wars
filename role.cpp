#include "role.h"
#include "fx.h"

Role::Role(QGraphicsPixmapItem *parent):gameObj{parent}{}

int Role::getHP()
{
    return HP;
}



Player::Player(QGraphicsPixmapItem *parent):Role{parent}{

    HP = Gsettings::playerHP;

    setPixmap(QPixmap(":/items/src/Items/player.png"));
    setScale(0.5);

    setPos(100,100);
}


void Player::move(QList<int>& keyPressing)
{

    QRectF border = scene()->sceneRect();
    QRectF playerRect = sceneBoundingRect();

    for (const int key : keyPressing) {
        switch(key) {
        case Qt::Key_W:
        case Qt::Key_Up:
            moveBy(0, -Gsettings::playerMoveSpeed);
            break;
        case Qt::Key_S:
        case Qt::Key_Down:
            moveBy(0, Gsettings::playerMoveSpeed);
            break;
        case Qt::Key_A:
        case Qt::Key_Left:
            moveBy(-Gsettings::playerMoveSpeed, 0);
            break;
        case Qt::Key_D:
        case Qt::Key_Right:
            moveBy(Gsettings::playerMoveSpeed, 0);
            break;
        }
    }

    //边界检测
    if(playerRect.top() < border.top()) setY(border.top());
    if(playerRect.bottom() > border.bottom()) setY(border.bottom() - playerRect.height());
    if(playerRect.left() < border.left()) setX(border.left());
    if(playerRect.right() > border.right()) setX(border.right() - playerRect.width());
}

void Player::beHitByEnemy()
{
    --HP;
    FX::getInstance()->playerBeHit(this);

}

void Player::setHP(int h)
{
    HP = h;
}

int Player::getHP()
{
    return HP;
}


Enemy::Enemy(QGraphicsPixmapItem *parent):Role{parent}{

    setPixmap(QPixmap(":/items/src/Items/enemy.png"));
    setScale(0.4);
    HP = Gsettings::enemyHP;

}

Enemy::~Enemy()
{
}

void Enemy::beshot()
{
    --HP;
    FX::getInstance()->enemyBeShot(this);
}

void Enemy::setHP(int H)
{
    HP = H;
}


void Enemy::move(){
    moveBy(-Gsettings::enemyMoveSpeed,0);
}



