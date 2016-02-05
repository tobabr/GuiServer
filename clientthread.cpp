#include <QTcpSocket>
#include <QByteArray>

#include "clientthread.h"

ClientThread::ClientThread(qintptr ID, QObject* parent) :
    QThread(parent), sDesc(ID)
{
}


void ClientThread::run()
{
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(sDesc))
    {
        emit error(socket->error());
        return;
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(dissconected()), Qt::DirectConnection);

    exec();
}

void ClientThread::readyRead()
{
    QByteArray data = socket->readAll();

    socket->write(data);
    socket->flush();
}


void ClientThread::dissconected()
{
    socket->deleteLater();
    exit(0);
}
