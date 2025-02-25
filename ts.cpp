#include <portaudio.h>
#include <iostream>

int main() {
    PaError err = Pa_Initialize();
    if (err != paNoError) {
        std::cerr << "PortAudio 初始化失败: " << Pa_GetErrorText(err) << std::endl;
        return 1;
    }

    std::cout << "PortAudio 初始化成功！" << std::endl;

    Pa_Terminate();
    return 0;
}