#pragma once
#include <boost/asio.hpp>
#include "Tools.h"
#define BOOST_BUFFER_SIZE_MAX 65536

using boost::asio::ip::tcp;

class TCPIPBase
{
public:
    TCPIPBase();
    ~TCPIPBase();	
    bool isConnected() const;
    bool m_connectionStatus;
    tcp::socket* m_socket = nullptr;
    boost::asio::io_context* m_io_context = nullptr;   
};
