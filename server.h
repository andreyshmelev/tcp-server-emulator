#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);

signals:

public slots:
    void newConnection();
    void serverRead();
    void clientDisconnected();

private:
    QTcpServer *server;
    QTcpSocket *socket;

};

#endif // SERVER_H
