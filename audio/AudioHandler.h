#ifndef AUDIOHANDLER_H
#define AUDIOHANDLER_H

#include <portaudio.h>
#include <vector>

class AudioHandler {
public:
    AudioHandler();
    ~AudioHandler();

    bool startRecording();
    bool stopRecording();
    bool startPlayback();
    bool stopPlayback();

    std::vector<float> getAudioData();

private:
    PaStream *stream;
    std::vector<float> audioData;
};

#endif // AUDIOHANDLER_H