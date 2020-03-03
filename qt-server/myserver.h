#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QDebug>

class MyServer : public QTcpServer
{
	Q_OBJECT


public:
	MyServer();

	QTcpSocket *socket;
	QByteArray *Data();

public slots:
	void startServer();
	void incomingConnection(qintptr socketDescriptor);
	void sockReady();
	void sockDisc();
};

#endif // MYSERVER_H
