#ifndef INDIELIB_EDITOR_APPLICATION_H
#define INDIELIB_EDITOR_APPLICATION_H

#include <QApplication>
#include <QAction>
#include "widgets/mainwindow.h"
#include "project.h"
#include "iomodule.h"

/**
* @class Application class.
* The #Application class is responsible for displaying the window and instanciating the main elements of the editor.
* @see MainWindow
* @see Project
* @see IOModule
*/
class Application : public QApplication
{
    Q_OBJECT
public:
    explicit Application(int& argc, char** argv);
    int start();
    void initActions();

public slots:
    void newProject();
    void openProject();
    void loadLevel();
    void newLevel();
    void saveAll();
    void projectOptions();

private:
    MainWindow* m_mainWindow; /**< store the reference to the #MainWindow */
    Project* m_project; /**< store the current #Project */
    IOModule* m_ioModule; /**< store the reference of the import export module #IOModule */

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

#endif // INDIELIB_EDITOR_APPLICATION_H
