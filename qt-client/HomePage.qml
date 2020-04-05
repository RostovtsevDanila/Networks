import QtQuick 2.0
import QtQuick.Controls 1.4

Column {
    id: column

	Button {
		id: connectButton
        height: 100
        anchors.top: parent.top
        anchors.topMargin: 0
		width: parent.width

		Text {
			id: textOnButton
			anchors.centerIn: parent
			color: client.isConnected ? "green" : "red"
			text: qsTr("Connect to server")
			font.pixelSize: 30
		}

		onClicked: client.connectToHost()
        visible: client.isConnected ? false : true
	}

    ChatZone {
        id: chatZone
        width: parent.width
        height: parent.height - messageZone.height - connectButton.height
        anchors.top: parent.top
        anchors.topMargin: 0
        visible: connectButton.visible ? false : true
    }

	MessageZone {
        id: messageZone
        height: 50
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        width: parent.width
        visible: connectButton.visible ? false : true
	}
}
