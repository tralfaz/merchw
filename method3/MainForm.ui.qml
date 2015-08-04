import QtQuick 2.4

Rectangle {
    id: mainRect
    //property alias mouseArea: mouseArea
    property alias cpuDetails: cpuDetails
    property alias nextMouseArea: nextMouseArea
    property alias prevMouseArea: prevMouseArea

    width: 360
    height: 360

    Item {
        id: funcs1
        /*
        function nextCPU() {
            CpuInfo.cpuIndex = CpuInfo.cpuIndex + 1;
            cpuDetails.text = "<PRE>" + CpuInfo.cpuIndexDetails + "</PRE>";
        }
        function prevCPU() {
            CpuInfo.cpuIndex = CpuInfo.cpuIndex - 1;
            cpuDetails.text = CpuInfo.cpuIndexDetails;
        }
*/
    }

    Text {
        id: cpuDetails
        x: 13
        y: 0
        width: 339
        height: 15
        text: "<PRE>" + CpuInfo.cpuIndexDetails + "</PRE>"
        anchors.top: parent.top
        anchors.topMargin: 108
        textFormat: Text.RichText
        wrapMode: Text.WordWrap
        font.pixelSize: 12
    }

    Text {
        id: cpuCount
        anchors.centerIn: parent
        text: CpuInfo.cpuCount
        anchors.top: parent.top
        anchors.topMargin: 18
        anchors.verticalCenterOffset: -154
        anchors.horizontalCenterOffset: 0
        x: 5
    }

    Rectangle {
        id: nextRect
        x: 217
        y: 44
        width: 95
        height: 49
        color: "#b3b3b3"
        radius: 5

        MouseArea {
            id: nextMouseArea
            anchors.fill: parent

            Text {
                id: nextLBL
                x: 2
                y: 4
                width: 93
                height: 35
                text: qsTr("Next")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 12
            }
            //onClicked: funcs.nextCPU()
        }
    }

    Rectangle {
        id: prevRect
        x: 38
        y: 44
        width: 108
        height: 49
        color: "#b3b3b3"
        radius: 5
        border.color: "#000000"

        MouseArea {
            id: prevMouseArea
            anchors.fill: parent

            Text {
                id: prevLBL
                text: qsTr("Prev")
                anchors.fill: parent
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 12
            }
            //                onClicked: funcs.prevCPU()
        }
    }


}
