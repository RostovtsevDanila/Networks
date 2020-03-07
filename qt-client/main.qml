import QtQuick 2.12
import QtQuick.Window 2.12

import space.developers 1.0

Window {
	id: root
	visible: true
	width: 640
	height: 480
	title: qsTr("Client")

	property string massage

	HomePage {
		anchors.fill: parent
	}

	MyClient {
		id: client
	}

	ChatList {
		id: chatList
	}
}
