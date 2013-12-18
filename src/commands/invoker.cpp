#include "invoker.h"
#include <QDebug>

Invoker::Invoker()
{
    m_undoStack = new QUndoStack();
}

//!For a move change, store the action in the undo stack list
void Invoker::itemMoved(QGraphicsItem *movedItem, const QPointF &oldPosition)
 {
    //TODO Problem : to much command stored and impossible to undo more than once
    m_undoStack->push(new MoveCommand(movedItem, oldPosition));
 }

//! For a changement of opacity, store the action in the undo stack list
void Invoker::opacityChanged(QGraphicsItem *item,const int &oldOpacity)
{
    QUndoCommand* command = new OpacityCommand(item, oldOpacity);
    m_undoStack->push(command);
}

