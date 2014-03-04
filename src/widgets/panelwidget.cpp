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

}

void PanelWidget::newEntityWidget(){
    EntityWidget* widget = new EntityWidget();
    m_entityWidgetStack->addWidget(widget);
    m_entityWidgetStack->setCurrentWidget(widget);
    EntityManager::getInstance()->addEntityWidgetToExistingEntity(EntityManager::getInstance()->getGraphicalItemArray().size() - 1, widget);
}

void PanelWidget::setCurrentSelectionWidget(QList<QGraphicsItem *> items){
    if(items.isEmpty()){
        //TODO creates an empty widget for empty selection
    }else if(items.size() > 1){
        //TODO creates an empty widget for multiple selection in waiting for proper multiple modification widget
    }else{
        m_entityWidgetStack->setCurrentWidget(EntityManager::getInstance()->findEntityWidgetWithGraphicalItem(dynamic_cast<GraphicalItem*>(items[0])));
    }
}


