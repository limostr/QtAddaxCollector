import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
Window {
    id: root
    width: 1024
    height: 680
    visible: true
    title: qsTr("Dynamic QML Object")
    color: "#1fa055"
    FontLoader {
          id: icone
          source: "qrc:///font/font/fontawesome-webfont.ttf"
         // resource: "qrc:/resources/font/font/fontawesome-webfont.ttf"
      }
    FontLoader { id: ioniconsFont; source: "qrc:///font/font/ionicons.ttf" }


    Text {
         font.family: icone.fa-edit
         text: "fa-edit"
         font.pointSize: 50;
         color: "#FFFFFF"; // support transparency as well "#ddaaaaaa"
    }
    Rectangle{
        width: parent.width
        height: 50
        anchors.bottom:  parent.bottom
        color: "#008020"
        Item {
            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 5

                Button {
                    icon: icone.icons.fa_money
                    text: "fa fa_money"
                  }
            }
        }
    }

}
