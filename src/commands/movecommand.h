#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include <QUndoCommand>
#include <QGraphicsItem>

class MoveCommand : public QUndoCommand
{
public:
    enum { Id = 1234 };

    MoveCommand(QGraphicsItem *diagramItem, const QPointF &oldPos,QUndoCommand *parent = 0);
    void undo();
    void redo();
    bool mergeWith(const QUndoCommand *command);
    int id() const { return Id; }


private:
    QGraphicsItem* m_graphicsItem;
    QPointF m_newPos;
    QPointF m_oldPos;
};

#endif // MOVECOMMAND_H
