import QtQuick

Window {
    width: Screen.width / 2
    height: Screen.height / 2
    visible: true
    title: qsTr("Listview Basic Example")

    ListModel
    {
        id: nameModel

        ListElement { name: "Alice" }
        ListElement { name: "Bob" }
        ListElement { name: "Jane" }
        ListElement { name: "Victor" }
        ListElement { name: "Wendy" }
        ListElement { name: "Alice" }
        ListElement { name: "Bob" }
        ListElement { name: "Jane" }
        ListElement { name: "Victor" }
        ListElement { name: "Wendy" }
        ListElement { name: "Alice" }
        ListElement { name: "Bob" }
        ListElement { name: "Jane" }
        ListElement { name: "Victor" }
        ListElement { name: "Wendy" }
        ListElement { name: "Alice" }
        ListElement { name: "Bob" }
        ListElement { name: "Jane" }
        ListElement { name: "Victor" }
        ListElement { name: "Wendy" }
    }

    Component
    {
        id: nameDelegate
        Text
        {
            text: model.name
            font.pixelSize: 32
        }
    }

    ListView
    {
        anchors.fill: parent
        model: nameModel
        delegate: nameDelegate
        clip: true
    }
}
