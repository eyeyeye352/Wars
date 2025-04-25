#include "gobjectpool.h"


gObjectPool * gObjectPool::instance = nullptr;

gObjectPool::gObjectPool(QObject *parent)
{
    for (int x = 0; x < 20; ++x) {
        bulletPool.enqueue(new Bullet);
        enemyPool.enqueue(new Enemy);
    }
}

gObjectPool::~gObjectPool()
{
    for (Bullet* b : bulletPool) {
        delete b;
    }for (Enemy* e : enemyPool) {
        delete e;
    }
}


Bullet *gObjectPool::takeBullet()
{
    return bulletPool.dequeue();
}

Enemy *gObjectPool::takeEnemy()
{
    return enemyPool.dequeue();
}

void gObjectPool::recycle(Bullet *obj)
{
    bulletPool.enqueue(obj);
}

void gObjectPool::recycle(Enemy *obj)
{
    obj->setHP(Gsettings::enemyHP);
    enemyPool.enqueue(obj);
}
