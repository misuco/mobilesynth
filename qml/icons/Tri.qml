import QtQuick 2.0
import QtQuick.Shapes 1.0

Item {
    property int xStep: width / 4
    property int yStep: height / 2

    Shape {

        anchors.fill: parent

        ShapePath {
            strokeWidth: 1+height/50
            strokeColor: modelData.selected ? hlColor : fgColor
            fillColor: "Transparent"

            startX: 0
            startY: yStep

            PathLine { x: 0; y: yStep }
            PathLine { x: xStep; y: 0 }
            PathLine { x: xStep*2; y: yStep }
            PathLine { x: xStep*3; y: yStep * 2 }
            PathLine { x: xStep*4; y: yStep }
        }
    }
}
