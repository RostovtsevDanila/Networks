#include "myserver.h"

#define PORTNUM 1275

MyServer::MyServer()
{
	m_socket = new QTcpSocket(this);
	connect(m_socket, SIGNAL(readyRead()), this, SLOT(sockReady()));
	connect(m_socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));
}

MyServer::~MyServer()
{
	m_socket->close();
	delete m_socket;
}

void MyServer::startServer()
{
	if(this->listen(QHostAddress::Any, PORTNUM))
		qDebug() << "Listening in process...";
	else
		qDebug() << "Error listening!";
}

void MyServer::incomingConnection(qintptr socketDescriptor)
{
	addPendingConnection(m_socket); //Непонятная муть, хз как это работает
	m_socket->setSocketDescriptor(socketDescriptor); //Непонятная муть

	qDebug() << "Socket number: " << socketDescriptor << endl
			 << "Client connected";
	qDebug() << "Send client connect status 'connected' ";

	m_socket->write("You are connected.");
}

void MyServer::sockReady()
{
	textPartOfMessage = m_socket->readAll();
	qDebug() << "New message: " << textPartOfMessage;
	sendMessage(textPartOfMessage);

	if(m_socket->waitForConnected(500)) {
		m_socket->waitForReadyRead(500);
		textPartOfMessage = m_socket->readAll();
	}
}

void MyServer::sockDisc()
{
	qDebug() << "Disconnected.";
	m_socket->deleteLater();
}

void MyServer::sendMessage(QByteArray msng)
{
	m_socket->write(msng);
}
