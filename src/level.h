//! Part of the IndieLib Level Editor
/*!\file level.h
 *\author Cecilia
 *\date 16-12-2013
 *\details The level class define a level within a project. The Level defines the map that is created and all the elements it contains.
 *A level is represented by a file in the game project resources folder.
*/

#ifndef LEVEL_H
#define LEVEL_H

#include <QString>

class Level
{
public:
    Level(QString name);

    //--------- Getter / Setter ------------- //
    QString getName(){return m_name;}

private:
    QString m_name;
};

#endif // LEVEL_H
