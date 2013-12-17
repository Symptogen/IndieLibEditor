#ifndef INVOKER_H
#define INVOKER_H

#include <QUndoStack>
#include "movecommand.h"

class Invoker
{
public:
    Invoker();

public slots:
    void itemMoved(QGraphicsItem *movedItem, const QPointF &oldPosition);

    QUndoStack* getStack(){return m_undoStack;}

private:
    QUndoStack* m_undoStack;

};

#endif // INVOKER_H
