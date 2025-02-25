#ifndef P2PHANDLER_H
#define P2PHANDLER_H

#include <rtc/rtc.hpp>
#include <string>
#include <vector>
#include <memory>

class P2PHandler {
public:
    P2PHandler();
    ~P2PHandler();

    void startCall(const std::string &remoteSdp);
    void endCall();
    void sendAudioData(const std::vector<float> &data);

private:
    std::shared_ptr<rtc::PeerConnection> peerConnection;
};

#endif // P2PHANDLER_H