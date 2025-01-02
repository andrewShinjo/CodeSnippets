import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text
    {
        text: _currentUser.name + ", " + qsTr("Age: %1 years old").arg(_currentUser.age)
    }
}
