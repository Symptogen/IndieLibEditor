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
#include "../commands/invoker.h"

class Entity;

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene(QStringList layerList, QObject * parent = 0 );

    void createLayer(QString name);
    QGraphicsItemGroup* getGroup(QString name);
    void setBackground(QString path);
    void newEntity(QString name);

    //---------------- Getter / Setter ------------------ //
    void setInvoker(Invoker* invoker){m_invoker = invoker;}
    Invoker* invoker(){return m_invoker;}

signals:
    void newEntityAdded(Entity* item);

private:
    QHash<QString, QGraphicsItemGroup*> m_itemGroupsList;
    Invoker* m_invoker;
    QString* m_defaultImagePath;


};

#endif // SCENE_H
