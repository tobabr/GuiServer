
#include "server.h"
#include "clientthread.h"


Server::Server(QAbstractItemModel* model, QObject* parent) :
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


void Server::incommingConnection(qintptr socketDesc)
{
    ClientThread* client = new ClientThread(socketDesc, this);

   connect(client, SIGNAL(finished()), client, SLOT(deleteLater()));
    client->start();
}
