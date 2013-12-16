//! Part of the IndieLib Level Editor
/*!\file newprojectdialog.cpp
 *\author Cecilia
 *\date 16-12-2013
*/

#include "newprojectdialog.h"
#include <QVBoxLayout>

NewProjectDialog::NewProjectDialog(QWidget *parent) :
    QWizard(parent)
{
    this->setWindowTitle("Project Creation");

    this->createMainPage();
    this->createLayerPage();
}

void NewProjectDialog::createMainPage(){
    m_mainPage = new QWizardPage();
    m_mainPage->setTitle("Project Informations");
    m_mainPage->setSubTitle("This wizard will help you create a new project, please fill it in.");

    //Project Name
    m_projectNameLabel = new QLabel(this->tr("&Project name:"));
    m_projectNameLineEdit = new QLineEdit;
    m_projectNameLabel->setBuddy(m_projectNameLineEdit);


    //Project location


    //Resources Location

    QVBoxLayout* vlayout = new QVBoxLayout();


    m_mainPage->setLayout(vlayout);
    this->addPage(m_mainPage);
}

void NewProjectDialog::createLayerPage(){

}
