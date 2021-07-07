#ifndef MYCLIENT_H
#define MYCLIENT_H

#pragma once

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QByteArray>
#include <QList>
#include <QString>

//#include "message.h"
#include "chatlist.h"

#define STANDART_IP "127.0.0.1"
#define PORTNUM 1275

class MyClient : public QObject
{
	Q_OBJECT

	Q_PROPERTY(bool isConnected READ isConnected WRITE setIsConnected NOTIFY isConnectedChanged)

public:
	explicit MyClient(QObject *parent = nullptr);
	bool isConnected() const;

	Q_INVOKABLE void connectToHost();
	Q_INVOKABLE void sendMessage(QString msg);

public slots:
	void setIsConnected(bool isConnected);
	void sockReady();
	void sockDisc();

signals:
	void isConnectedChanged(bool isConnected);	
	void messangeChanged(QByteArray msg);

private:
	QTcpSocket *m_socket;
	bool m_isConnected = false;
	QByteArray m_messange;
	ChatList m_chatList;
};

#endif // MYCLIENT_H
