//! Part of the IndieLib Level Editor
/*!\file entity.cpp
 *\author Cecilia
 *\date 16-12-2013
 *\todo
*/

#include "entity.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

Entity::Entity(QPixmap pixmap)
{
    enum { Type = UserType + 1 };
    this->setPixmap(pixmap);
    this->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemSendsGeometryChanges);
}

void Entity::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        this->setPos(event->scenePos().x() - this->mapFromScene(event->scenePos()).x(), event->scenePos().y() - this->mapFromScene(event->scenePos()).y());
    }
}
