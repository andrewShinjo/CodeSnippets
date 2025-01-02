import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle
    {
        width: _aSize.width
        height: _aSize.height
        color: _background

        Column
        {
            Text
            {
                text: "The string: " + _aString
            }
            Text
            {
                text: "The size: " + _aSize
            }
        }
    }
}
