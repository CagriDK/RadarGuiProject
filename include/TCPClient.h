#pragma once

#include "TCPIPBase.h"

class TCPClient : public TCPIPBase
{
public:
    TCPClient(const std::string &ipAddr, const uint16_t port);
    ~TCPClient();
    void ConnectServer();

private:
    tcp::endpoint *m_endpoint;
};