#include "myclient.h"

MyClient::MyClient(QObject *parent) : QObject(parent)
{
	m_socket = new QTcpSocket(this);

	connect(m_socket, SIGNAL(readyRead()), this, SLOT(sockReady()));
	connect(m_socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));
	connect(this, &MyClient::messangeChanged, &m_chatList, &ChatList::newMessange);
}

bool MyClient::isConnected() const
{
	return m_isConnected;
}

void MyClient::sockReady()
{
	m_messange = m_socket->readAll();
	emit messangeChanged(m_messange);
	qDebug() << "New message: " << m_messange;

	if(m_socket->waitForConnected(500)) {
		m_socket->waitForReadyRead(500);
		m_messange = m_socket->readAll();
		setIsConnected(true);
	}
}

void MyClient::sockDisc()
{
	m_socket->deleteLater();
}

void MyClient::connectToHost()
{
	m_socket->connectToHost(STANDART_IP, PORTNUM);
}

void MyClient::sendMessage(QString msg)
{
	m_messange.clear();
	m_messange.append(msg);
	m_socket->write(m_messange);
}

void MyClient::setIsConnected(bool isConnected)
{
	if (m_isConnected == isConnected)
		return;

	m_isConnected = isConnected;
	emit isConnectedChanged(m_isConnected);
}

