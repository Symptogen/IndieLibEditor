//! Part of the IndieLib Level Editor
/*!\file elementpanel.cpp
 *\author Cecilia
 *\date 15-12-2013
 *\todo
 *\sa HierarchyPanel
*/

#include "elementpanel.h"
#include <QGraphicsItem>
#include "entityelementpanel.h"
#include "../graphic/graphicalitem.h"
#include <QDebug>

ElementPanel::ElementPanel()
{
    this->setMinimumWidth(200);
    this->setMaximumWidth(300);
    this->setMinimumHeight(300);
    m_entityStacked = new QStackedWidget();
    m_backgroundStacked = new QStackedWidget();
    this->addWidget(m_entityStacked);
    this->addWidget(m_backgroundStacked);
    this->setCurrentWidget(m_entityStacked);
}

void ElementPanel::setScene(Scene* scene){
    m_scene = scene;
    this->initElementPanel();
}

//! This function is called when a project and a level have been created or opened
void ElementPanel::initElementPanel(){
    //Initialise the widget with the already existing items if there are
    if (!m_scene->items().isEmpty()){
        for (int i = 0; i < m_scene->items().count(); ++i) {

            //Creates an entity panel
            if(m_scene->items().at(i)->type() == QGraphicsItem::UserType + 1){
                QWidget* widget = new EntityElementPanel(qgraphicsitem_cast<GraphicalItem*>(m_scene->items().at(i)));
                this->m_entityStacked->addWidget(widget);
            }
            //creates a Background panel
            //else {
            //    QWidget* widget = new BackgroundElementPanel(m_scene->items().at(i));
            //    this->m_entityStacked->addWidget(widget);
            //}
        }
    }
}

//! Creates a new panel because an entity was added to the scene
void ElementPanel::newEntity(GraphicalItem* item){
    qDebug() << "new entity received in Element panel !";
    if(item->type() == QGraphicsItem::UserType + 1){
        qDebug() << "creation of the panel ...";
        QWidget* widget = new EntityElementPanel(item);
        this->m_entityStacked->addWidget(widget);
        this->m_entityStacked->setCurrentWidget(widget);
    }
    //else
}


