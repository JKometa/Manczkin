#ifndef CSERVER_H
#define CSERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

class CServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit CServer(QObject *parent = 0);

signals:

public slots:
    void newConnection();
    void readyRead();

private:
    QTcpServer* server;
    int licznik;

};

#endif // CSERVER_H
