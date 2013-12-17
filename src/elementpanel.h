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
#include "graphics/entity.h"
#include "graphics/scene.h"

class ElementPanel : public QStackedWidget
{
    Q_OBJECT
public:
    ElementPanel();
    void initElementPanel();
    void setScene(Scene* scene);

private slots:
    void newEntity(Entity* item);

private:
    Scene* m_scene;
    QStackedWidget* m_entityStacked;
    QStackedWidget* m_backgroundStacked;
};

#endif // _INDIELIB_EDITOR_ELEMENTPANEL_H
