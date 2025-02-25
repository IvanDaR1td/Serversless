#include "AudioHandler.h"
#include <iostream>

AudioHandler::AudioHandler() : stream(nullptr) {
    Pa_Initialize();
}

AudioHandler::~AudioHandler() {
    Pa_Terminate();
}

bool AudioHandler::startRecording() {
    return Pa_OpenDefaultStream(&stream, 1, 0, paFloat32, 44100, 512, nullptr, nullptr) == paNoError;
}

bool AudioHandler::stopRecording() {
    return Pa_CloseStream(stream) == paNoError;
}

std::vector<float> AudioHandler::getAudioData() {
    return audioData;
}