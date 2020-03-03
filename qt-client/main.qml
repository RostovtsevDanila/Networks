import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.4

import space.developers 1.0

Window {
	id: root
	visible: true
	width: 640
	height: 480
	title: qsTr("Client")



	Button {
		height: 100
		width: 300

		anchors.horizontalCenter: parent.horizontalCenter
		anchors.verticalCenter: parent.verticalCenter

		Text {
			id: textOnButton
			anchors.centerIn: parent
			text: qsTr("Connect to server")
			font.pixelSize: 30
		}

		onClicked: client.connectToHost()
	}

	MyClient {
		id: client
	}
}
