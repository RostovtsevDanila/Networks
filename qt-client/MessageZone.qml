import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle {
	id: frame
	border.color: "lightgrey"
	border.width: 1

	Row {
		anchors.fill: parent
		TextEdit {
			id: txtPlane
			width: parent.width - sendButton.width
			font.pixelSize: 20
			focus: true

			onTextChanged: {
				massage = txtPlane.text
			}
		}

		Rectangle {
			id: sendButton
			color: "transparent"
			height: parent.height
			width: 70

			Image {
				id:buttonIcon
				anchors.fill: parent
				fillMode: Image.PreserveAspectFit
				source: "/icons/send.png"
			}

			MouseArea {
				anchors.fill: parent
				onClicked: {
					client.sendMessage(massage)
					txtPlane.text = null
				}
			}
		}
	}
}
