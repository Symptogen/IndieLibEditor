#ifndef _INDIELIB_EDITOR_MAINWINDOW_H
#define _INDIELIB_EDITOR_MAINWINDOW_H

#include <QMainWindow>
#include "elementpanel.h"
#include "hierarchypanel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    ElementPanel* m_elementPanel;
    HierarchyPanel* m_hierarchyPanel;
};

#endif // _INDIELIB_EDITOR_MAINWINDOW_H
