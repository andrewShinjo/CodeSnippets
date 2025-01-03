import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Example: Subclass QAbstractItemModel")

    TreeView
    {
        anchors.fill: parent
        model: _model
        delegate: TreeViewDelegate {}
    }
}
