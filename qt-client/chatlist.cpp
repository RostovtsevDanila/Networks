#include "chatlist.h"

#include <QDebug>

ChatList::ChatList(QObject *parent) : QAbstractListModel(parent)
{
    m_messange = "Here will be messages.";
	m_data.append(m_messange);
	updateData();
}

int ChatList::rowCount(const QModelIndex &parent) const
{
	if (parent.isValid()) {
		return 0;
	}
	return m_data.size();
}

QVariant ChatList::data(const QModelIndex &index, int role) const
{
	if(index.isValid()) {
		return QVariant();
	}

	switch(role) {
//	case UserName:
//		return "no username :(";
	case UserMsg:
		return m_data[index.row()].data();
	default:
		return QVariant();
	}
}

QHash<int, QByteArray> ChatList::roleNames() const
{
	QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
//	roles[UserName] = "userName";
	roles[UserMsg] = "userMsg";
	return roles;
}

void ChatList::updateData()
{
	m_data.append(m_messange);
	beginResetModel();
	endResetModel();
}

void ChatList::newMessange(QByteArray msg)
{
	m_messange = msg;
	updateData();
}
