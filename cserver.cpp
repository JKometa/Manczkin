#include "cserver.h"

CServer::CServer(QObject *parent) :
    QTcpServer(parent)
{

    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
    licznik = 0;

    if(!server->listen(QHostAddress::Any, 7331)){

        qDebug() << "Nie dziala";

    }
    else{


        qDebug() << "Dziala!";
    }

}

void CServer::newConnection(){


    QTcpSocket* socket = server->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    socket->write("Manczkin v0.00000000001\r\n                        _,-%/%|\r\n                    _,-'    \\//%\\ \r\n                _,-'        \\%/|%\r\n              / / )    __,--  /%\\ \r\n              \\__/_,-'%(%  ;  %)%\r\n                      %\\%,   %\\ \r\n                         '--%' \r\n\r\n\r\nEl.Ka.Es. ChuWdu iChuj\r\n");
 //   socket->write("ahahahahaha! dziala a modzel jest gopi\r\n");

    socket->flush();
    socket->waitForBytesWritten(3000);
qDebug() << "trololo!";

//socket->close();

}

void CServer::readyRead(){
    QTcpSocket *socket = dynamic_cast<QTcpSocket*>(this->sender());

    licznik++;
    qDebug() << "Dane" << " " << socket->readAll() << " "  << licznik << " \r\n";

}
