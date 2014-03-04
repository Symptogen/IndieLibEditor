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
#include <QMimeData>
#include <QDir>
#include <QFileInfo>
#include "scene.h"
#include "../entitymanager.h"

Scene::Scene(QStringList layerList, QObject *parent):
    QGraphicsScene(parent)
{

    //Drag and drop

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

    connect(this, SIGNAL(selectionChanged()), this, SLOT(emitNewSelection()));

}

//! Creates an entity and alert the panel to do so
void Scene::newEntity(QString name, QString path, int x, int y){
    GraphicalItem* item = new GraphicalItem(name, path);
    item->setPos(x, y);
    addItem(item);

    EntityManager::getInstance()->addGraphicalItem(item);
    emit newEntity();
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

void Scene::dragEnterEvent ( QGraphicsSceneDragDropEvent * event )
{

}

void Scene::dragLeaveEvent ( QGraphicsSceneDragDropEvent * event )
{

}

void Scene::dragMoveEvent ( QGraphicsSceneDragDropEvent * event )
{

}


void Scene::dropEvent ( QGraphicsSceneDragDropEvent * event )
{
    QFileInfo* file = new QFileInfo(event->mimeData()->text());
    newEntity(file->baseName(), file->filePath().split("file:///")[1], event->scenePos().x(), event->scenePos().y());
}

void Scene::emitNewSelection(){
    emit selectedItemsChanged(selectedItems());
}

