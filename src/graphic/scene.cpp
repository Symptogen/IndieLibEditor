//! Part of the IndieLib Level Editor
/*!\file scene.cpp
 *\author Cecilia
 *\date 16-12-2013
 *\todo
*/
#include <QGraphicsItemGroup>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include "scene.h"

Scene::Scene(QStringList layerList, QObject *parent):
    QGraphicsScene(parent)
{
    m_defaultImagePath = "C:/Users/Cecilia/Pictures/editorResources/set3/bearPurple.png";

    //Create all the layers corresponding to the categories in the projet properties
    for(int i = 0; i<layerList.count(); ++i){
        this->createLayer(layerList[i]);
    }

    //TEMPORARY
    QString path = "C:/Users/Cecilia/Pictures/editorResources/set3/background.png";
    //this->setBackground(path);
    QPixmap* imageBackground = new QPixmap(path);
    QGraphicsPixmapItem* background= new QGraphicsPixmapItem(*imageBackground);
    this->addItem(background);

}

//! Creates an entity and alert the panel to do so
void Scene::newEntity(QString name){

    GraphicalItem* item = new GraphicalItem(name, m_defaultImagePath);
    m_graphicalItemList.append(item);
    qDebug() << "newentity : " << m_graphicalItemList.size();
    this->addItem(item);


    qDebug() << "New Entity in the scene aaaand it's gone !";
}

//! TEMPORARY
void Scene::setBackground(QString path){
    QPixmap* image = new QPixmap(path);
    QGraphicsPixmapItem* background = new QGraphicsPixmapItem(*image);
    this->addItem(background);

}

void Scene::createLayer(QString name){
    QGraphicsItemGroup* group = new QGraphicsItemGroup();
    m_itemGroupsList.insert(name, group);
}

QGraphicsItemGroup* Scene::getGroup(QString name){
    return m_itemGroupsList.find(name).value();
}

