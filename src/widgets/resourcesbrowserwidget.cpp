#include "resourcesbrowserwidget.h"
#include <QHBoxLayout>

#include <QDebug>

ResourcesBrowserWidget::ResourcesBrowserWidget()
{

}

void ResourcesBrowserWidget::setResourcesDir(QString resourcesDir){
    m_resourcesDir = resourcesDir;

    // File Browser
    QDir currentDir = QDir(m_resourcesDir);
    currentDir.cdUp();

    QFileSystemModel* fileModel = new QFileSystemModel;
    fileModel->setFilter(QDir::Dirs|QDir::NoDotAndDotDot);
    fileModel->setRootPath(currentDir.path());

    m_fileBrowser = new QTreeView();
    m_fileBrowser->setModel(fileModel);
    m_fileBrowser->setMinimumWidth(50);
    m_fileBrowser->setMaximumWidth(200);
    m_fileBrowser->setHeaderHidden(true);
    m_fileBrowser->setRootIndex(fileModel->index(currentDir.path()));
    m_fileBrowser->hideColumn(1);
    m_fileBrowser->hideColumn(2);
    m_fileBrowser->hideColumn(3);
    QObject::connect(m_fileBrowser->selectionModel(), SIGNAL(currentChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(updateAssetsBrowser(const QModelIndex &, const QModelIndex &)));

    m_layout = new QHBoxLayout();
    m_layout->addWidget(m_fileBrowser);

    // Assets Browser
    QFileSystemModel* resourcesModel = new QFileSystemModel;
    resourcesModel->setRootPath(m_resourcesDir);

    m_assetsBrowser = new QListView();
    m_assetsBrowser->setViewMode(QListView::IconMode);
    m_assetsBrowser->setWrapping(true);
    m_assetsBrowser->setUniformItemSizes(true);
    m_assetsBrowser->setModel(resourcesModel);
    m_assetsBrowser->setRootIndex(resourcesModel->index(m_resourcesDir));
    m_layout->addWidget(m_assetsBrowser);

    setLayout(m_layout);
}

void ResourcesBrowserWidget::updateAssetsBrowser( const QModelIndex & current, const QModelIndex & previous ){
    QDir currentDir = QDir(m_resourcesDir);
    currentDir.cdUp();
    QString newDir = currentDir.path() + QDir::separator() + current.data(0).toString();

    QFileSystemModel* resourcesModel = new QFileSystemModel;
    resourcesModel->setRootPath(newDir);
    m_assetsBrowser->setModel(resourcesModel);
    m_assetsBrowser->setRootIndex(resourcesModel->index(newDir));

}
