#ifndef GSETTINGS_H
#define GSETTINGS_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QToolButton>
#include <QTimer>
#include <QRectF>
#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QList>
#include <QIcon>
#include <QRandomGenerator>
#include <QQueue>

class Gsettings{

    Gsettings() = default;

public:

    static const int screenUpdateInterval = 16;

    static const int bulletMoveSpeed = 4;

    static const int playerMoveSpeed = 4;

    static const int playerShootInterval = 400;

    static const int backgroundMoveSpeed = 2;

    static const int enemyGenerateInterval = 1500;

    static const int enemyMoveSpeed = 3;

    static const int screenWidth = 800;

    static const int screenHeight = 600;

    static const int musicVolumn = 50;

    static const bool backgroundMovable = true;

    static const int playerHP = 4;

    static const int enemyHP = 4;







};
#endif // GSETTINGS_H
