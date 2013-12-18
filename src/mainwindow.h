//! Part of the IndieLib Level Editor
/*!\file mainwindow.h
 *\author Cecilia
 *\date 15-12-2013
 *\details This class instanciate the QMainWindow and draw the main widgets of the editor. Currently we use two widgets : the element panel
 *that describe the parameters of the selected element, and the hierarchy panel that gives a global view of all the elements in the
 *current projet and of their relations. In addition, the viewer focus on the final visual of the work.
 *\sa ElementPanel, HierarchyPanel
*/

#ifndef _INDIELIB_EDITOR_MAINWINDOW_H
#define _INDIELIB_EDITOR_MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QMenu>
#include "iomodule.h"
#include "elementpanel.h"
#include "hierarchypanel.h"
#include "viewer.h"
#include "graphics/scene.h"
#include "project.h"
#include "dialog/newprojectdialog.h"
#include "commands/invoker.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initDockWidgets();
    void initStatusBar();
    void initMenu();
    void initActions();
    void closeEvent(QCloseEvent *event);
    void setFinalCreationStep();

public slots:
    void newProject();
    void openProject();
    void loadLevel();
    void newLevel();
    void saveAll();
    void projectOptions();

private:
    IOModule* m_ioModule;
    ElementPanel* m_elementPanel;
    HierarchyPanel* m_hierarchyPanel;
    Viewer* m_viewer;
    Scene* m_scene;
    Project* m_project;
    Invoker* m_invoker;
    NewProjectDialog* m_wizard;

    QDockWidget* m_elementDock;
    QDockWidget* m_hierarchyDock;
    QDockWidget* m_viewerDock;

    //Menus
    QMenu* m_fileMenu;
    QMenu* m_aboutMenu;
    QMenu* m_editMenu;
    QMenu* m_projectMenu;

    //Actions
    QAction* m_newProjectAction;
    QAction* m_openProjectAction;
    QAction* m_newLevelAction;
    QAction* m_loadLevelAction;
    QAction* m_saveAllAction;
    QAction* m_quitAction;
    QAction* m_projectOptionsAction;
    QAction* m_undoAction;
    QAction* m_redoAction;
};

#endif // _INDIELIB_EDITOR_MAINWINDOW_H
