//! Part of the IndieLib Level Editor
/*!\file graphicalitem.cpp
 *\author Cecilia
 *\date 16-12-2013
 *\todo
*/

#include "graphicalitem.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

GraphicalItem::GraphicalItem(QString name, QString filePath)
{
    this->setName(name);
    QPixmap image(filePath);
    this->setPixmap(image);
    this->acceptHoverEvents();
    this->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemSendsGeometryChanges);

    m_oldOpacity = this->opacity();
    m_filePath = filePath;
}

//! Store the position of the GraphicalItem before a movement appears
void GraphicalItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        m_oldPos = this->pos();
    }
}

QVariant GraphicalItem::itemChange(GraphicsItemChange change, const QVariant &value){
    //! Call the undo manager when the moving is done
    if (change == QGraphicsItem::ItemPositionHasChanged){
        //this->getScene()->invoker()->itemMoved(this, m_oldPos);
    }
    if (change == QGraphicsItem::ItemOpacityHasChanged){
        //this->getScene()->invoker()->opacityChanged(this, m_oldOpacity);
        m_oldOpacity = this->opacity();
    }

    return QGraphicsItem::itemChange(change, value);
}

