#include "entitymanager.h"

#include <QDebug>

EntityManager::EntityManager()
{

}

void EntityManager::addEntity(GraphicalItem* graphic, EntityWidget* entityWidget){
    m_graphicalItemArray.append(graphic);
    m_entityWidgetArray.append(entityWidget);
}

void EntityManager::addGraphicalItem(GraphicalItem* graphic){
    m_graphicalItemArray.append(graphic);
    m_entityWidgetArray.append(NULL);
}

void EntityManager::addEntityWidgetToExistingEntity(int index, EntityWidget* entityWidget){
    if(index < m_graphicalItemArray.size()){
        m_entityWidgetArray.insert(index, entityWidget);
        entityWidget->init(m_graphicalItemArray[index]);
    }
}

EntityWidget* EntityManager::findEntityWidgetWithGraphicalItem(GraphicalItem *item){
    EntityWidget* widget = NULL;
    for(int i = 0; i < m_graphicalItemArray.size(); ++i){
        if (m_graphicalItemArray[i] == item){
            widget = m_entityWidgetArray[i];
        }
    }
    return widget;
}
