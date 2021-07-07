#ifndef MESSAGE_H
#define MESSAGE_H

#include <QByteArray>

struct Messange
{
	Messange(const int &userID, const QByteArray &userMsng)
	{
		m_userID = userID;
		m_userMsng = userMsng;
	}

	int m_userID;
	QByteArray m_userMsng;
};

#endif // MESSAGE_H
