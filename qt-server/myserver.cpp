#include "myserver.h"


MyServer::MyServer()
{

}

void MyServer::startServer()
{
	if(this->listen(QHostAddress::AnyIPv4, 1275))
		qDebug() << "Listening in process...";
	else
		qDebug() << "Error listeening!";
}

void MyServer::incomingConnection(qintptr socketDescriptor)
{
	socket = new QTcpSocket(this);
	addPendingConnection(socket);
	socket->setSocketDescriptor(socketDescriptor);

	connect(socket, SIGNAL(readyRead()), this, SLOT(sockReady()));
	connect(socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));

	qDebug() << "Socket number: " << socketDescriptor << endl
			 << "Client connected.";

	socket->write("You are connected.");

	qDebug() << "Send client connect status 'connected' ";
}

void MyServer::sockReady()
{

}

void MyServer::sockDisc()
{
	qDebug() << "Disconnected.";
	socket->deleteLater();
}
