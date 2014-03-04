//! Part of the IndieLib Level Editor
/*!\file PanelWidget.cpp
 *\author Cecilia
 *\date 15-12-2013
 *\todo
 *\sa HierarchyPanel
*/

#include "PanelWidget.h"
#include <QGraphicsItem>
#include "panelwidget.h"
#include "../graphic/graphicalitem.h"
#include <QDebug>
#include "../entitymanager.h"

PanelWidget::PanelWidget()
{
    this->setMinimumWidth(150);
    this->setMaximumWidth(400);
    this->setMinimumHeight(100);
    this->setMaximumHeight(400);

    m_entityWidgetStack = new QStackedWidget();
    m_physicalWidgetStack = new QStackedWidget();
    this->addTab(m_entityWidgetStack, "Entity");
    this->addTab(m_physicalWidgetStack, "Physical");

    this->setCurrentIndex(0);
}

//! This function is called when a project and a level have been created or opened
void PanelWidget::init(){
    //Initialise the widget with the already existing items if there are
//    if (!m_scene->items().isEmpty()){
//        for (int i = 0; i < m_scene->items().count(); ++i) {

//            //Creates an entity panel
//            if(m_scene->items().at(i)->type() == QGraphicsItem::UserType + 1){
//                QWidget* widget = new EntityPanelWidget(qgraphicsitem_cast<GraphicalItem*>(m_scene->items().at(i)));
//                this->m_entityStacked->addWidget(widget);
//            }
//            //creates a Background panel
//            //else {
//            //    QWidget* widget = new BackgroundPanelWidget(m_scene->items().at(i));
//            //    this->m_entityStacked->addWidget(widget);
//            //}
//        }
//    }
}

void PanelWidget::newEntityWidget(){
    EntityWidget* widget = new EntityWidget();
    m_entityWidgetStack->addWidget(widget);
    m_entityWidgetStack->setCurrentWidget(widget);
    EntityManager::getInstance()->addEntityWidgetToExistingEntity(EntityManager::getInstance()->getGraphicalItemArray().size() - 1, widget);
}


