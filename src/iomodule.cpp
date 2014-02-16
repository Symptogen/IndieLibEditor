#include "iomodule.h"
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QGraphicsItem>
#include "widgets/mainwindow.h"

IOModule::IOModule(Scene *scene)
{
    m_scene = scene;
}

void IOModule::saveTileset(QString path, QString savePath){
//    QDir* dir = new QDir(path);
//    QDir* saveDir = new QDir(savePath);
//    //Test the validity of the path
//    if (dir->exists() && saveDir->exists()){
//        TiXmlDocument mXmlDoc;

//        // XML Declaration
//        TiXmlDeclaration *mDecl = new TiXmlDeclaration ("1.0", "", "");
//        mXmlDoc.LinkEndChild (mDecl);

//        // Resources tag
//        TiXmlElement *mXRoot = new TiXmlElement ("resources");
//        mXmlDoc.LinkEndChild (mXRoot);

//        // Surfaces tag
//        TiXmlElement *mXRootSurface = new TiXmlElement ("surfaces");
//        mXRoot->LinkEndChild (mXRootSurface);

//        //List of resources
//        QStringList files = dir->entryList(QDir::Files, QDir::Type);
//        int counter = 1;
//        for (int i = 0; i<files.count(); ++i){
//            if (QFileInfo(files.at(i)).completeSuffix() == "png" || QFileInfo(files.at(i)).completeSuffix() == "jpg"){
//                TiXmlElement *mXNode = new TiXmlElement ("surface");
//                mXNode->SetAttribute ("id", counter);
//                mXNode->SetAttribute("image", files.at(i).toStdString().c_str());
//                mXRootSurface->LinkEndChild (mXNode);
//                counter ++;
//            }
//        }

//        // Save the map to an XML file
//        m_saveTilesetPath = new QString(savePath);
//        m_saveTilesetPath->append("/tileset.xml");

//        bool returnValue = mXmlDoc.SaveFile(m_saveTilesetPath->toStdString().c_str());
//        if (!returnValue){
//            qDebug() << "failed to save the tileset.";
//        }

//    }else{
//        qDebug() << "Oups : not a valid resources dir or save dir!";
//    }
}

void IOModule::saveLevel(QString path){
//    QFileInfo* file = new QFileInfo(path);
//    if (file->dir().exists()){
//        qDebug() << "Saving level ...";
//        TiXmlDocument mXmlDoc;

//        // XML Declaration
//        TiXmlDeclaration *mDecl = new TiXmlDeclaration ("1.0", "", "");
//        mXmlDoc.LinkEndChild (mDecl);

//        // Map tag
//        TiXmlElement *mXRoot = new TiXmlElement ("map");
//        mXmlDoc.LinkEndChild (mXRoot);

//        // Tileset
//        TiXmlElement *mXTileset = new TiXmlElement ("tileset");
//        mXRoot->LinkEndChild (mXTileset);
//        mXTileset->SetAttribute("tileset_file", m_saveTilesetPath->toStdString().c_str());

//        // Iterate the nodes vector and write them to the XML
//        TiXmlElement *mXNodes = new TiXmlElement ("nodes");
//        mXRoot->LinkEndChild (mXNodes);

//        //Retrieve all the items in a level
//        QList<QGraphicsItem*> items = m_scene->items();
//        for (int i = 0; i<items.count(); ++i){
//            TiXmlElement *mXNode;
//            mXNode = new TiXmlElement ("node");
//            //mXNode->SetAttribute ("surface_id", (*mIter)->GetSurfaceId());
//            mXNode->SetAttribute ("x", items.at(i)->pos().x() );
//            mXNode->SetAttribute ("y", items.at(i)->pos().y() );
//           /* mXNode->SetAttribute ("z", (*mIter)->GetEntity()->getPosZ());
//            mXNode->SetAttribute ("layer", (*mIter)->GetLayer());
//            mXNode->SetDoubleAttribute ("angle", (*mIter)->GetEntity()->getAngleZ());
//            mXNode->SetDoubleAttribute ("scale", (*mIter)->GetEntity()->getScaleX());
//            mXNode->SetAttribute ("trans", (*mIter)->GetEntity()->getTransparency());
//            mXNode->SetAttribute ("mirror_x", (*mIter)->GetEntity()->getMirrorX());
//            mXNode->SetAttribute ("mirror_y", (*mIter)->GetEntity()->getMirrorY());
//            mXNode->SetAttribute ("tint_r", (*mIter)->GetEntity()->getTintR());
//            mXNode->SetAttribute ("tint_g", (*mIter)->GetEntity()->getTintG());
//            mXNode->SetAttribute ("tint_b", (*mIter)->GetEntity()->getTintB());
//            mXNode->SetAttribute ("if_wrap", (*mIter)->GetEntity()->ifWrap());
//            mXNode->SetAttribute ("region_width", (*mIter)->GetEntity()->getRegionWidth());
//            mXNode->SetAttribute ("region_height", (*mIter)->GetEntity()->getRegionHeight());
//            */
//            mXNodes->LinkEndChild (mXNode);
//        }

//        bool returnValue = mXmlDoc.SaveFile(m_saveTilesetPath->toStdString().c_str());
//        if (!returnValue){
//            qDebug() << "failed to save the tileset.";
//        }

//    }
}
