import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
 import "qrc:/font/js/all.js" as FontAwesome

ApplicationWindow  {
    id: root
    width: 1024
    height: 680
    visible: true
    title: qsTr("Dynamic QML Object")
    color: "#1fa055"
    Item {
        id : customFonts
        readonly property FontLoader fontAwesomeRegular: FontLoader {
            source: "qrc:/font/webfonts/fa-regular-400.ttf"
        }
        readonly property FontLoader fontAwesomeSolid: FontLoader {
            source: "qrc:/font/webfonts/fa-solid-900.ttf"
        }
        readonly property FontLoader fontAwesomeBrands: FontLoader {
            source: "qrc:/font/webfonts/fa-brands-400.ttf"
        }

        readonly property var names : {
            "fontAwesomeRegular" : customFonts.fontAwesomeRegular.name,
            "fontAwesomeSolid" : customFonts.fontAwesomeSolid.name,
            "fontAwesomeBrands" : customFonts.fontAwesomeBrands.name
        }
    }

    Text {
            color: "black"
            font.pixelSize: 40
            text: Icons.faChrome
            font.family: CustomFonts.names.fontAwesomeRegular
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

            }
        }
    }

}
