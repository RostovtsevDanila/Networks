#include "myserver.h"


MyServer::MyServer()
{
	m_socket = new QTcpSocket(this);
	connect(m_socket, SIGNAL(readyRead()), this, SLOT(sockReady()));
	connect(m_socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));

	setUserID(0);
}

MyServer::~MyServer()
{
	m_socket->close();
	delete m_socket;
}

int MyServer::userID() const
{
	return m_userID;
}

void MyServer::startServer()
{
	if(this->listen(QHostAddress::Any, 1275))
		qDebug() << "Listening in process...";
	else
		qDebug() << "Error listening!";
}

void MyServer::incomingConnection(qintptr socketDescriptor)
{
	addPendingConnection(m_socket); //Непонятная муть
	m_socket->setSocketDescriptor(socketDescriptor); //Непонятная муть

	m_userID ++;

	qDebug() << "Socket number: " << socketDescriptor << endl
			 << "Client connected with id:" << userID();
	qDebug() << "Send client connect status 'connected' ";

	m_socket->write("You are connected.");
}

void MyServer::sockReady()
{
	Data = m_socket->readAll();
	qDebug() << "New message: " << Data;
}

void MyServer::sockDisc()
{
	qDebug() << "Disconnected.";
	m_socket->deleteLater();
}

void MyServer::setUserID(int userID)
{
	if (m_userID == userID)
		return;


	m_userID = userID;
	emit userIDChanged(m_userID);
}

