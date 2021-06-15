 import QtQuick 2.4
import QtQuick.Window 2.4
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Suivi des caisse")
    Rectangle {
        width: 300; height: 400
        color: "white"

        ListModel {
            id: appModel
            ListElement { name: "Music"; icon: "pics/AudioPlayer_48.png" }
            ListElement { name: "Movies"; icon: "pics/VideoPlayer_48.png" }
            ListElement { name: "Camera"; icon: "pics/Camera_48.png" }
            ListElement { name: "Calendar"; icon: "pics/DateBook_48.png" }
            ListElement { name: "Messaging"; icon: "pics/EMail_48.png" }
            ListElement { name: "Todo List"; icon: "pics/TodoList_48.png" }
            ListElement { name: "Contacts"; icon: "pics/AddressBook_48.png" }
        }
        GridView {
            anchors.fill: parent
            cellWidth: 100; cellHeight: 100
            focus: true
            model: appModel

            highlight: Rectangle { width: 80; height: 80; color: "lightsteelblue" }

            delegate: Item {
                width: 100; height: 100

                Image {
                    id: myIcon
                    y: 20; anchors.horizontalCenter: parent.horizontalCenter
                    source: icon
                }
                Text {
                    anchors { top: myIcon.bottom; horizontalCenter: parent.horizontalCenter }
                    text: name
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: parent.GridView.view.currentIndex = index
                }
            }
        }
    }
    TableView
    {
        anchors.fill: parent

        style: TableViewStyle
        {
            headerDelegate: Rectangle
                            {
                                height: 20
                                color: "lightsteelblue"
                                Text {
                                    width: parent.width
                                    text: styleData.value
                                    elide: Text.ElideMiddle
                                }
                            }


            rowDelegate: Rectangle
                            {
                                color: "blue"
                                height: 30

                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        console.log(row, column, mymodel.data(mymodel.model.index(row, column)))
                                    }
                                }

                            }
        }

        TableViewColumn
        {
            role: "aaa"
            title: "AAA"
            width: 100

            delegate: Item
                        {
                            Rectangle
                            {
                                anchors.left: parent.left
                                id: pic
                                radius: 100
                                height: 15; width: 15; color: "red"
                            }

                            Text
                            {
                                anchors.left: pic.right
                                anchors.leftMargin: 10
                                text: styleData.value
                            }
                        }
        }
        TableViewColumn
        {
            role: "bbb"
            title: "BBB"
            width: 100
        }

        model: ListModel
                {
                    id: mymodel
                    ListElement
                    {
                       aaa : "Banana1"
                       bbb : "Apple1"
                    }
                    ListElement
                    {
                        aaa : "Banana2"
                        bbb : "Apple2"
                    }
                }
    }

    Item {
        width: 400
        height: 400
        id:root
        Rectangle{
            id: rectangle1
            anchors.fill: parent
            radius: 10
            color: "#fff7e8"
            Text{
                id:text1
                anchors.top: parent.top
                anchors.topMargin: 10
                anchors.horizontalCenter: parent.horizontalCenter
                font.bold:true
                font.family: "time new romain"
                color: "#dd6a00"
                font.pixelSize: 24
                text:"aaaaa"
            }

            Component{
                id:itemDelegateText
                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    color: styleData.selected?"#1E90FF":"#000000"
                    elide: styleData.elideMode
                    text: styleData.value
                    font.pointSize: 12
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                }
            }
            TableView{
                id:tableView
                frameVisible: true
                width: parent.width
                height: parent.height - 100
                anchors.top: text1.bottom
                anchors.topMargin: 20
                TableViewColumn{role: "id"; title: "id"; width: 20;delegate: itemDelegateText}
                TableViewColumn{role: "redName"; title: "tt"; width: 100;delegate: itemDelegateText}
                TableViewColumn{role: "blueName"; title: "tt"; width: 100;delegate: itemDelegateText}
                TableViewColumn{role: "gameMode"; title: "tt"; width: 70;delegate: itemDelegateText}
                TableViewColumn{role: "gameTime"; title: "tt"; width: 80;delegate: itemDelegateText}
                TableViewColumn{role: "redGoal"; title: "tt"; width: 70;delegate: itemDelegateText}
                TableViewColumn{role: "blueGoal"; title: "tt"; width: 70;delegate: itemDelegateText}
                TableViewColumn{role: "redScore"; title: "tt"; width: 70;delegate: itemDelegateText}
                TableViewColumn{role: "blueScore"; title: "t"; width: 70;delegate: itemDelegateText}
                TableViewColumn{role: "result"; title: "tt"; width: 60;delegate: itemDelegateText}
                TableViewColumn{role: "createDate"; title: "tt"; width: 160;delegate: itemDelegateText}

                model: modelItems

                headerDelegate: Rectangle{
                    implicitWidth: 10
                    implicitHeight: 24
                    border.color: "gray"
                    border.width: 1
                    Text{
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 4
                        anchors.right: parent.right
                        anchors.rightMargin: 4
                        text: styleData.value
                        color: styleData.pressed ?"red" : "blue"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.bold: true
                    }
                }
                rowDelegate: Rectangle{
                    height: 24
                    color: styleData.selected?"#f0b0b0af":(styleData.alternate?"#c3c3c0":"#c0c0c3")
                }

                itemDelegate: Rectangle {
                    height: 24
                    color: "transparent"
                    Text {
                        //anchors.centerIn: parent
                        //anchors.left: parent.left
                        anchors.leftMargin: 6
                        anchors.verticalCenter: parent.verticalCenter
                        color: styleData.textColor
                        text: styleData.value
                        verticalAlignment: Text.AlignVCenter
                        font.pointSize: 13
                    }
                }
            }

            Button{
                id:clearData
                width: 60
                height: 24
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 10
                anchors.right: parent.right
                anchors.rightMargin: 10
                Text{
                    anchors.centerIn: parent
                    font.family: "time new roman"
                    font.pixelSize: 16
                    text:"aa"
                }
                style: ButtonStyle {
                    background:Rectangle{
                        color: "#ee8742"
                        radius: 4
                    }
                }
                onClicked: {
                    backendProxy.clearData();
                    modelItems.select();
                }
            }

        }
    }

}
