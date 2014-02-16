#ifndef IOMODULE_H
#define IOMODULE_H

#include "level.h"
#include "graphics/scene.h"

class IOModule
{
public:
    IOModule(Scene* scene);

    void saveTileset(QString path, QString savePath);
    void saveLevel(Level* level, QString path);

private:
    Scene* m_scene;
    QString* m_saveTilesetPath;
};

#endif // IOMODULE_H
