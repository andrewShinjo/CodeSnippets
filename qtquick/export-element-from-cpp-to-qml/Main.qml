import QtQuick
import CustomComponents 1.0

// Steps to define a new type in QML:
// 1. In C++, subclass either QObject or QQuickItem.
//    Use QQuickItem if you're building an element that's visible on the screen.
//    Otherwise, use QObject instead.
// 2. In C++, register the type with the QML environment.
// 3. In QML, import the module containing the new item.
// 4. In QML, use the item like any other standard item.

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    HelloComponent
    {
        id: helloComponent

        Component.onCompleted:
        {
            console.log(helloComponent.sayHello());
        }
    }
}
