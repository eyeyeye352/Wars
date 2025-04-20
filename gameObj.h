#ifndef GAMEOBJ_H
#define GAMEOBJ_H


#include "Gsettings.h"


class gameObj : public QGraphicsPixmapItem
{

public:
    gameObj(QGraphicsPixmapItem *parent = nullptr):QGraphicsPixmapItem{parent}{}
    virtual void move(){}
};





#endif // GAMEOBJ_H
