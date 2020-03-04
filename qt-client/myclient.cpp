#include "myclient.h"

MyClient::MyClient(QObject *parent) : QObject(parent)
{
	m_socket = new QTcpSocket(this);

	connect(m_socket, SIGNAL(readyRead()), this, SLOT(sockReady()));
	connect(m_socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));
}

bool MyClient::isConnected() const
{
	return m_isConnected;
}

void MyClient::sockReady()
{
	if(m_socket->waitForConnected(500)) {
		m_socket->waitForReadyRead(500);
		Data = m_socket->readAll();
		setIsConnected(true);
		qDebug() << Data;
	}
}

void MyClient::sockDisc()
{
	m_socket->deleteLater();
}

void MyClient::connectToHost()
{
	m_socket->connectToHost("127.0.0.1", 1275);
}

void MyClient::sendMessage(QString msg)
{
	Data.clear();
	Data.append(msg);
	m_socket->write(Data);
}

void MyClient::setIsConnected(bool isConnected)
{
	if (m_isConnected == isConnected)
		return;

	m_isConnected = isConnected;
	emit isConnectedChanged(m_isConnected);
}
