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
#include "background.h"
#include "scene.h"
#include "entity.h"

Scene::Scene(QStringList layerList, QObject *parent):
    QGraphicsScene(parent)
{
    m_defaultImagePath = new QString( "/home/cecilia/Documents/Editor/resources/images/set3/bearPurple.png");

    //Create all the layers corresponding to the categories in the projet properties
    for(int i = 0; i<layerList.count(); ++i){
        this->createLayer(layerList[i]);
    }

    //TEMPORARY
    QString path = "/home/cecilia/Documents/Editor/resources/images/set3/background.png";
    //this->setBackground(path);
    QPixmap* imageBackground = new QPixmap(path);
    Background* background= new Background(*imageBackground);
    this->addItem(background);

    this->newEntity("Bear");

}

//! Creates an entity and alert the panel to do so
void Scene::newEntity(QString name){

    QPixmap* image = new QPixmap(*m_defaultImagePath);
    Entity* item = new Entity(name, *image);
    this->addItem(item);
    item->setScene(this);

    //Emit a signal
    emit this->newEntityAdded(item);
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

