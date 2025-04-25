#include "bullet.h"
#include <QDebug>
#include <QGraphicsView>



Bullet::Bullet(QGraphicsPixmapItem *parent):gameObj{parent}{}


void Bullet::beginAt(QPointF pos, int type)
{
    switch (type) {
    case BulletType::P :
        setPixmap(QPixmap(":/items/src/Items/wp_ball.png"));
        break;

    case BulletType::E :
        setPixmap(QPixmap(":/items/src/Items/wp_enemy.png"));
        break;
    }

    setScale(0.1);
    setPos(pos);
}




void Bullet::move()
{
    moveBy(Gsettings::bulletMoveSpeed,0);
}
