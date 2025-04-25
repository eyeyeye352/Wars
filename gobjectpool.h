#ifndef GOBJECTPOOL_H
#define GOBJECTPOOL_H

#include <QObject>


#include "bullet.h"
#include "role.h"
#include "Gsettings.h"


class gObjectPool : public QObject
{

    gObjectPool(QObject *parent = nullptr);

    static gObjectPool * instance;

public:

    ~gObjectPool();

    static gObjectPool* Instance(){
        if(instance == nullptr){
            instance = new gObjectPool();
        }
        return instance;
    }

    Bullet* takeBullet();
    Enemy* takeEnemy();

    void recycle(Bullet* obj);
    void recycle(Enemy* obj);


protected:
    //子弹对象池
    QQueue<Bullet *> bulletPool;
    QQueue<Enemy *> enemyPool;

};



#endif // GOBJECTPOOL_H
