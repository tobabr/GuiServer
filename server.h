#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QStandardItemModel>


class Server : public QTcpServer
{
    Q_OBJECT

public:
    explicit Server(QStandardItemModel* model, QObject * parent = 0);

public slots:
    void start();

signals:
    void status(QString);


private:
    QStandardItemModel* _model;
    virtual void incomingConnection(qintptr socketDesc) override;
};

#endif // SERVER_H
