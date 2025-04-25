#ifndef BULLET_H
#define BULLET_H

#include "gameObj.h"

enum BulletType{
    //普通子弹（玩家）
    P,
    //普通子弹（怪物）
    E
};

class Bullet : public gameObj
{

public:

    Bullet(QGraphicsPixmapItem *parent = nullptr);

    //生成位置、子弹类型
    void beginAt(QPointF pos,int type);

    void move();
};

#endif // BULLET_H
