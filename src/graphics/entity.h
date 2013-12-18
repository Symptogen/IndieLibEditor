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
    enum { Type = UserType + 1 };
    Entity(QString name, QPixmap pixmap);
    int type() const{return Type;}

    //-------------- Event Handlers ---------------- //
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    //----------- Getter /Setter ---------------- //
    void setScene(Scene* scene){m_scene = scene;}
    Scene* getScene(){return m_scene;}
    QString name(){return m_name;}
    void setName(QString name){m_name = name;}

private:
     QPointF m_oldPos;
     qreal m_oldOpacity;
     Scene* m_scene;
     QString m_name;
};
#endif // ENTITY_H
