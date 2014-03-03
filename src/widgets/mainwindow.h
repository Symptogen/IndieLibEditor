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
#include <QGraphicsView>
#include <QMenu>
#include "elementpanel.h"
#include "hierarchypanel.h"
#include "../graphic/scene.h"
#include "../project.h"
#include "../dialogs/newprojectdialog.h"
#include "../command/invoker.h"
#include "../widgets/resourcesbrowserwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow(){}

    void init();
    void initDockWidgets();
    void initStatusBar();
    void initMenu();
    void closeEvent(QCloseEvent *event);
    void setFinalCreationStep();

    //Setters
    inline void setProject(Project* project) {m_project = project; m_resourcesBrowser->setResourcesDir(m_project->getResourcesPath());}
    inline void setNewProjectAction(QAction* action) {m_newProjectAction = action;}
    inline void setOpenProjectAction(QAction* action) {m_openProjectAction = action;}
    inline void setNewLevelAction(QAction* action) {m_newLevelAction = action;}
    inline void setLoadLevelAction(QAction* action) {m_loadLevelAction = action;}
    inline void setSaveAllAction(QAction* action) {m_saveAllAction = action;}
    inline void setQuitAction(QAction* action) {m_quitAction = action;}
    inline void setProjectOptionsAction(QAction* action) {m_projectOptionsAction = action;}
    inline void setUndoAction(QAction* action) {m_undoAction = action;}
    inline void setRedoAction(QAction* action) {m_redoAction = action;}

    //Getter
    Scene* getScene() const {return m_scene;}

private:
    ElementPanel* m_elementPanel;
    HierarchyPanel* m_hierarchyPanel;
    QGraphicsView* m_viewer;
    Scene* m_scene;
    Project* m_project;
    ResourcesBrowserWidget* m_resourcesBrowser;

    QDockWidget* m_elementDock;
    QDockWidget* m_hierarchyDock;
    QDockWidget* m_viewerDock;
    QDockWidget* m_resourcesBrowserDock;

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
