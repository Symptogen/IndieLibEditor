//! Part of the IndieLib Level Editor
/*!\file scene.h
 *\author Cecilia
 *\date 16-12-2013
 *\details  The scene class inherits from the QGrpahicsScene class. It implements the Model View pattern to present a drawing widget.
*/

#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Scene : public QGraphicsScene
{
public:
    Scene(QStringList layerList, QObject * parent = 0 );

    void createLayer(QString name);
    QGraphicsItemGroup* getGroup(QString name);
    void setBackground(QString path);

    // --------------- Event Handlers ------------------- //
    //void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QHash<QString, QGraphicsItemGroup*> m_itemGroupsList;



};

#endif // SCENE_H
