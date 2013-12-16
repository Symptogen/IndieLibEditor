//! Part of the IndieLib Level Editor
/*!\file viewer.h
 *\author Cecilia
 *\date 15-12-2013
 *\todo
*/

#ifndef VIEWER_H
#define VIEWER_H

#include <QGraphicsView>

class Viewer : public QGraphicsView
{
public:
    Viewer(QGraphicsScene * scene, QWidget * parent = 0);
};

#endif // VIEWER_H
