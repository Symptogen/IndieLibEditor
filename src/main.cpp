//! Part of the IndieLib Level Editor
/*!\file main.cpp
 *\author Cecilia
 *\date 15-12-2013
*/

#include <QApplication>
#include "widgets/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
