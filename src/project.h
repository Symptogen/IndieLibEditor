//! Part of the IndieLib Level Editor
/*!\file project.h
 *\author Cecilia
 *\date 16-12-2013
 *\details The project correspond to a game the user edit the levels for. A project know where are the resources of the game (taken
 *from the developement folders), what are the previous levels created for this game, if there is a model for new level to copy, and
 *what are the "categories" used for the layers. A level cannot be created if it doesn't belong to a project.
*/

#ifndef PROJECT_H
#define PROJECT_H

#include <QString>
#include <QStringList>

class Project
{
public:
    Project(QString name, QString resourcePath, QStringList layerList);

    //void addLayerItem(QString name, int pos);
    void addLevel(QString name);

    //---------- Getter / Setter----------- //
    void setResourcesPath(QString path){m_resourcesPath = path;}
    void setCurrentLevel(QString level){m_currentLevel = level;}
    QStringList getLevelList(){return m_levelList;}
    QStringList getLayerList(){return m_layerList;}
    QString getSavePath(){return m_savePath;}
    QString getName(){return m_name;}
    QString getResourcesPath(){return m_resourcesPath;}
    QString getCurrentLevel(){return m_currentLevel;}

private:
    QString m_name;
    QString m_savePath;
    QString m_resourcesPath;
    QStringList  m_levelList;
    QStringList m_layerList;
    QString m_currentLevel;

};

#endif // PROJECT_H
