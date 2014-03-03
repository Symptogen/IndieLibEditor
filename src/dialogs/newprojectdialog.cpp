//! Part of the IndieLib Level Editor
/*!\file newprojectdialog.cpp
 *\author Cecilia
 *\date 16-12-2013
*/

#include "newprojectdialog.h"
#include <QGridLayout>
#include <QFileDialog>

NewProjectDialog::NewProjectDialog(QWidget *parent) :
    QWizard(parent)
{
    this->setWindowTitle("Project Creation");

    //Create the default layer list
    m_defaultLayerList = new QStringList();
    m_defaultLayerList->append("Character");
    m_defaultLayerList->append("Static objects");
    m_defaultLayerList->append("Dangerous objects");
    m_defaultLayerList->append("Movable objects");
    m_defaultLayerList->append("Ground and Roof");
    m_defaultLayerList->append("Background");
    m_defaultLayerList->append("Decor");
    m_defaultLayerList->append("Platforms");

    //create the wizard pages
    m_mainPage = new QWizardPage();
    m_layerPage = new QWizardPage();

    this->setPage(0, m_mainPage);
    this->setPage(1, m_layerPage);

    this->createMainPage();
    this->createLayerPage();
}

void NewProjectDialog::createMainPage(){
    m_mainPage->setFinalPage(false);
    m_mainPage->setTitle("Project Informations");
    m_mainPage->setSubTitle("This wizard will help you create a new project, from an existing assets directory or from sratch.");

    //Project Name
    m_projectNameLabel = new QLabel(this->tr("&Project name :"));
    m_projectNameLineEdit = new QLineEdit;
    m_projectNameLabel->setBuddy(m_projectNameLineEdit);

    //Resources Location
    m_projectResourcesPathLabel = new QLabel(this->tr("&Assets root dir :"));
    m_projectResourcesPathLineEdit = new QLineEdit;
    connect(m_projectResourcesPathLineEdit, SIGNAL(textChanged(QString)), m_projectResourcesPathLineEdit, SLOT(setText(QString)));
    m_projectResourcesPathLabel->setBuddy(m_projectResourcesPathLineEdit);

    //Browse button
    m_browseResources = new QPushButton("...");
    this->connect(m_browseResources, SIGNAL(clicked()), this, SLOT(browseDialog()));

    //Layout
    QGridLayout* layout = new QGridLayout();
    layout->addWidget(m_projectNameLabel, 0, 0);
    layout->addWidget(m_projectNameLineEdit, 0, 1);
    layout->addWidget(m_projectResourcesPathLabel, 1, 0);
    layout->addWidget(m_projectResourcesPathLineEdit, 1, 1);
    layout->addWidget(m_browseResources, 1, 2);

    m_mainPage->setLayout(layout);
}

void NewProjectDialog::createLayerPage(){
    m_layerPage->setFinalPage(false);
    m_layerPage->setTitle("Create the categories for the project");
    m_layerPage->setSubTitle("The entity you will create in the level will belong to groups that you can define here.");

    //List view
    m_listView = new QListView();
    m_listView->setSelectionMode(QAbstractItemView::SingleSelection);
    m_listModel = new QStringListModel();
    m_listModel->setStringList(*m_defaultLayerList);
    m_listView->setModel(m_listModel);
    this->connect(m_listView, SIGNAL(clicked(QModelIndex)), this, SLOT(selected(QModelIndex)));

    //Add new entry
    m_layerLineEdit = new QLineEdit();
    m_addEntryButton = new QPushButton("Add entry");
    this->connect(m_addEntryButton, SIGNAL(clicked()), this, SLOT(addEntry()));

    //Clear all button
    m_clearAllButton = new QPushButton("Clear all");
    this->connect(m_clearAllButton, SIGNAL(clicked()), this, SLOT(clearList()));

    //Remove item button
    m_removeItemButton = new QPushButton("Remove");
    this->connect(m_removeItemButton, SIGNAL(clicked()), this, SLOT(removeItem()));

    //Restore default list
    m_restoreDefaultListButton = new QPushButton("Restore default");
    this->connect(m_restoreDefaultListButton, SIGNAL(clicked()), this, SLOT(restoreDefault()));


    QGridLayout* layout = new QGridLayout();
    layout->addWidget(m_listView, 0, 0, 4, 4);
    layout->addWidget(m_removeItemButton, 0, 5);
    layout->addWidget(m_clearAllButton, 1, 5);
    layout->addWidget(m_restoreDefaultListButton, 2, 5);
    layout->addWidget(m_layerLineEdit, 5, 0 );
    layout->addWidget(m_addEntryButton, 5, 5);

    m_layerPage->setLayout(layout);

}

//! Open a browse file dialog and copy the selection into the correct line edit following which button called the dialog
void NewProjectDialog::browseDialog(){
    QString folder = QFileDialog::getExistingDirectory(this, this->tr("Select the resources folder"), "/home/cecilia");
    m_projectResourcesPathLineEdit->setText(folder);
}

//!This Slot is called when the user clicks the add entry button, it taked the value of the line edit to update the layer list.
void NewProjectDialog::addEntry(){
    //Prepare a new row
    //int row = m_listModel->rowCount();
    //m_listModel->insertRows(row, 1);

    QStringList list = m_listModel->stringList();
    list << m_layerLineEdit->text();

    m_listModel->setStringList(list);

    //Retrieve the inserted row and edit it
    //QModelIndex index = m_listModel->index(m_listModel->rowCount()+1);
    //m_listModel->setData(index, m_layerLineEdit->text());
    m_layerLineEdit->clear();
    m_layerLineEdit->setFocus();
}

//!Remove the selected item(s) from the list
void NewProjectDialog::removeItem(){
    //Retrieve the selection
    //Suppress all the selected elements
    QStringList list = m_listModel->stringList();
    list.removeAt(m_selection.row());
    //Update the model
    m_listModel->setStringList(list);
}

//!Clear the model and the view
void NewProjectDialog::clearList(){
    QStringList* emptyList = new QStringList();
    m_listModel->setStringList(*emptyList);

}

//! Restore the default list of layers
void NewProjectDialog::restoreDefault(){
    m_listModel->setStringList(*m_defaultLayerList);
}

//!Update the selectin from the list view
void NewProjectDialog::selected(QModelIndex index){
    m_selection = index;
}

//----------------- GETTER ----------------------- //
QString NewProjectDialog::getResourcesPath(){
    return m_projectResourcesPathLineEdit->text();
}

QString NewProjectDialog::getProjectName(){
    return m_projectNameLineEdit->text();
}

QStringList NewProjectDialog::getLayerList(){
    return m_listModel->stringList();
}
