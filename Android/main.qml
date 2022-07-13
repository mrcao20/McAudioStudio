import QtQuick
import QtQuick.Controls
import QtMultimedia
import AudioStudioCore 1.0

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    AudioGenerator {
        id: audio
    }

    MediaPlayer {
        id: playMusic
        source: "music.wav"
        audioOutput: AudioOutput {
            volume: 1.0
        }
    }

    Button {
        text: "aaaaaaaaaaaaa"
        onClicked: {
            playMusic.source = audio.generateData()
            playMusic.play()
            console.log(playMusic.source)
        }
    }
}
