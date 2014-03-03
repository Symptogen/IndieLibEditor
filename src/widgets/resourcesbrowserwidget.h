#ifndef RESOURCESBROWSERWIDGET_H
#define RESOURCESBROWSERWIDGET_H

#include <QWidget>
#include <QTreeView>
#include <QListView>
#include <QFileSystemModel>
#include <QPixmapCache>
#include <QFileIconProvider>

//------------------------------------- ICON PROVIDER ------------------------------------------------//
class CustomIconProvider : public QFileIconProvider
{
public:
    CustomIconProvider():QFileIconProvider(){}
    virtual ~CustomIconProvider(){}
protected:
    QIcon icon(const QFileInfo &info) const;
};
//------------------------------------------------------------------------------------------------//

class ResourcesBrowserWidget : public QWidget
{
    Q_OBJECT
public:
    ResourcesBrowserWidget();

    void setResourcesDir(QString resourcesDir);

public slots:
    void updateAssetsBrowser( const QModelIndex & current, const QModelIndex & previous );
    void updateFileBrowser(const QModelIndex & selected);

private:
    QString m_resourcesDir;
    QLayout* m_layout;
    QTreeView* m_fileBrowser;
    QListView* m_assetsBrowser;
    CustomIconProvider* m_iconProvider;
};



#endif // RESOURCESBROWSERWIDGET_H
