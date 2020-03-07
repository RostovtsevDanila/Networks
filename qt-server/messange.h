#ifndef MESSANGE_H
#define MESSANGE_H

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

#endif // MESSANGE_H
