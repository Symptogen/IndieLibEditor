//! Part of the IndieLib Level Editor
/*!\file entityelementpanel.cpp
 *\author Cecilia
 *\date 17-12-2013
 *\todo
*/

#include "entityelementpanel.h"
#include <QLineEdit>
#include <QDebug>

EntityElementPanel::EntityElementPanel(GraphicalItem* item, QWidget* parent):
    QWidget(parent)
{
    this->setMinimumWidth(50);
    this->setMaximumWidth(200);
    this->setMinimumHeight(100);
    this->setMaximumHeight(400);
    m_entity = item;
    this->init();
    //this->setStyleSheet("background: #222222;");
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
    m_firstLayout->addWidget(m_thumbnail, 2, 0);
    m_firstLayout->addWidget(m_changePixmapButton,2, 1);


    //Second part : geometry
    QLabel* geometry = new QLabel("Geometry");
    QLabel* position = new QLabel("Position");
    QLabel* x = new QLabel("x");
    QLabel* y = new QLabel("y");
    m_posX = new QSpinBox(this);
    m_posX->setValue(m_entity->pos().x());
    //TODO : find a way to grab max from the scene rect width
    //m_posX->setRange(0, m_entity->scene()->width());
    m_posX->setSingleStep(1);
    m_posX->setSuffix("px");

    m_posY = new QSpinBox();
    m_posX->setValue(m_entity->pos().y());
    //TODO : find a way to grab max from the scene rect width
    //m_posY->setRange(0, m_entity->scene()->width());
    m_posY->setSingleStep(1);
    m_posY->setSuffix("px");

    QLabel* scale = new QLabel("Scale : ");
    m_scaleX = new QSpinBox(this);
    m_scaleX->setValue(1);
    m_scaleX->setRange(0, 10);
    m_scaleX->setSingleStep(1);

    m_scaleY = new QSpinBox(this);
    m_scaleY->setValue(1);
    m_scaleY->setRange(0, 10);
    m_scaleY->setSingleStep(1);

    QLabel* rotation = new QLabel("Rotation : ");

    m_rotation = new QSpinBox(this);
    m_rotation->setValue(0);
    //QObject::connect(m_rotation, SIGNAL(valueChanged(int)), m_entity, SLOT(setRotation(int)));
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
    //Just graphics for now... TODO
    m_thirdLayout = new QGridLayout();
    QLabel* graphics = new QLabel("Graphics");
    m_tiling = new QCheckBox("Tiling", this);

    //Opacity stuff
    QLabel* opacity = new QLabel("Opacity");
    QLineEdit* opacityLineEdit = new QLineEdit();
    opacityLineEdit->setValidator( new QIntValidator(0, 100, this) );
    opacityLineEdit->setMaximumWidth(60);
    m_opacity = new QSlider(Qt::Horizontal, this);
    m_opacity->setRange(0, 100);
    m_opacity->setPageStep(10);
    qDebug() << "entity opacity : " << m_entity->opacity();
    m_opacity->setValue(m_entity->opacity()*100);
    connect(m_opacity, SIGNAL(valueChanged(int)), this, SLOT(opacityAboutToChange(int)));

    QLabel* zindex = new QLabel("z-index");
    QLineEdit* zindexLineEdit = new QLineEdit();
    zindexLineEdit->setMaximumWidth(60);
    QPushButton* bringForward = new QPushButton("+", this);
    bringForward->setMaximumWidth(30);
    QPushButton* sendBackward = new QPushButton("-", this);
    sendBackward->setMaximumWidth(30);

    m_thirdLayout->addWidget(graphics, 0, 0);
    m_thirdLayout->addWidget(m_tiling, 1, 0);
    m_thirdLayout->addWidget(opacity, 2, 0);
    m_thirdLayout->addWidget(opacityLineEdit, 2, 4);
    m_thirdLayout->addWidget(m_opacity, 3, 0, 1, 5);
    m_thirdLayout->addWidget(zindex, 4, 0);
    m_thirdLayout->addWidget(zindexLineEdit, 4, 1);
    m_thirdLayout->addWidget(bringForward, 4, 2);
    m_thirdLayout->addWidget(sendBackward, 4, 3);

    layout->addLayout(m_firstLayout);
    layout->addLayout(m_secondLayout);
    layout->addLayout(m_thirdLayout);
    layout->setStretchFactor(m_firstLayout, 1);
    layout->setStretchFactor(m_secondLayout, 2);
    layout->setStretchFactor(m_thirdLayout, 2);

    this->setLayout(layout);
}

//! Slot to connect the opacity slider and the Invoker
void EntityElementPanel::opacityAboutToChange(int newValue){
    m_entity->setOpacity(newValue*1.0/100.0);
}
