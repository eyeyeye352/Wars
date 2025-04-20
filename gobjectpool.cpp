#include "gobjectpool.h"


gObjectPool * gObjectPool::instance = nullptr;

gObjectPool::~gObjectPool()
{
    for (int x = 0; x < bulletPool.size(); ++x) {
        Bullet * b = bulletPool.dequeue();
        delete b;
    }

    for (int x = 0; x < enemyPool.size(); ++x) {
        Enemy * e = enemyPool.dequeue();
        delete e;
    }
}

void gObjectPool::init()
{
    for (int x = 0; x < 20; ++x) {
        Bullet * b = new Bullet();
        Enemy * e = new Enemy();
        bulletPool.enqueue(b);
        enemyPool.enqueue(e);
    }

}

Bullet *gObjectPool::takeBullet()
{
    Bullet * b = bulletPool.dequeue();
    return b;
}

Enemy *gObjectPool::takeEnemy()
{
    Enemy* e = enemyPool.dequeue();
    return e;
}

void gObjectPool::recycle(Bullet *obj)
{
    bulletPool.enqueue(obj);
}

void gObjectPool::recycle(Enemy *obj)
{
    enemyPool.enqueue(obj);
}
