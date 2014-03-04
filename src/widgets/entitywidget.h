//! Part of the IndieLib Level Editor
/*!\file entityWidget.h
 *\author Cecilia
 *\date 17-12-2013
 *\todo
*/

#ifndef ENTITYWIDGET_H
#define ENTITYWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QSlider>
#include <QSpinBox>
#include <QGridLayout>
#include "../graphic/graphicalitem.h"

class EntityWidget : public QWidget
{
    Q_OBJECT
public:
    EntityWidget(QWidget *parent=0);
    void init(GraphicalItem *item);

private slots:
    void opacityAboutToChange(int newValue);

private:
    //First part
    GraphicalItem* m_entity;
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

#endif // ENTITYWIDGET_H
