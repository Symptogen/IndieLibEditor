//! Part of the IndieLib Level Editor
/*!\file project.cpp
 *\author Cecilia
 *\date 16-12-2013
*/

#include <QDebug>
#include "project.h"

Project::Project(QString name, QString savePath, QString resourcePath, QStringList layerList)
    : m_name(name), m_savePath(savePath), m_resourcesPath(resourcePath), m_layerList(layerList)
{
}

//! Add a new level to the list of levels
void Project::addLevel(QString name){
    m_levelList << name;
}
