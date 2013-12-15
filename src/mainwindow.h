//! Part of the IndieLib Level Editor
/*!\file mainwindow.h
 *\author Cecilia
 *\date 15-12-2013
 *\details This class instanciate the QMainWindow and draw the main widgets of the editor. Currently we use two widgets : the element panel
 *that describe the parameters of the selected element, and the hierarchy panel that gives a global view of all the elements in the
 *current projet and of their relations.
 *\sa ElementPanel, HierarchyPanel
*/

#ifndef _INDIELIB_EDITOR_MAINWINDOW_H
#define _INDIELIB_EDITOR_MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QMenu>
#include "elementpanel.h"
#include "hierarchypanel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initDockWidgets();
    void initStatusBar();
    void initMenu();

private:
    ElementPanel* m_elementPanel;
    HierarchyPanel* m_hierarchyPanel;

    QDockWidget* m_elementDock;
    QDockWidget* m_hierarchyDock;

    //Menus
    QMenu* m_fileMenu;
};

#endif // _INDIELIB_EDITOR_MAINWINDOW_H
