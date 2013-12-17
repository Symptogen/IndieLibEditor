//! Part of the IndieLib Level Editor
/*!\file entity.h
 *\author Cecilia
 *\date 16-12-2013
 *\todo
*/

#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsPixmapItem>
#include "scene.h"

class Entity : public QGraphicsPixmapItem
{
public:
    Entity(QPixmap pixmap);

    //-------------- Event Handlers ---------------- //
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    //----------- Getter /Setter ---------------- //
    void setScene(Scene* scene){m_scene = scene;}
    Scene* getScene(){return m_scene;}

private:
     QPointF m_oldPos;
     Scene* m_scene;
};
#endif // ENTITY_H
