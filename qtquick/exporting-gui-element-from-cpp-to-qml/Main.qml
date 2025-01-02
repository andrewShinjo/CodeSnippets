import QtQuick
import Shapes 1.0

// QQuickPaintedItem easier to implement, but potentially slower.
// QQuickItem potentially faster because it's hardware accelerated, but harder to implement.

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Ellipse
    {
        id: ellipse
        anchors.fill: parent

        Component.onCompleted:
        {
            console.log("Ellipse created.");
        }
    }
}
