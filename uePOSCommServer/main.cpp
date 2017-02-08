#include <QApplication>

#include "uemainwindow.h"

/*!
 * @brief main
 * @param argc
 * @param argv
 * @return program exit code
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UeMainWindow w;
    w.showMaximized();

    return a.exec();
}
