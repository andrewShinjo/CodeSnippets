import QtQuick
import QtQuick.Controls


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Example: Treeview Minimal Example")

    TreeView
    {
        anchors.fill: parent
        model: _treeModel
        delegate: TreeViewDelegate {}
    }
}
