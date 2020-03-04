#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class MyClient : public QObject
{
	Q_OBJECT

	Q_PROPERTY(bool isConnected READ isConnected WRITE setIsConnected NOTIFY isConnectedChanged)

public:
	explicit MyClient(QObject *parent = nullptr);

	QByteArray Data;

	bool isConnected() const;

public slots:
	void sockReady();
	void sockDisc();

	Q_INVOKABLE void connectToHost();
	Q_INVOKABLE void sendMessage(QString msg);

	void setIsConnected(bool isConnected);

signals:

	void isConnectedChanged(bool isConnected);

private:
	QTcpSocket *m_socket;
	bool m_isConnected = false;
};

#endif // MYCLIENT_H
