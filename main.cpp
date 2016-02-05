
#include "mainwindow.h"
#include "server.h"

#include <QApplication>
#include <QStandardItemModel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStandardItemModel* model = new QStandardItemModel();
    MainWindow w(model);
    Server server(model);

    QObject::connect(&w, SIGNAL(startServer()), &server, SLOT(start()));
    QObject::connect(&server, SIGNAL(status(QString)), &w, SLOT(status(QString)));

    w.show();

    return a.exec();
}
