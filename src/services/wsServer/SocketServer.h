//
// Created by linhdv on 5/5/23.
//

#ifndef CALCULATOR_SOCKETSERVER_H
#define CALCULATOR_SOCKETSERVER_H

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/dispatch.hpp>
#include <boost/asio/strand.hpp>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>
#include "./Session.h"
#include "../../utils/logger/LoggerFailer.h"

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

class SocketServer  : public std::enable_shared_from_this<SocketServer>, LoggerFailer {

private:
    net::io_context &ioc_;
    tcp::acceptor acceptor_;

public:
    SocketServer(net::io_context &ioc, tcp::endpoint endpoint);

    // Start accepting incoming connections
    void run();

private:
    void do_accept();

    void on_accept(beast::error_code ec, tcp::socket socket);
};


#endif //CALCULATOR_SOCKETSERVER_H
