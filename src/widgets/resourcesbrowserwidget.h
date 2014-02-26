#ifndef RESOURCESBROWSERWIDGET_H
#define RESOURCESBROWSERWIDGET_H

#include <QWidget>
#include <QTreeView>
#include <QListView>
#include <QFileSystemModel>

class ResourcesBrowserWidget : public QWidget
{
    Q_OBJECT
public:
    ResourcesBrowserWidget();

    void setResourcesDir(QString resourcesDir);
    void updateAssetsBrowser( const QModelIndex & current, const QModelIndex & previous );

private:
    QString m_resourcesDir;
    QLayout* m_layout;
    QTreeView* m_fileBrowser;
    QListView* m_assetsBrowser;
    QFileSystemModel* m_fileModel;
};

#endif // RESOURCESBROWSERWIDGET_H
