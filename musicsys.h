#ifndef MUSICSYS_H
#define MUSICSYS_H


#include "Gsettings.h"

class MusicSys : public QObject
{
    Q_OBJECT
public:
    explicit MusicSys(QObject *parent = nullptr);
    QMediaPlayer * bgm;
    QMediaPlayer * shootSound;
};

#endif // MUSICSYS_H
