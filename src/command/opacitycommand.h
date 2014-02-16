//! Part of the IndieLib Level Editor
/*!\file opacitycommand.h
 *\author Cecilia
 *\date 17-12-2013
 *\todo
*/

#ifndef OPACITYCOMMAND_H
#define OPACITYCOMMAND_H

#include <QUndoCommand>
#include <QGraphicsItem>

class OpacityCommand : public QUndoCommand
{
public:
    enum { Id = 1234 +1 };
    OpacityCommand(QGraphicsItem *diagramItem, const int &oldOpacity,QUndoCommand *parent = 0);
    void undo();
    void redo();
    bool mergeWith(const QUndoCommand *command);
    int id() const { return Id; }

private:
    QGraphicsItem* m_graphicsItem;
    qreal m_newOpacity;
    qreal m_oldOpacity;
};

#endif // OPACITYCOMMAND_H
