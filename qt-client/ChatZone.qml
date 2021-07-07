import QtQuick 2.0
import QtQuick.Controls 1.4

ListView {
	id: root
	model: chatList
	clip: true

	delegate: MessangeItem {

	}
}
