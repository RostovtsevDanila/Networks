import QtQuick 2.0

Rectangle {
	id: messange
	height: 30
	width: parent.width
	radius: 3
	border.color: "black"

	Text {
		id: messageText
		anchors.centerIn: parent
		font.pixelSize: 20
		text: model.userMsg
	}
}
