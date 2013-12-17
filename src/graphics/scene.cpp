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

    QString imagePath = "/home/cecilia/Documents/Editor/resources/images/set3/bearPurple.png";
    QPixmap* image = new QPixmap(imagePath);
    Entity* item = new Entity(*image);
    this->addItem(item);
    item->setScene(this);

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

