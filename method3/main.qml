import QtQuick 2.4
import QtQuick.Window 2.2


//Item {
//    function nextCPU() {
//        CpuInfo.cpuIndex = CpuIndex.cpuIndex + 1;
//        cpuDetails.text = CpuInfo.cpuIndexDetails;
//    }
//}

Window {
    visible: true
    width: 400
    height: 300

    MainForm {
        id: mainUI
        anchors.fill: parent

        prevMouseArea.onClicked: {
            CpuInfo.cpuIndex = CpuInfo.cpuIndex - 1;
            cpuDetails.text = "<PRE>" + CpuInfo.cpuIndexDetails + "</PRE>";
        }
        nextMouseArea.onClicked: {
            CpuInfo.cpuIndex = CpuInfo.cpuIndex + 1;
            cpuDetails.text = "<PRE>" + CpuInfo.cpuIndexDetails + "</PRE>";
        }

    }

}
