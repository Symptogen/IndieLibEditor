//! Part of the IndieLib Level Editor
/*!\file opacitycommand.cpp
 *\author Cecilia
 *\date 17-12-2013
 *\todo
*/

#include "opacitycommand.h"
#include <QDebug>
#include <QGraphicsScene>

OpacityCommand::OpacityCommand(QGraphicsItem *diagramItem, const int &oldOpacity, QUndoCommand *parent):
    QUndoCommand(parent)
{
    m_graphicsItem = diagramItem;
    m_newOpacity = diagramItem->opacity();
    m_oldOpacity = oldOpacity;
}

void OpacityCommand::undo()
 {
    qDebug() << "undo Opacity " ;
    m_graphicsItem->setOpacity(m_oldOpacity);
    m_graphicsItem->scene()->update();
    setText(QObject::tr("Change Opacity"));
 }

void OpacityCommand::redo()
 {
    qDebug() << "redo Opacity " ;
    m_graphicsItem->setOpacity(m_newOpacity);
    setText(QObject::tr("Change Opacity"));
 }
