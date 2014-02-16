//! Part of the IndieLib Level Editor
/*!\file elementpanel.h
 *\author Cecilia
 *\date 15-12-2013
 *\todo
 *\sa HierarchyPanel
*/

#ifndef _INDIELIB_EDITOR_ELEMENTPANEL_H
#define _INDIELIB_EDITOR_ELEMENTPANEL_H

#include <QStackedWidget>
#include "../graphic/graphicalitem.h"
#include "../graphic/scene.h"
#include "../command/invoker.h"

class ElementPanel : public QStackedWidget
{
    Q_OBJECT
public:
    ElementPanel();
    void initElementPanel();
    void setScene(Scene* scene);
    Scene* getScene(){return m_scene;}

private slots:
    void newEntity(GraphicalItem* item);

private:
    Scene* m_scene;
    QStackedWidget* m_entityStacked;
    QStackedWidget* m_backgroundStacked;
};

#endif // _INDIELIB_EDITOR_ELEMENTPANEL_H
