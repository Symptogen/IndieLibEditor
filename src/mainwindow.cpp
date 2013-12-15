//! Part of the IndieLib Level Editor
/*!\file mainwindow.cpp
 *\author Cecilia
 *\date 15-12-2013
*/

#include "mainwindow.h"
#include <QStatusBar>
#include <QMenuBar>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //Restore the previous geometry
    QSettings settings("Symptogene Team", "Level Editor");
    restoreGeometry(settings.value("geometry").toByteArray());
    //restoreState(settings.value("state").toByteArray());

    this->initDockWidgets();
    this->initStatusBar();
    this->initActions();
    this->initMenu();
}

MainWindow::~MainWindow()
{
    
}

//! Store the geometry and state of the application before closing
void MainWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings("Symptogene Team", "Level Editor");
    settings.setValue("geometry", saveGeometry());
    //settings.setValue("state", saveState());
    QMainWindow::closeEvent(event);
}

//!Function that instanciate the two dock widgets needed for the editor : the element dock and the hierarchy dock
void MainWindow::initDockWidgets(){

    //Element Dock Widget
    m_hierarchyPanel = new HierarchyPanel();
    m_hierarchyDock = new QDockWidget(this->tr("Hierarchy Panel"), this);
    m_hierarchyDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    m_hierarchyDock->setWidget(m_hierarchyPanel);
    m_hierarchyDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);

    //Element Dock Widget
    m_elementPanel = new ElementPanel();
    m_elementDock = new QDockWidget(this->tr("Element Panel"), this);
    m_elementDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    m_elementDock->setWidget(m_elementPanel);
    m_elementDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);

    //Viewer Widget
    m_viewer = new Viewer();
    m_viewerDock = new QDockWidget(this->tr("Viewer"), this);
    m_viewerDock->setAllowedAreas(Qt::LeftDockWidgetArea);
    m_viewerDock->setWidget(m_viewer);
    m_viewerDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);

    //Add the dock to the main window
    this->addDockWidget(Qt::LeftDockWidgetArea, m_viewerDock);
    this->addDockWidget(Qt::RightDockWidgetArea, m_hierarchyDock);
    this->addDockWidget(Qt::RightDockWidgetArea, m_elementDock);
}

//!Function that set up the status bar
void MainWindow::initStatusBar(){
    this->statusBar()->showMessage(this->tr("Ready"));
}

//!Function that set up the menu and the actions that are contained into it
void MainWindow::initMenu(){

    //File menu
     m_fileMenu = this->menuBar()->addMenu(this->tr("&File"));
     m_fileMenu->addAction(m_newLevelAction);
     m_fileMenu->addSeparator();
     m_fileMenu->addAction(m_loadLevelAction);
     m_fileMenu->addAction(m_saveLevelAction);
     m_fileMenu->addSeparator();
     m_fileMenu->addAction(m_quitAction);

     //About Menu
     m_aboutMenu = this->menuBar()->addMenu(this->tr("&About"));

}

//!Create the actions that are used in the MainWindow menu
void MainWindow::initActions(){

    //New level
    m_newLevelAction = new QAction(this->tr("New Level"), this);
    m_newLevelAction->setShortcut(QKeySequence::New);
    m_newLevelAction->setStatusTip(this->tr("Create a new empty project"));
    this->connect(m_newLevelAction, SIGNAL(triggered()), this, SLOT(newLevel()));

    //Load level
    m_loadLevelAction = new QAction(this->tr("Load Level"), this);
    m_loadLevelAction->setShortcut(QKeySequence::Open);
    m_loadLevelAction->setStatusTip(this->tr("Open a project and load the level"));
    this->connect(m_loadLevelAction, SIGNAL(triggered()), this, SLOT(loadLevel()));

    //Save level
    m_saveLevelAction = new QAction(this->tr("Save Level"), this);
    m_saveLevelAction->setShortcut(QKeySequence::Save);
    m_saveLevelAction->setStatusTip(this->tr("Save the current level"));
    this->connect(m_saveLevelAction, SIGNAL(triggered()), this, SLOT(saveLevel()));

    //Quit
    m_quitAction = new QAction(this->tr("Quit"), this);
    m_quitAction->setShortcut(QKeySequence::Quit);
    m_quitAction->setStatusTip(this->tr("Close the editor"));
    this->connect(m_quitAction, SIGNAL(triggered()), this, SLOT(closeEvent()));
}

void MainWindow::loadLevel(){

}

void MainWindow::saveLevel(){


}

void MainWindow::newLevel(){

}
