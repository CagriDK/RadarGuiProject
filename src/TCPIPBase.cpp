#include "TCPIPBase.h"

TCPIPBase::TCPIPBase() : m_connectionStatus(false) , m_socket(nullptr)
{
    m_io_context = new boost::asio::io_context();
}

TCPIPBase::~TCPIPBase()
{

    if (m_socket != nullptr)
    {
        if(m_socket->is_open())
        {
            m_socket->close();
        }

        delete m_socket;
        m_socket = nullptr;
    }

    if(m_io_context != nullptr)
    {
        delete m_io_context;
        m_io_context = nullptr;
    }
}

bool TCPIPBase::isConnected() const
{
    return m_connectionStatus;
}