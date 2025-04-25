#ifndef ROLE_H
#define ROLE_H


#include "gameObj.h"


class Role : public gameObj
{

public:
    Role(QGraphicsPixmapItem *parent = nullptr);

    virtual int getHP();

protected:
    int HP;
};





class Player : public Role
{

public:

    Player(QGraphicsPixmapItem *parent = nullptr);

    void move(QList<int>&);

    void beHitByEnemy();

    void setHP(int);

    int getHP();

};





class Enemy : public Role
{

public:
    Enemy(QGraphicsPixmapItem *parent = nullptr);
    ~Enemy();

    //受击
    void beshot();

    void setHP(int);

    void move();
private:

};

#endif // ROLE_H
