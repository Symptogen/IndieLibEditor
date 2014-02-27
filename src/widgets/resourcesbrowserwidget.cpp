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

    m_fileModel = new QFileSystemModel;
    m_fileModel ->setRootPath(currentDir.path());

    m_fileBrowser = new QTreeView();
    m_fileBrowser->setModel(m_fileModel);
    m_fileBrowser->setMinimumWidth(50);
    m_fileBrowser->setMaximumWidth(200);
    m_fileBrowser->setRootIndex(m_fileModel->index(currentDir.path()));
    m_fileBrowser->hideColumn(1);
    m_fileBrowser->hideColumn(2);
    m_fileBrowser->hideColumn(3);
    QObject::connect(m_fileBrowser->selectionModel(), SIGNAL(currentChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(updateAssetsBrowser(const QModelIndex &, const QModelIndex &)));

    m_layout = new QHBoxLayout();
    m_layout->addWidget(m_fileBrowser);

    // Assets Browser
    m_assetsBrowser = new QListView();
    m_assetsBrowser->setViewMode(QListView::IconMode);
    m_assetsBrowser->setModel(m_fileModel);
    m_assetsBrowser->setRootIndex(m_fileModel->index(m_resourcesDir));
    m_layout->addWidget(m_assetsBrowser);

    setLayout(m_layout);
}

void ResourcesBrowserWidget::updateAssetsBrowser( const QModelIndex & current, const QModelIndex & previous ){
    qDebug() << "current changed " ;
    m_assetsBrowser->setCurrentIndex(current);
}
