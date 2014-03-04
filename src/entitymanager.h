#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "singleton.h"
#include <QVector>
#include "widgets/entitywidget.h"
#include "graphic/graphicalitem.h"

class EntityManager: public Singleton<EntityManager> {

    // Friend to use private constructor/destructor
    friend class Singleton<EntityManager>;

public:
    void addEntity(GraphicalItem* graphic, EntityWidget* entityWidget);
    void addGraphicalItem(GraphicalItem* graphic);
    void addEntityWidgetToExistingEntity(int index, EntityWidget* entityWidget);
    EntityWidget* findEntityWidgetWithGraphicalItem(GraphicalItem* item);

    inline QVector<GraphicalItem*> getGraphicalItemArray() const {return m_graphicalItemArray;}
    inline QVector<EntityWidget*> getEntityWidgetArray() const { return m_entityWidgetArray;}

private:
    QVector<GraphicalItem*> m_graphicalItemArray;
    //QVector<PhysicalItem*> m_physicalItemArray;
    QVector<EntityWidget*> m_entityWidgetArray;
    //QVector<PhysicalWidget*> m_physicalWidgetArray;


    EntityManager*	m_pEntityManager;

    /**
    * Private constructor (because it is a singleton)
    * @see EntityManager()
    * @see ~EntityManager()
    */
    EntityManager();

    /**
    * Private destructor (because it is a singleton)
    * @see EntityManager()
    * @see ~EntityManager()
    */
    ~EntityManager(){}
};

#endif // ENTITYMANAGER_H
