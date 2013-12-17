#include "movecommand.h"

MoveCommand::MoveCommand(QGraphicsItem *diagramItem, const QPointF &oldPos, QUndoCommand *parent)
     : QUndoCommand(parent)
 {
     m_graphicsItem = diagramItem;
     m_newPos = diagramItem->pos();
     m_oldPos = oldPos;
 }

void MoveCommand::undo()
 {
     m_graphicsItem->setPos(m_oldPos);
     m_graphicsItem->scene()->update();
     setText(QObject::tr("Move %1").arg(createCommandString(m_graphicsItem, m_newPos)));
 }

void MoveCommand::redo()
 {
     m_graphicsItem->setPos(m_newPos);
     setText(QObject::tr("Move %1").arg(createCommandString(m_graphicsItem, m_newPos)));
 }

bool MoveCommand::mergeWith(const QUndoCommand *command)
 {
     const MoveCommand *moveCommand = static_cast<const MoveCommand *>(command);
     QGraphicsItem *item = moveCommand->m_graphicsItem;

     if (m_graphicsItem != item)
     return false;

     m_newPos = item->pos();
     setText(QObject::tr("Move %1").arg(createCommandString(m_graphicsItem, m_newPos)));

     return true;
 }
