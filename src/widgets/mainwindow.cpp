//! Part of the IndieLib Level Editor
/*!\file mainwindow.cpp
 *\author Cecilia
 *\date 15-12-2013
*/

#include "mainwindow.h"
#include <QStatusBar>
#include <QMenuBar>
#include <QSettings>
#include <QMessageBox>
#include <QInputDialog>
#include <QVBoxLayout>

#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //Restore the previous geometry
    QSettings settings("Symptogene Team", "Level Editor");
    restoreGeometry(settings.value("geometry").toByteArray());
    //restoreState(settings.value("state").toByteArray());
}

void MainWindow::init(){
    this->initStatusBar();
    this->initMenu();
    this->initDockWidgets();
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
    m_viewer = new QGraphicsView(this);
    m_viewerDock = new QDockWidget(this->tr(""), this);
    m_viewerDock->setAllowedAreas(Qt::TopDockWidgetArea);
    m_viewerDock->setWidget(m_viewer);
    m_viewerDock->setFeatures(QDockWidget::NoDockWidgetFeatures);

    //Resources Browser Widget
    m_resourcesBrowser = new ResourcesBrowserWidget();
    m_resourcesBrowserDock = new QDockWidget(this->tr("Assets"), this);
    m_resourcesBrowserDock->setAllowedAreas(Qt::BottomDockWidgetArea | Qt::LeftDockWidgetArea);
    m_resourcesBrowserDock->setWidget(m_resourcesBrowser);
    m_resourcesBrowserDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);

    //Add the dock to the main window
    this->setCorner( Qt::BottomRightCorner, Qt::RightDockWidgetArea );
    this->setCorner( Qt::BottomLeftCorner, Qt::BottomDockWidgetArea );
    this->setCorner( Qt::TopLeftCorner, Qt::TopDockWidgetArea );
    this->setCorner( Qt::TopRightCorner, Qt::RightDockWidgetArea );
    this->addDockWidget(Qt::TopDockWidgetArea, m_viewerDock);
    this->addDockWidget(Qt::BottomDockWidgetArea, m_resourcesBrowserDock);
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
     m_fileMenu->addAction(m_newProjectAction);
     m_fileMenu->addAction(m_openProjectAction);
     m_fileMenu->addSeparator();
     m_fileMenu->addSeparator();
     m_fileMenu->addAction(m_newLevelAction);
     m_fileMenu->addAction(m_loadLevelAction);
     m_fileMenu->addSeparator();
     m_fileMenu->addAction(m_saveAllAction);
     m_fileMenu->addSeparator();
     m_fileMenu->addAction(m_quitAction);

     //Edit Menu
     m_editMenu = this->menuBar()->addMenu(this->tr("&Edit"));
     //m_editMenu->addAction(m_undoAction);
     //m_editMenu->addAction(m_redoAction);

     //Project Menu
     m_projectMenu = this->menuBar()->addMenu(this->tr("&Project"));
     m_projectMenu->addAction(m_projectOptionsAction);

     //About Menu
     m_aboutMenu = this->menuBar()->addMenu(this->tr("&About"));

}

//! When a level is created, we can set  the final steps for the window creation and connect widgets between one another
void MainWindow::setFinalCreationStep(){

    //Scene creation and connection with the element panel
    m_scene = new Scene(m_project->getLayerList(), this);
    m_elementPanel->setScene(m_scene);

    //Init the viewer with a proper title
    QWidget* titleBar = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout();
    QLabel* label = new QLabel(m_project->getName().toLocal8Bit() + m_project->getCurrentLevel().toLocal8Bit());
    layout->addWidget(label);
    titleBar->setLayout(layout);
    m_viewerDock->setTitleBarWidget(titleBar);
    m_viewer->setScene(m_scene);
}
