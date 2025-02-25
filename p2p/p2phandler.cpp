#include "p2phandler.h"

P2PHandler::P2PHandler() {
    rtc::InitLogger(rtc::LogLevel::Debug);
}

P2PHandler::~P2PHandler() {}

void P2PHandler::startCall(const std::string &remoteSdp) {
    rtc::Configuration config;
    config.iceServers.emplace_back("stun:stun.l.google.com:19302");

    peerConnection = std::make_shared<rtc::PeerConnection>(config);
    peerConnection->setRemoteDescription(rtc::Description(remoteSdp, "offer"));
}

void P2PHandler::endCall() {
    peerConnection.reset();
}

void P2PHandler::sendAudioData(const std::vector<float> &data) {
    if (peerConnection) {
        peerConnection->send(data.data(), data.size());
    }
}