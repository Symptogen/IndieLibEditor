//! Part of the IndieLib Level Editor
/*!\file viewer.h
 *\author Cecilia
 *\date 15-12-2013
 *\todo
*/

#ifndef VIEWER_H
#define VIEWER_H

#include <QGraphicsView>
#include <QStackedWidget>

class Viewer : public QStackedWidget
{
public:
    Viewer(QWidget * parent = 0);
    void initView(QGraphicsScene * scene, QWidget * parent = 0);

private:
    QGraphicsView* m_viewWidget;
    QWidget* m_emptyWidget;
};

#endif // VIEWER_H
