import QtQuick 2.0

Item {
    id: root

    Row {
        anchors.fill: parent

        onHeightChanged: {
            for(var i=0;i<layout.tuneArea.length;i++) {
                layout.tuneArea[i].onResize(height);
            }
        }

        Repeater  {
            model: layout.tuneArea

            Rectangle {
                id: faderBackground
                anchors.top: parent.top
                anchors.bottom: parent.bottom

                color: modelData.bgColor
                width: buttonSize
                height: parent.height

                Rectangle {
                    color: modelData.pitchColor
                    width: buttonSize
                    height: modelData.knobSize
                    y: modelData.faderY
                }

                Text {
                    anchors.fill: parent
                    text: modelData.text1
                    font.pixelSize: fontSize1
                    color: modelData.fontColor
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignTop
                }

                MultiPointTouchArea {
                    anchors.fill: parent

                    onPressed: {
                        for(var i=0;i<touchPoints.length;i++) {
                            modelData.onPressed(touchPoints[i].pointId,touchPoints[i].x,touchPoints[i].y,height)
                            modelData.onPressedPitch(touchPoints[i].pointId)
                        }
                    }

                    onTouchUpdated: {
                        for(var i=0;i<touchPoints.length;i++) {
                            modelData.onUpdated(touchPoints[i].pointId,touchPoints[i].y,height)
                            modelData.onUpdatedPitch(touchPoints[i].pointId)
                        }
                    }

                    onUpdated: {
                        for(var i=0;i<touchPoints.length;i++) {
                            modelData.onUpdated(touchPoints[i].pointId,touchPoints[i].y,height)
                            modelData.onUpdatedPitch(touchPoints[i].pointId)
                        }
                    }

                    onCanceled: {
                        for(var i=0;i<touchPoints.length;i++) {
                            modelData.onReleased()
                            modelData.onReleasedPitch(touchPoints[i].pointId)
                        }
                    }

                    onReleased: {
                        for(var i=0;i<touchPoints.length;i++) {
                            modelData.onReleased()
                            modelData.onReleasedPitch(touchPoints[i].pointId)
                        }
                    }

                    onGestureStarted: {
                        gesture.grab();
                    }
                }
            }
        }
    }
}