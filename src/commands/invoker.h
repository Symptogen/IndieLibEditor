#ifndef INVOKER_H
#define INVOKER_H

#include <QUndoStack>
#include "movecommand.h"
#include "opacitycommand.h"

class Invoker
{
public:
    Invoker();

public slots:
    void itemMoved(QGraphicsItem *movedItem, const QPointF &oldPosition);
    void opacityChanged(QGraphicsItem *item, const int &oldOpacity);

    QUndoStack* getStack(){return m_undoStack;}

private:
    QUndoStack* m_undoStack;

};

#endif // INVOKER_H
