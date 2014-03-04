#include "application.h"

#include <QMessageBox>
#include <QDebug>
#include <QInputDialog>
#include "dialogs/newprojectdialog.h"
#include "entitymanager.h"

/**
* @brief Application constructor.
* Responsible for the initialization of the private attributes of #Application class and for the initialization of the #MainWindow class.
* @param argc is application entry number of variables
* @param argv is the argument given as parameter at the application launch
* @see MainWindow
* @see ~Application()
*/
Application::Application(int& argc, char** argv) :
    QApplication(argc, argv)
{
    // Instanciate the IOModule
    m_ioModule = new IOModule();

    //Initialize the main actions and the mainWindow
    m_mainWindow = new MainWindow();
    initActions();
    m_mainWindow->init();
}

/**
* @brief Function that display the #MainWindow
* This function is done when all the mandatory attributes are initialized. The main file needs the return value of the #MainWindow to
* stop the loop.
* @return bool the result of the execution of the #MainWindow class : if it is closed, then the return value while close the main loop
* @see MainWindow
* @see Application
*/
int Application::start(){
    m_mainWindow->show();
    return this->exec();
}

/**
* @brief Creates all the actions that will be displayed in the #MainWindow menus
* These actions needs to be created in the #Application class because the logical code of their connected slot function belongs in the
* #Application class. So each time a QAction is created, it is set also for the #MainWindow to add it the menu or toolbar.
* @see MainWindow
* @see Application
*/
void Application::initActions(){

    //---------------- FILE MENU ACTION ---------------------------- //

    //New Project
    m_newProjectAction = new QAction(this->tr("New Project"), this);
    m_newProjectAction->setStatusTip(this->tr("Create a new empty project"));
    this->connect(m_newProjectAction, SIGNAL(triggered()), this, SLOT(newProject()));
    m_mainWindow->setNewProjectAction(m_newProjectAction);

    //New Project
    m_openProjectAction = new QAction(this->tr("Open Project"), this);
    m_openProjectAction->setStatusTip(this->tr("Create a new empty project"));
    this->connect(m_openProjectAction, SIGNAL(triggered()), this, SLOT(openProject()));
    m_mainWindow->setOpenProjectAction(m_openProjectAction);

    //New level
    m_newLevelAction = new QAction(this->tr("New Level"), this);
    m_newLevelAction->setShortcut(QKeySequence::New);
    m_newLevelAction->setStatusTip(this->tr("Create a new empty project"));
    this->connect(m_newLevelAction, SIGNAL(triggered()), this, SLOT(newLevel()));
    m_mainWindow->setNewLevelAction(m_newLevelAction);

    //Load level
    m_loadLevelAction = new QAction(this->tr("Load Level"), this);
    m_newLevelAction->setShortcut(QKeySequence::Open);
    m_loadLevelAction->setStatusTip(this->tr("Load a level from the current project"));
    this->connect(m_loadLevelAction, SIGNAL(triggered()), this, SLOT(loadLevel()));
    m_mainWindow->setLoadLevelAction(m_loadLevelAction);

    //Save level
    m_saveAllAction = new QAction(this->tr("Save All"), this);
    m_saveAllAction->setShortcut(QKeySequence::Save);
    m_saveAllAction->setStatusTip(this->tr("Save the current level and the project"));
    this->connect(m_saveAllAction, SIGNAL(triggered()), this, SLOT(saveAll()));
    m_mainWindow->setSaveAllAction(m_saveAllAction);

    //Quit
    m_quitAction = new QAction(this->tr("Quit"), this);
    m_quitAction->setShortcut(QKeySequence::Quit);
    m_quitAction->setStatusTip(this->tr("Close the editor"));
    this->connect(m_quitAction, SIGNAL(triggered()), m_mainWindow, SLOT(close()));
    m_mainWindow->setQuitAction(m_quitAction);

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
    m_mainWindow->setProjectOptionsAction(m_projectOptionsAction);

    //---------------- EDIT MENU ACTION ---------------------------- //

//    m_undoAction = m_invoker->getStack()->createUndoAction(this, tr("&Undo"));
//    m_undoAction->setShortcuts(QKeySequence::Undo);

//    m_redoAction = m_invoker->getStack()->createRedoAction(this, tr("&Redo"));
//    m_redoAction->setShortcuts(QKeySequence::Redo);

}

//------------------------- SLOTS ----------------------------- //
//!Show a dialog for the creation of a new project
void Application::newProject(){

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
               //Save was clicked
               qDebug() << "Save" ;
               saveAll();
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
    NewProjectDialog* wizard = new NewProjectDialog();
    int returnValue = wizard->exec();

    //Update the mainWindow and create a project if the dialog succeded
    if (returnValue == 1){
        m_project = new Project(wizard->getProjectName(), wizard->getResourcesPath(), wizard->getLayerList());
        m_mainWindow->setProject(m_project);

        //Updating the actions now a project has been created
        m_newLevelAction->setEnabled(true);
        m_saveAllAction->setEnabled(true);
    }
}

//! Show a dialog to choose a project file and load it
void Application::openProject(){
    //TODO
}

void Application::loadLevel(){

}

//! Save the current level into an xml file in the projet default save path
void Application::saveAll(){

    // Save the map to an XML file
    QString savePath(m_project->getSavePath());
    savePath.append("/");
    savePath.append(m_project->getCurrentLevel());
    savePath.append(".xml");

    m_ioModule->saveLevel(savePath, m_mainWindow->getScene());

}
//!This function creates a level within the project context and set the main window ready to work
void Application::newLevel(){

    //Open a dialog for the user to choose the level name
    bool ok;
    QString text = QInputDialog::getText(m_mainWindow, tr("New Level"),
                                         tr("Level name:"), QLineEdit::Normal,
                                         "Level_1", &ok);
    //Create a Level with the given name
    if (ok && !text.isEmpty()){
        m_project->addLevel(text);
        m_project->setCurrentLevel(text);

        m_mainWindow->setFinalCreationStep();

        //Set up the resources
        m_ioModule->saveTileset(m_project->getResourcesPath(), m_project->getSavePath());

    }
}
//! Shows up a dialog to expose the project properties and to change them if need.
void Application::projectOptions(){
    //TODO
}

