import QtQuick 2.4

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        Flickable {
            id: flickable1
            flickableDirection: Flickable.HorizontalAndVerticalFlick
            anchors.fill: parent

            Text {
                objectName: "cpuInfoText"
                id: cpuInfoText
                text: "[CpuInfo]"
                textFormat: Text.RichText
                anchors.fill: parent
                horizontalAlignment: Text.AlignLeft
                wrapMode: Text.WordWrap
            }
        }
    }
}
