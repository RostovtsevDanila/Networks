#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QDebug>

class MyServer : public QTcpServer
{
	Q_OBJECT

	Q_PROPERTY(int userID READ userID WRITE setUserID NOTIFY userIDChanged)

public:
	MyServer();
	~MyServer();

	QByteArray Data;

	int userID() const;

public slots:
	void startServer();
	void incomingConnection(qintptr socketDescriptor);
	void sockReady();
	void sockDisc();

	void setUserID(int userID); //userID ++

signals:
	void userIDChanged(int userID);

private:
	QTcpSocket *m_socket;
	int m_userID;
};

#endif // MYSERVER_H
