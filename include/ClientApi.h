#pragma once

#include "TCPClient.h"

class ClientApi : public TCPClient
{
public:
    ClientApi(const std::string &ipAddr, const uint16_t port);
    ~ClientApi();

    bool sendJsonMessage(json data, std::string messageName);
    bool getConnectionStatus() const;

private:
    std::mutex m_mtx;

};