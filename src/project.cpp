//! Part of the IndieLib Level Editor
/*!\file project.cpp
 *\author Cecilia
 *\date 16-12-2013
*/

#include <QDebug>
#include "project.h"

#include <QDir>

Project::Project(QString name, QString resourcePath, QStringList layerList)
    : m_name(name), m_resourcesPath(resourcePath), m_layerList(layerList)
{
    //Create a sub-directory for the levels
    QDir* resourcesDir = new QDir(m_resourcesPath);
    resourcesDir->mkdir("levels");
    m_savePath = m_resourcesPath + QDir::separator() + "levels";
}

//! Add a new level to the list of levels
void Project::addLevel(QString name){
    m_levelList << name;
}
