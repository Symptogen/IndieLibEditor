#include "invoker.h"
#include <QDebug>

Invoker::Invoker()
{
    m_undoStack = new QUndoStack();
}

void Invoker::itemMoved(QGraphicsItem *movedItem, const QPointF &oldPosition)
 {
    m_undoStack->push(new MoveCommand(movedItem, oldPosition));
 }

