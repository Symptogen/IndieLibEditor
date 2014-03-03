#include "resourcesbrowserwidget.h"
#include <QHBoxLayout>

#include <QDebug>

ResourcesBrowserWidget::ResourcesBrowserWidget()
{
    setMinimumHeight(100);
    setMaximumHeight(300);
}

void ResourcesBrowserWidget::setResourcesDir(QString resourcesDir){
    m_resourcesDir = resourcesDir;

    // File Browser
    QDir currentDir = QDir(m_resourcesDir);
    currentDir.cdUp();

    QFileSystemModel* fileModel = new QFileSystemModel;
    fileModel->setFilter(QDir::Dirs|QDir::NoDotAndDotDot);
    fileModel->setRootPath(currentDir.path());

    m_iconProvider = new CustomIconProvider();

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

    //Drag and drop specifications
    m_fileBrowser->setDragEnabled(true);
    m_fileBrowser->setAcceptDrops(false);
    m_fileBrowser->setDragDropMode(QAbstractItemView::DragOnly);

    m_layout = new QHBoxLayout();
    m_layout->addWidget(m_fileBrowser);
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->setSpacing(0);

    // Assets Browser
    QFileSystemModel* resourcesModel = new QFileSystemModel;
    resourcesModel->setIconProvider(m_iconProvider);
    resourcesModel->setRootPath(m_resourcesDir);

    m_assetsBrowser = new QListView();
    m_assetsBrowser->setViewMode(QListView::IconMode);
    m_assetsBrowser->setWrapping(true);
    m_assetsBrowser->setUniformItemSizes(true);
    m_assetsBrowser->setModel(resourcesModel);
    m_assetsBrowser->setRootIndex(resourcesModel->index(m_resourcesDir));
    m_layout->addWidget(m_assetsBrowser);
    QObject::connect(m_assetsBrowser, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(updateFileBrowser(const QModelIndex &)));

    setLayout(m_layout);
}

// Slot called when a directory from the fileBrowser is selected, and that update the resourcesBrowser
void ResourcesBrowserWidget::updateAssetsBrowser( const QModelIndex & current, const QModelIndex & previous ){
    //Creation of a new model for updating the view
    QFileSystemModel* resourcesModel = new QFileSystemModel;
    resourcesModel->setIconProvider(m_iconProvider);
    //Setting the path selected as root for the new model
    resourcesModel->setRootPath(current.data(Qt::UserRole + 1).toString());
    // Update the view
    m_assetsBrowser->setModel(resourcesModel);
    m_assetsBrowser->setRootIndex(resourcesModel->index(current.data(Qt::UserRole + 1).toString()));

}

// Slot called on a double click event on a directory of the resources Browser, and that select the corresponding index in the fileBrowser
void ResourcesBrowserWidget::updateFileBrowser( const QModelIndex & selected ){
    if(static_cast<QFileSystemModel*>(m_fileBrowser->model())->isDir(selected)){
        m_fileBrowser->setCurrentIndex(static_cast<QFileSystemModel*>(m_fileBrowser->model())->index(selected.data(Qt::UserRole + 1).toString()));
    }
}

//---------------------------------------------------------------------------------------------------------------//

QIcon CustomIconProvider::icon(const QFileInfo &info) const
{
    static QPixmapCache cache;
    const QString filepath = info.canonicalFilePath();
    QPixmap pixmap;
    if (!cache.find(filepath, &pixmap)) {
        pixmap.load(filepath);
        cache.insert(filepath, pixmap);
    }
    return pixmap.isNull() ? QFileIconProvider::icon(info) : QIcon(pixmap);
}
