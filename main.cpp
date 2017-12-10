#include "connectdb.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connectDb w;
    w.show();

    return a.exec();
}
