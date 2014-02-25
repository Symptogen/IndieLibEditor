#ifndef IOMODULE_H
#define IOMODULE_H

#include "graphic/scene.h"
#include <QtXml>

class IOModule
{
public:
    IOModule(){}

    void saveTileset(QString resourcesPath, QString savePath);
    void saveLevel(QString path, Scene *scene);
    void loadLevel();

private:
    QString* m_saveTilesetPath;
};

#endif // IOMODULE_H
