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

Entity::Entity(QString name, QPixmap pixmap)
{
    this->setName(name);
    this->setPixmap(pixmap);
    this->acceptHoverEvents();
    this->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemSendsGeometryChanges);

    m_oldOpacity = this->opacity();
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
    if (change == QGraphicsItem::ItemOpacityHasChanged){
        this->getScene()->invoker()->opacityChanged(this, m_oldOpacity);
        m_oldOpacity = this->opacity();
    }

    return QGraphicsItem::itemChange(change, value);
}

