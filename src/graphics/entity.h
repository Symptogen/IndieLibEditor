//! Part of the IndieLib Level Editor
/*!\file entity.h
 *\author Cecilia
 *\date 16-12-2013
 *\todo
*/

#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsPixmapItem>

class Entity : public QGraphicsPixmapItem
{
public:
    Entity(QPixmap pixmap);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    //----------- Getter /Setter ---------------- //
};
#endif // ENTITY_H
