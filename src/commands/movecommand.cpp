#include "movecommand.h"
#include <QGraphicsScene>
#include <QDebug>

MoveCommand::MoveCommand(QGraphicsItem *diagramItem, const QPointF &oldPos, QUndoCommand *parent)
     : QUndoCommand(parent)
 {

     m_graphicsItem = diagramItem;
     m_newPos = diagramItem->pos();
     m_oldPos = oldPos;
 }

void MoveCommand::undo()
 {
    qDebug() << "undo " ;
    m_graphicsItem->setPos(m_oldPos);
    m_graphicsItem->scene()->update();
    setText(QObject::tr("Move"));
 }

void MoveCommand::redo()
 {
    qDebug() << "redo : new Pos = " << m_newPos ;
    m_graphicsItem->setPos(m_newPos);
    setText(QObject::tr("Move"));
 }

bool MoveCommand::mergeWith(const QUndoCommand *command)
 {
     const MoveCommand *moveCommand = static_cast<const MoveCommand *>(command);
     QGraphicsItem *item = moveCommand->m_graphicsItem;

     if (m_graphicsItem != item)
     return false;

     m_newPos = item->pos();
     setText(QObject::tr("Move %1"));

     return true;
 }

