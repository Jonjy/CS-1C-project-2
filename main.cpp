#include "adminpage.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    adminPage w;
    w.show();


    return a.exec();

}
