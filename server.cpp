#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{

    server = new QTcpServer(this);

    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any,1234))
    {
        qDebug() << server->errorString();
    }

    else
    {
        qDebug() << "Server started";
    }
}

void Server::newConnection()
{
    socket = server->nextPendingConnection();
    socket->write("Hello, i am server\r\n");
    connect(socket,SIGNAL(readyRead()),this,SLOT(serverRead()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(clientDisconnected()));

    /*socket->flush();
    socket->waitForBytesWritten(3000);
    socket->close();*/
}
void Server::serverRead()
{
    while(socket->bytesAvailable()>0)
    {
        QByteArray ba= socket->readAll();


        socket->write(ba);socket->write(ba);socket->write(ba);socket->write(ba);
        qDebug() << ba;

    }
}

void Server::clientDisconnected()
{
    socket->close();
}
