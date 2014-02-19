//! Part of the IndieLib Level Editor
/*!\file entity.h
 *\author Cecilia
 *\date 16-12-2013
 *\todo
*/

#ifndef INDIELIB_EDITOR_GRAPHIC_GRAPHICAL_ITEM_H
#define INDIELIB_EDITOR_GRAPHIC_GRAPHICAL_ITEM_H

#include <QGraphicsPixmapItem>

class GraphicalItem : public QGraphicsPixmapItem
{
public:
    enum { Type = UserType + 1 };
    GraphicalItem(QString name, QString filePath);
    int type() const{return Type;}

    //-------------- Event Handlers ---------------- //
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    //----------- Getter /Setter ---------------- //
    QString name(){return m_name;}
    void setName(QString name){m_name = name;}
    QString getFilePath() const {return m_filePath;}

private:
     QPointF m_oldPos;
     qreal m_oldOpacity;
     QString m_name;
     QString m_filePath;
};
#endif // INDIELIB_EDITOR_GRAPHICAL_ITEM_H
