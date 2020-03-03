#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class MyClient : public QObject
{
	Q_OBJECT
public:
	explicit MyClient(QObject *parent = nullptr);

	QTcpSocket *socket;
	QByteArray Data;

public slots:
	void sockReady();
	void sockDisc();

	Q_INVOKABLE void connectToHost();

signals:

};

#endif // MYCLIENT_H
