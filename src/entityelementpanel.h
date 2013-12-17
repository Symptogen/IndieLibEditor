//! Part of the IndieLib Level Editor
/*!\file entityelementpanel.h
 *\author Cecilia
 *\date 17-12-2013
 *\todo
*/

#ifndef ENTITYELEMENTPANEL_H
#define ENTITYELEMENTPANEL_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QSlider>
#include <QSpinBox>
#include <QGridLayout>
#include "graphics/entity.h"

class EntityElementPanel : public QWidget
{
public:
    EntityElementPanel(Entity* item);
    void init();

private:

    //First part
    Entity* m_entity;
    QLabel* m_type;
    QLabel* m_name;
    QLabel* m_thumbnail;
    QPushButton* m_changePixmapButton;

    //Second Part
    QSpinBox* m_posX;
    QSpinBox* m_posY;
    QSpinBox* m_scaleX;
    QSpinBox* m_scaleY;
    QSpinBox* m_rotation;

    //Third Part
    QCheckBox* m_tiling;
    QSlider* m_opacity;

    //Layouts
    QGridLayout* m_firstLayout;
    QGridLayout* m_secondLayout;
    QGridLayout* m_thirdLayout;

};

#endif // ENTITYELEMENTPANEL_H
