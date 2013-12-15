//! Part of the IndieLib Level Editor
/*!\file mainwindow.cpp
 *\author Cecilia
 *\date 15-12-2013
*/

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->initDockWidgets();
    this->initStatusBar();
    this->initMenu();
}

MainWindow::~MainWindow()
{
    
}
//!Function that instanciate the two dock widgets needed for the editor : the element dock and the hierarchy dock
MainWindow::initDockWidgets(){

    //Element Dock Widget
    m_hierarchyPanel = HierarchyPanel();
    m_hierarchyDock = new QDockWidget("Hierarchy Panel", this);
    m_hierarchyDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    m_hierarchyDock->setWidget(m_hierarchyPanel);
    m_hierarchyDock->setFeatures(QDockWidget.DockWidgetMovable | QDockWidget.DockWidgetClosable);

    //Element Dock Widget
    m_elementPanel = ElementPanel();
    m_elementDock = new QDockWidget("Element Panel", this);
    m_elementDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    m_elementDock->setWidget(m_elementPanel);
    m_elementDock->setFeatures(QDockWidget.DockWidgetMovable | QDockWidget.DockWidgetClosable);

    //Add the dock to the main window
    this->addDockWidget(Qt::RightDockWidgetArea, m_hierarchyDock);
    this->addDockWidget(Qt::RightDockWidgetArea, m_elementDock);
}

//!Function that set up the status bar
MainWindow::initStatusBar(){
    this->statusBar().showMessage(this->tr("Ready"))
}

//!Function that set up the menu and the actions that are contained into it
MainWindow::initMenu(){
     m_fileMenu = this->menuBar().addMenu(this->tr("&File"));
     m_fileMenu->addAction(m_newLevelAction)

}
