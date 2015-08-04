import QtQuick 2.0

Rectangle {

    signal shown
    objectName: "CpuInfo";
    id: mainRect
    width: 360
    height: 360

    Flickable {
        id: cpuInfoFlickArea
        anchors.fill: parent
        contentHeight: cpuInfoEDT.height

        TextEdit {
            objectName: "cpuInfoText";
            id: cpuInfoEDT
            text: qsTr("CpuInfo")
            anchors.fill: parent
            readOnly: true
            horizontalAlignment: TextEdit.AlignLeft
            textFormat: TextEdit.RichText
            font.pixelSize: 12
        }
    }

//    MouseArea {
//        anchors.fill: parent
//        onClicked: {
//            Qt.quit();
//        }
//    }

    onShown: {
        console.log("OnShow");
        var xhr = new XMLHttpRequest;
        xhr.onreadystatechange = function() {
            console.log("STATE", xhr.readyState);
            if ( xhr.readyState == XMLHttpRequest.DONE ) {
                var respText = xhr.responseText;
                console.log("TEXT:", respText);
                //cpuInfoTXT.text = "<PRE>" + respText + "</PRE>";
                cpuInfoEDT.text = "<PRE>" + respText + "</PRE>";
                }
            }

        xhr.open("GET", "file:///proc/cpuinfo");
        xhr.send();
        }

    Component.onCompleted: mainRect.shown() 
    }
