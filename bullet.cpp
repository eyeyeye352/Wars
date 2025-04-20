#include "bullet.h"
#include <QDebug>
#include <QGraphicsView>



Bullet::Bullet(QGraphicsPixmapItem *parent):gameObj{parent}{
    setPixmap(QPixmap(":/items/src/Items/wp_ball.png"));
    setScale(0.1);
}

Bullet::Bullet(QPointF pos, int type)
{


    switch (type) {
    case BulletType::P :

        setPixmap(QPixmap(":/items/src/Items/wp_ball.png"));
        break;

    case BulletType::E :

        setPixmap(QPixmap(":/items/src/Items/wp_enemy.png"));
        break;
    }

    //子弹图像调整
    setScale(0.1);
    setPos(pos);

}

void Bullet::setType(int type)
{
    switch (type) {
    case BulletType::P :

        setPixmap(QPixmap(":/items/src/Items/wp_ball.png"));
        break;

    case BulletType::E :

        setPixmap(QPixmap(":/items/src/Items/wp_enemy.png"));
        break;
    }
}



void Bullet::move()
{
    moveBy(Gsettings::bulletMoveSpeed,0);
}
