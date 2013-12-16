//! Part of the IndieLib Level Editor
/*!\file project.cpp
 *\author Cecilia
 *\date 16-12-2013
*/

#include "project.h"

Project::Project(QString name, QString savePath, QString resourcePath, QList<QString> layerList)
    : m_name(name), m_savePath(savePath), m_resourcesPath(resourcePath), m_layerList(layerList)
{
}
