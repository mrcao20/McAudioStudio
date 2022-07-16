import QtQuick
import QtQuick.Controls
import McAudioPlayer 1.0

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    McAudioPlayer {
        id: audio
    }

    Button {
        text: "aaaaaaaaaaaaa"
        onClicked: {
            audio.play()
        }
    }
}
