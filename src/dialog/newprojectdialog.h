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
#include <QLineEdit>

class NewProjectDialog : public QWizard
{
    Q_OBJECT
public:
    explicit NewProjectDialog(QWidget *parent = 0);
    
    void createMainPage();
    void createLayerPage();

signals:
    
public slots:

private:
    QWizardPage* m_mainPage;
    QWizardPage* m_layerPage;

    //Name
    QLabel* m_projectNameLabel;
    QLineEdit* m_projectNameLineEdit;
    
};

#endif // NEWPROJECTDIALOG_H
