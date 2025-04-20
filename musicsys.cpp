#include "musicsys.h"
#include <QDebug>

MusicSys::MusicSys(QObject *parent)
    : QObject{parent}
{

    bgm = new QMediaPlayer(this);
    shootSound = new QMediaPlayer(this);


    //载入文件
    bgm->setSource(QUrl("qrc:/bgm/src/bgm/Wonderland_Overture.mp3"));
    shootSound->setSource(QUrl("qrc:/FX/src/FX/shoot.mp3"));

    //绑定到扬声器
    QAudioOutput * device1 = new QAudioOutput(this);
    QAudioOutput * device2 = new QAudioOutput(this);
    bgm->setAudioOutput(device1);
    shootSound->setAudioOutput(device2);
    device1->setVolume(Gsettings::musicVolumn);
    device2->setVolume(Gsettings::musicVolumn * 2);

    //裁切射击音效
    connect(shootSound,&QMediaPlayer::positionChanged,[this]{
        if(shootSound->position() >= Gsettings::playerShootInterval){
            shootSound->setPosition(0);
        }
    });


}

