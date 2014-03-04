//! Part of the IndieLib Level Editor

#ifndef PANELWIDGET_H
#define PANELWIDGET_H

#include <QTabWidget>
#include <QStackedWidget>
#include "../graphic/graphicalitem.h"
#include "../graphic/scene.h"
#include "../command/invoker.h"

class PanelWidget : public QTabWidget
{
    Q_OBJECT
public:
    PanelWidget();
    void init();

public slots:
    void newEntityWidget();

private:
    QStackedWidget* m_entityWidgetStack;
    QStackedWidget* m_physicalWidgetStack;
};

#endif //PANELWIDGET_H
