//! Part of the IndieLib Level Editor
/*!\file entity.cpp
 *\author Cecilia
 *\date 16-12-2013
 *\todo
*/

#include "entity.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

Entity::Entity(QPixmap pixmap)
{
    enum { Type = UserType + 1 };
    this->setPixmap(pixmap);
    this->acceptHoverEvents();
    this->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemSendsGeometryChanges);
}

//! Store the position of the entity before a movement appears
void Entity::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        m_oldPos = this->pos();
    }
}

QVariant Entity::itemChange(GraphicsItemChange change, const QVariant &value){
    //! Call the undo manager when the moving is done
    if (change == QGraphicsItem::ItemPositionHasChanged){
        this->getScene()->invoker()->itemMoved(this, m_oldPos);
    }

    return QGraphicsItem::itemChange(change, value);
}
