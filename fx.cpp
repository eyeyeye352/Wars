#include "fx.h"

FX* FX::instance = nullptr;
FX::FX() {}
FX::~FX(){}

void FX::enemyBeShot(Enemy * e)
{
    QGraphicsColorizeEffect* fx = new QGraphicsColorizeEffect;
    fx->setColor(Qt::red);
    fx->setStrength(0.5);

    e->setGraphicsEffect(fx);

    QTimer::singleShot(100, [e,fx] {
        e->setGraphicsEffect(nullptr);
    });
}

void FX::playerBeHit(Player * p)
{
    QGraphicsColorizeEffect* fx = new QGraphicsColorizeEffect;
    fx->setColor(Qt::red);
    fx->setStrength(0.5);

    p->setGraphicsEffect(fx);

    QTimer::singleShot(100, [p,fx] {
        p->setGraphicsEffect(nullptr);
    });
}
