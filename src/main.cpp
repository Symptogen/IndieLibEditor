//! Part of the IndieLib Level Editor
/*!\file main.cpp
 *\author Cecilia
 *\date 15-12-2013
*/

#include "application.h"

int main(int argc, char *argv[])
{
    Application* a = new Application(argc, argv);
    return a->start();
}
