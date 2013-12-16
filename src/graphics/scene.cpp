//! Part of the IndieLib Level Editor
/*!\file scene.cpp
 *\author Cecilia
 *\date 16-12-2013
 *\todo
*/
#include <QGraphicsItemGroup>
#include "scene.h"

Scene::Scene(QStringList layerList, QObject *parent):
    QGraphicsScene(parent)
{
    //Create all the layers corresponding to the categories in the projet properties
    for(int i = 0; i<layerList.count(); ++i){
        this->createLayer(layerList[i]);
    }
}

void Scene::createLayer(QString name){
    QGraphicsItemGroup* group = new QGraphicsItemGroup();
    m_itemGroupsList.insert(name, group);
}

QGraphicsItemGroup* Scene::getGroup(QString name){
    return m_itemGroupsList.find(name).value();
}
