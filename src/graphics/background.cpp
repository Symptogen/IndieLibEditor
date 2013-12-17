//! Part of the IndieLib Level Editor
/*!\file background.cpp
 *\author Cecilia
 *\date 16-12-2013
 *\todo
*/

#include "background.h"

Background::Background(QPixmap pixmap)
{
    enum { Type = UserType + 2 };
    this->setPixmap(pixmap);
}
