#include "ClientApi.h"

#define MAX_NO_DATA_COUNT 100

ClientApi::ClientApi(const std::string &ipAddr, const uint16_t port) : TCPClient(ipAddr, port)
{
    thread_running = true;
}

ClientApi::~ClientApi()
{
    thread_running = false;
    m_connectionStatus = false;
}

bool ClientApi::sendJsonMessage(json data, std::string messageName)
{
    if(getConnectionStatus())
    {
        std::unique_lock<std::mutex> lck(m_mtx);
        json jD;
        jD["senderID"] = 3;
        jD["receiverID"] = 1;
        jD["messageName"] = messageName;
        jD["payload"] = data;
        auto saveData = jD.dump();
        auto wLen = boost::asio::write(*m_socket, boost::asio::buffer(saveData, static_cast<int>(saveData.length())));
        return (wLen > 0);
    }
    return false;
}

bool ClientApi::getConnectionStatus() const
{
    return m_connectionStatus;
}