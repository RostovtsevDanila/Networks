#ifndef CHATLIST_H
#define CHATLIST_H

#pragma once

#include <QObject>
#include <QAbstractListModel>
#include <QList>

class ChatList : public QAbstractListModel
{
	Q_OBJECT

public:
	ChatList(QObject *parent = nullptr);

	enum Roles {
		UserName,
		UserMsg
	};

	int rowCount(const QModelIndex &parent) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	QHash<int, QByteArray> roleNames() const override;

public slots:
	void newMessange(QByteArray msg);

private slots:
	void updateData();

private:
	QList<QString> m_data;
	QString m_messange;
};

#endif // CHATLIST_H
