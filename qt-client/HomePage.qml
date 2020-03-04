import QtQuick 2.0
import QtQuick.Controls 1.4

Column {

	Button {
		id: connectButton
		height: 100
		width: parent.width

		Text {
			id: textOnButton
			anchors.centerIn: parent
			color: client.isConnected ? "green" : "red"
			text: qsTr("Connect to server")
			font.pixelSize: 30
		}

		onClicked: client.connectToHost()
	}

	ChatZone {
		id: chatZone
		width: parent.width
		height: parent.height - messageZone.height - connectButton.height
	}

	MessageZone {
		id: messageZone
		height: 50
		width: parent.width
	}
}
