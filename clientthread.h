#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include <QThread>
#include <QTcpSocket>

class ClientThread : public QThread
{
    Q_OBJECT

public:
    explicit ClientThread(qintptr ID, QObject* parent = 0);
    void run();

signals:
    void error(QTcpSocket::SocketError socketError);

public slots:
    void readyRead();
    void dissconected();

private:
    QTcpSocket* socket;
    qintptr sDesc;

};

#endif // CLIENTTHREAD_H
