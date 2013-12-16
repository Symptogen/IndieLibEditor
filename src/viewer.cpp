//! Part of the IndieLib Level Editor
/*!\file viewer.cpp
 *\author Cecilia
 *\date 15-12-2013
 *\todo
*/

#include "viewer.h"

Viewer::Viewer(QGraphicsScene * scene, QWidget * parent):
    QGraphicsView(parent)
{
    this->setScene(scene);
    this->setMinimumWidth(400);
    this->setMinimumHeight(400);
}
