//! Part of the IndieLib Level Editor
/*!\file viewer.cpp
 *\author Cecilia
 *\date 15-12-2013
 *\todo
*/

#include "viewer.h"
#include <QHBoxLayout>
#include <QLabel>

Viewer::Viewer(QWidget *parent):
    QStackedWidget(parent)
{
    //Creates an empty widget to initiate the view nad to tell the user there is no project
    m_emptyWidget = new QWidget();
    QHBoxLayout* layout = new QHBoxLayout();
    QLabel* label = new QLabel(" There is no level to work on. First create a project, then create a level. ");
    layout->addWidget(label);
    m_emptyWidget->setLayout(layout);
    this->addWidget(m_emptyWidget);
    this->setCurrentWidget(m_emptyWidget);
}


//! Construct the graphic view and add to the stack
void Viewer::initView(QGraphicsScene *scene, QWidget *parent){
    m_viewWidget = new QGraphicsView(scene, parent);
    m_viewWidget->setScene(scene);
    m_viewWidget->setMinimumWidth(400);
    m_viewWidget->setMinimumHeight(400);

    this->addWidget(m_viewWidget);
    this->setCurrentWidget(m_viewWidget);
}
