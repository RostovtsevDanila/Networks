#include "myclient.h"

MyClient::MyClient(QObject *parent) : QObject(parent)
{
	socket = new QTcpSocket(this);

	connect(socket, SIGNAL(readyRead()), this, SLOT(sockReady()));
	connect(socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));
}

void MyClient::sockReady()
{
	if(socket->waitForConnected(500)) {
		socket->waitForReadyRead(500);
		Data = socket->readAll();
		qDebug() << Data;
	}
}

void MyClient::sockDisc()
{
	socket->deleteLater();
}

void MyClient::connectToHost()
{
	qDebug() << "Clicked";
	socket->connectToHost("127.0.0.1", 1275);
}
