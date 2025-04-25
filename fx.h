#ifndef FX_H
#define FX_H

#include "role.h"
#include <QGraphicsColorizeEffect>

class FX
{
    FX();
    ~FX();
    static FX* instance;
public:
    static FX* getInstance(){
        if(instance == nullptr){
            instance = new FX;
        }
        return instance;
    }

    static void delInstance(){
        if(instance != nullptr){
            delete instance;
            instance = nullptr;
        }
    }

    void enemyBeShot(Enemy*);
    void playerBeHit(Player*);

};

#endif // FX_H
