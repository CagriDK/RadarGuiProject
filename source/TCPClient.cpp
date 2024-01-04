#include "../include/TCPClient.h"

TCPClient::TCPClient(const std::string &ipAddr, const uint16_t port) : TCPIPBase()
{
    m_connectionStatus = false;
    m_endpoint = new tcp::endpoint(boost::asio::ip::address::from_string(ipAddr), port);
}

TCPClient::~TCPClient()
{
    if (m_endpoint != nullptr)
    {
        delete m_endpoint;
        m_endpoint = nullptr;
    }
}

void TCPClient::ConnectServer()
{
    m_connectionStatus = false;
    m_socket = new tcp::socket(*m_io_context);
    boost::system::error_code ec;
    m_socket->connect(*m_endpoint, ec);

    if(!ec)
    {
        m_connectionStatus = true;
    }
    else
    {
        m_connectionStatus = false;
    }
}