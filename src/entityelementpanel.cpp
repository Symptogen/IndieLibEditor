//! Part of the IndieLib Level Editor
/*!\file entityelementpanel.cpp
 *\author Cecilia
 *\date 17-12-2013
 *\todo
*/

#include "entityelementpanel.h"


EntityElementPanel::EntityElementPanel(Entity *item)
{
    m_entity = item;
    this->init();
}

void EntityElementPanel::init(){

    QVBoxLayout* layout = new QVBoxLayout();

    //First part of the widget : description
    m_type = new QLabel("ENTITY");
    m_name = new QLabel(m_entity->name());
    m_thumbnail = new QLabel();
    m_thumbnail->setPixmap(m_entity->pixmap());
    m_changePixmapButton = new QPushButton("Change", this);

    m_firstLayout = new QGridLayout();
    m_firstLayout->addWidget(m_type,0,0);
    m_firstLayout->addWidget(m_name,1,0);
    m_firstLayout->addWidget(m_thumbnail, 2,0);
    m_firstLayout->addWidget(m_changePixmapButton,2,1);


    //Second part : geometry
    QLabel* geometry = new QLabel("Geometry");
    QLabel* position = new QLabel("Position");
    QLabel* x = new QLabel("x");
    QLabel* y = new QLabel("y");
    m_posX = new QSpinBox(this);
    //TODO : find a way to grab max from the scene rect width
    m_posX->setRange(0, 1000);
    m_posX->setSingleStep(1);
    m_posX->setSuffix("px");

    m_posY = new QSpinBox();
    //TODO : find a way to grab max from the scene rect width
    m_posY->setRange(0, 1000);
    m_posY->setSingleStep(1);
    m_posY->setSuffix("px");

    QLabel* scale = new QLabel("Scale : ");
    m_scaleX = new QSpinBox(this);
    m_scaleX->setRange(0, 10);
    m_scaleX->setSingleStep(1);

    m_scaleY = new QSpinBox(this);
    m_scaleY->setRange(0, 10);
    m_scaleY->setSingleStep(1);

    QLabel* rotation = new QLabel("Rotation : ");

    m_rotation = new QSpinBox(this);
    m_rotation->setRange(0, 360);
    m_rotation->setSingleStep(1);
    m_rotation->setSuffix("°");

    m_secondLayout = new QGridLayout();
    m_secondLayout->addWidget(geometry, 0, 0);
    m_secondLayout->addWidget(position, 1, 0);
    m_secondLayout->addWidget(x, 1, 1);
    m_secondLayout->addWidget(m_posX, 1, 2);
    m_secondLayout->addWidget(y, 1, 3);
    m_secondLayout->addWidget(m_posY, 1, 4);
    m_secondLayout->addWidget(scale, 2, 0);
    m_secondLayout->addWidget(x, 2, 1);
    m_secondLayout->addWidget(m_scaleX, 2, 2);
    m_secondLayout->addWidget(y, 2, 3);
    m_secondLayout->addWidget(m_scaleY, 2, 4);
    m_secondLayout->addWidget(rotation, 3, 0);
    m_secondLayout->addWidget(m_rotation, 3, 1);


    //Third Part : graphics

    layout->addLayout(m_firstLayout);
    layout->addLayout(m_secondLayout);
    layout->addLayout(m_thirdLayout);

    this->setLayout(layout);
}
