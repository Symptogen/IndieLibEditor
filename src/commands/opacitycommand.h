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
    OpacityCommand(QGraphicsItem *diagramItem, const int &oldOpacity,QUndoCommand *parent = 0);
    void undo();
    void redo();

private:
    QGraphicsItem* m_graphicsItem;
    int m_newOpacity;
    int m_oldOpacity;
};

#endif // OPACITYCOMMAND_H
