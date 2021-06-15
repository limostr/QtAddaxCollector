import QtQuick 2.4
import Qt.labs.settings 1.0
import QtQuick.Controls.Universal 2.0
import QtQuick.Controls 2.15

Item {

    Text {
        id: text1
        x: 199
        y: 46
        width: 216
        height: 57
        color: "#0b8a14"
        text: qsTr("Suivi des Caisses")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        lineHeight: 0.9
        minimumPointSize: 18
        minimumPixelSize: 24
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
