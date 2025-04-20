#ifndef ROLE_H
#define ROLE_H


#include "gameObj.h"

class Role : public gameObj
{

public:
    Role(QGraphicsPixmapItem *parent = nullptr);

protected:
    int HP;
};





class Player : public Role
{

public:

    Player(QGraphicsPixmapItem *parent = nullptr);

    void move(QList<int>&);

};





class Enemy : public Role
{

public:
    Enemy(QGraphicsPixmapItem *parent = nullptr);

    //特定位置生成enemy
    void init(QPointF pos);


    void move();
};

#endif // ROLE_H
