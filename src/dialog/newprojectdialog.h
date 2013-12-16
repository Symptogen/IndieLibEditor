//! Part of the IndieLib Level Editor
/*!\file newprojectdialog.h
 *\author Cecilia
 *\date 16-12-2013
 *\details The New Project Dialog intends to create a new project as its name said. A new projetc is created by setting the resource
 *path, the save location, a name and a cetegorie list.
*/

#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include <QWizard>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QListView>
#include <QStringListModel>
#include <QModelIndex>

class NewProjectDialog : public QWizard
{
    Q_OBJECT
public:
    explicit NewProjectDialog(QWidget *parent = 0);
    
    void createMainPage();
    void createLayerPage();
    QString getResourcesPath();
    QString getSavePath();
    QString getProjectName();
    QStringList getLayerList();

signals:
    
public slots:
    void browseDialog();
    void addEntry();
    void clearList();
    void removeItem();
    void restoreDefault();
    void selected(QModelIndex index);

private:
    QWizardPage* m_mainPage;
    QWizardPage* m_layerPage;

    //Layer page
    QListView* m_listView;
    QStringListModel* m_listModel;
    QStringList* m_defaultLayerList;
    QLineEdit* m_layerLineEdit;
    QPushButton* m_addEntryButton;
    QPushButton* m_clearAllButton;
    QPushButton* m_removeItemButton;
    QPushButton* m_restoreDefaultListButton;
    QModelIndex m_selection;

    //Name
    QLabel* m_projectNameLabel;
    QLineEdit* m_projectNameLineEdit;

    //Location
    QLabel* m_projectSavePathLabel;
    QLineEdit* m_projectSavePathLineEdit;
    QPushButton* m_browseSave;

    //Resources
    QLabel* m_projectResourcesPathLabel;
    QLineEdit* m_projectResourcesPathLineEdit;
    QPushButton* m_browseResources;
    
};

#endif // NEWPROJECTDIALOG_H
