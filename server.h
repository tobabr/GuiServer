#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QAbstractItemModel>


class Server : public QTcpServer
{
    Q_OBJECT

public:
    explicit Server(QAbstractItemModel* model, QObject * parent = 0);

public slots:
    void start();

signals:
    void status(QString);


private:
    QAbstractItemModel* _model;

    void incommingConnection(qintptr socketDesc);
};

#endif // SERVER_H
