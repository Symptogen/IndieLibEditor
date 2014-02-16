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

    m_project = NULL;

    //Restore the previous geometry
    QSettings settings("Symptogene Team", "Level Editor");
    restoreGeometry(settings.value("geometry").toByteArray());
    //restoreState(settings.value("state").toByteArray());

    //Init the command pattern for the undo/redo
    m_invoker = new Invoker();

    this->initStatusBar();
    this->initActions();
    this->initMenu();
    this->initDockWidgets();
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
    m_viewerDock = new QDockWidget(this->tr(""), this);
    m_viewerDock->setAllowedAreas(Qt::LeftDockWidgetArea);
    m_viewerDock->setWidget(m_viewer);
    m_viewerDock->setFeatures(QDockWidget::NoDockWidgetFeatures);

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
     m_editMenu->addAction(m_undoAction);
     m_editMenu->addAction(m_redoAction);

     //Project Menu
     m_projectMenu = this->menuBar()->addMenu(this->tr("&Project"));
     m_projectMenu->addAction(m_projectOptionsAction);

     //About Menu
     m_aboutMenu = this->menuBar()->addMenu(this->tr("&About"));

}

//!Create the actions that are used in the MainWindow menu
void MainWindow::initActions(){

    //---------------- FILE MENU ACTION ---------------------------- //

    //New Project
    m_newProjectAction = new QAction(this->tr("New Project"), this);
    m_newProjectAction->setStatusTip(this->tr("Create a new empty project"));
    this->connect(m_newProjectAction, SIGNAL(triggered()), this, SLOT(newProject()));

    //New Project
    m_openProjectAction = new QAction(this->tr("Open Project"), this);
    m_openProjectAction->setStatusTip(this->tr("Create a new empty project"));
    this->connect(m_openProjectAction, SIGNAL(triggered()), this, SLOT(openProject()));

    //New level
    m_newLevelAction = new QAction(this->tr("New Level"), this);
    m_newLevelAction->setShortcut(QKeySequence::New);
    m_newLevelAction->setStatusTip(this->tr("Create a new empty project"));
    this->connect(m_newLevelAction, SIGNAL(triggered()), this, SLOT(newLevel()));

    //Load level
    m_loadLevelAction = new QAction(this->tr("Load Level"), this);
    m_newLevelAction->setShortcut(QKeySequence::Open);
    m_loadLevelAction->setStatusTip(this->tr("Load a level from the current project"));
    this->connect(m_loadLevelAction, SIGNAL(triggered()), this, SLOT(loadLevel()));

    //Save level
    m_saveAllAction = new QAction(this->tr("Save All"), this);
    m_saveAllAction->setShortcut(QKeySequence::Save);
    m_saveAllAction->setStatusTip(this->tr("Save the current level and the project"));
    this->connect(m_saveAllAction, SIGNAL(triggered()), this, SLOT(saveAll()));

    //Quit
    m_quitAction = new QAction(this->tr("Quit"), this);
    m_quitAction->setShortcut(QKeySequence::Quit);
    m_quitAction->setStatusTip(this->tr("Close the editor"));
    this->connect(m_quitAction, SIGNAL(triggered()), this, SLOT(close()));

    //Specifications for before the project creation
    if(m_project == NULL){
        m_newLevelAction->setEnabled(false);
        m_loadLevelAction->setEnabled(false);
        m_saveAllAction->setEnabled(false);
    }

    //---------------- PROJECT MENU ACTION ---------------------------- //

    //Project options
    m_projectOptionsAction = new QAction(this->tr("Project Options"), this);
    m_projectOptionsAction->setStatusTip(this->tr("Open a dialog with the main project properties"));
    this->connect(m_projectOptionsAction, SIGNAL(triggered()), this, SLOT(projectOptions()));

    //---------------- EDIT MENU ACTION ---------------------------- //

    m_undoAction = m_invoker->getStack()->createUndoAction(this, tr("&Undo"));
    m_undoAction->setShortcuts(QKeySequence::Undo);

    m_redoAction = m_invoker->getStack()->createRedoAction(this, tr("&Redo"));
    m_redoAction->setShortcuts(QKeySequence::Redo);

}
//------------------------- SLOTS ----------------------------- //
//!Show a dialog for the creation of a new project
void MainWindow::newProject(){

    //If a current project is open then we close it, before we ask the user what he want to do
    if (m_project != NULL){
        QMessageBox msgBox;
        msgBox.setText("The project and the level have been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();

        switch (ret) {
           case QMessageBox::Save:
               // Save was clicked
               qDebug() << "Save" ;
               break;
           case QMessageBox::Discard:
               // Don't Save was clicked
               qDebug() << "Discard" ;
               break;
           case QMessageBox::Cancel:
               // Cancel was clicked
               qDebug() << "Cancel" ;
               break;
           default:
               // should never be reached
               break;
         }
    }

    //Show a custom dialog for the project creation
    NewProjectDialog* m_wizard = new NewProjectDialog();
    int returnValue = m_wizard->exec();

    //Update the main window if the dialog succeded
    if (returnValue == 1){
        m_project = new Project(m_wizard->getProjectName(), m_wizard->getSavePath(), m_wizard->getResourcesPath(), m_wizard->getLayerList());

        //Updating the actions now a project has been created
        m_newLevelAction->setEnabled(true);
        m_saveAllAction->setEnabled(true);
    }
}

//! Show a dialog to choose a project file and load it
void MainWindow::openProject(){
    //TODO
}

void MainWindow::loadLevel(){

}

//! Save the current level into an xml file in the projet default save path
void MainWindow::saveAll(){

    // Save the map to an XML file
    QString* savePath = new QString(m_project->getSavePath());
    savePath->append("/");
    savePath->append(m_project->getCurrentLevel()->getName());
    savePath->append(".xml");
    qDebug() << "save path : " << *savePath;

    //m_ioModule->saveLevel(m_project->getCurrentLevel(), *savePath);

}
//!This function creates a level within the project context and set the main window ready to work
void MainWindow::newLevel(){

    //Open a dialog for the user to choose the level name
    bool ok;
    QString text = QInputDialog::getText(this, tr("New Level"),
                                         tr("Level name:"), QLineEdit::Normal,
                                         "Level_1", &ok);
    //Create a Level with the given name
    if (ok && !text.isEmpty()){
        Level* level = new Level(text);
        m_project->addLevel(text, level);
        m_project->setCurrentLevel(level);

        this->setFinalCreationStep();

    }
}

//! When a level is created, we can set  the final steps for the window creation and connect widgets between one another
void MainWindow::setFinalCreationStep(){

    //Scene creation and connection with the element panel
    m_scene = new Scene(m_project->getLayerList(), this);
    m_scene->setInvoker(m_invoker);
    //m_ioModule = new IOModule(m_scene);
    //Set up the resources
    //m_ioModule->saveTileset(m_project->getResourcesPath(), m_project->getSavePath());

    m_elementPanel->setScene(m_scene);
    bool value = QObject::connect(m_scene, SIGNAL(newEntityAdded(Entity*)), m_elementPanel, SLOT(newEntity(Entity*)));
    qDebug() << "connection : " << value;

    //Init the viewer with a proper title
    QWidget* titleBar = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout();
    QLabel* label = new QLabel(m_project->getName().toLocal8Bit() + m_project->getCurrentLevel()->getName().toLocal8Bit());
    layout->addWidget(label);
    titleBar->setLayout(layout);
    m_viewerDock->setTitleBarWidget(titleBar);
    m_viewer->initView(m_scene, this);
}


//! Shows up a dialog to expose the project properties and to change them if need.
void MainWindow::projectOptions(){
    //TODO
}

