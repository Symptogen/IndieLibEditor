#include "iomodule.h"
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QGraphicsItem>
#include "widgets/mainwindow.h"
#include "entitymanager.h"


void IOModule::saveTileset(QString resourcesPath, QString savePath){
    QDir* resourcesDir = new QDir(resourcesPath);
    QDir* saveDir = new QDir(savePath);
    //Test the validity of the path
    if (!resourcesDir->exists() || !saveDir->exists()){
        qDebug() << "The dir for saving the tileset and map does not exists.";
    } else {
        //Creation of the DOM
        m_saveTilesetPath = new QString(savePath);
        m_saveTilesetPath->append("/tileset.xml");

        // Check up
        QFile xml_doc(m_saveTilesetPath->toStdString().c_str());
        if(!xml_doc.open(QIODevice::WriteOnly)){
            // If troubles in opening the xml file
            qDebug() <<"Opening : Erreur à l'ouverture du document XML";
            return;
        }

        QXmlStreamWriter stream(&xml_doc);
        stream.setAutoFormatting(true);
        stream.writeStartDocument();

            stream.writeStartElement("resources");
                stream.writeStartElement("surfaces");
                QStringList files = resourcesDir->entryList(QDir::Files, QDir::Type);
                int counter = 1;
                for (int i = 0; i<files.count(); ++i){
                    if (QFileInfo(files.at(i)).completeSuffix() == "png" || QFileInfo(files.at(i)).completeSuffix() == "jpg"){


                        stream.writeStartElement("surface");
                        stream.writeAttribute("id", QString::number(counter));
                        stream.writeAttribute("image", files.at(i).toStdString().c_str());
                        stream.writeEndElement();
                        counter ++;
                    }
                }
            stream.writeEndElement();
        stream.writeEndDocument();
    }
}

void IOModule::saveLevel(QString path, Scene* scene){
    QFileInfo* file = new QFileInfo(path);
    if (file->dir().exists()){

        // Check up
        QFile xml_doc(path.toStdString().c_str());
        if(!xml_doc.open(QIODevice::WriteOnly)){
            // If troubles in opening the xml file
            qDebug() <<"Opening : Erreur à l'ouverture du document XML";
            return;
        }

        QXmlStreamWriter stream(&xml_doc);
        stream.setAutoFormatting(true);
        stream.writeStartDocument();

            stream.writeStartElement("map");
                stream.writeStartElement("surfaces");
                stream.writeStartElement("tileset");
                stream.writeAttribute("tileset_file", m_saveTilesetPath->toStdString().c_str());

                    stream.writeStartElement("nodes");

                        //Retrieve all the items in a level
                        QVector<GraphicalItem*> items = EntityManager::getInstance()->getGraphicalItemArray();
                        qDebug() << "iomodule " << items.count() ;
                        for (int i = 0; i<items.count(); ++i){
                            stream.writeStartElement("node");
                            stream.writeAttribute("surface_path", items.at(i)->getFilePath());
                            stream.writeAttribute("x", QString::number(items.at(i)->pos().x()));
                            stream.writeAttribute("y", QString::number(items.at(i)->pos().y()));
                            stream.writeEndElement();
                        }

                stream.writeEndElement();
            stream.writeEndDocument();

    }
}

void IOModule::loadLevel(){

}
