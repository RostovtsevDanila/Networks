#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QDebug>
#include <QList>

#include "messange.h"

class MyServer : public QTcpServer
{
	Q_OBJECT

public:
	MyServer();
	~MyServer();

public slots:
	void startServer();
	void incomingConnection(qintptr socketDescriptor);
	void sockReady();
	void sockDisc();
	void sendMessage(QByteArray msng);//####################################

private:
	QTcpSocket *m_socket;
	QByteArray textPartOfMessage;
};

#endif // MYSERVER_H
