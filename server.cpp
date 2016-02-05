#include <QList>
#include <QStandardItem>
#include <QMessageBox>

#include "server.h"
#include "clientthread.h"


Server::Server(QStandardItemModel* model, QObject* parent) :
    QTcpServer(parent), _model(model)
{

}


void Server::start()
{

    if(this->listen(QHostAddress::Any, 55555))
        emit status("Server Listens!");
    else
        emit status("Couldn't start server");
}


void Server::incomingConnection(qintptr socketDesc)
{
    QList<QStandardItem*> clients;
    QStandardItem* client = new QStandardItem(QString::number(socketDesc));
    clients.push_back(client);

    ClientThread* clientTh = new ClientThread(socketDesc, this);

    connect(clientTh, SIGNAL(finished()), clientTh, SLOT(deleteLater()));
    clientTh->start();

    _model->appendColumn(clients);
}
