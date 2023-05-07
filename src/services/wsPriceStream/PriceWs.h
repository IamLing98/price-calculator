//
// Created by linhdv on 5/5/23.
//

#ifndef CALCULATOR_PRICEWS_H
#define CALCULATOR_PRICEWS_H

#include "./root_certificates.hpp"
#include <boost/beast/core.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/beast/websocket/ssl.hpp>
#include <boost/asio/strand.hpp>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <chrono>
#include <ctime>

#include "../../utils/logger/Logger.h"

using namespace std;

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
namespace ssl = boost::asio::ssl;       // from <boost/asio/ssl.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

class PriceWs : public std::enable_shared_from_this<PriceWs>, Logger {
private:
    tcp::resolver resolver_;
    websocket::stream<
            beast::ssl_stream<beast::tcp_stream>> ws_;
    beast::flat_buffer buffer_;
    std::string host_;
    std::string text_;
public:
    explicit PriceWs(net::io_context &ioc, ssl::context &ctx);

    // Start the asynchronous operation
    void run(char const *host, char const *port, char const *text);

    void enable_async_read();

    bool is_socket_open();

    void on_resolve(beast::error_code ec, tcp::resolver::results_type results);

    void on_connect(beast::error_code ec, tcp::resolver::results_type::endpoint_type ep);

    void on_ssl_handshake(beast::error_code ec);

    void on_handshake(beast::error_code ec);

    void on_write(beast::error_code ec, std::size_t bytes_transferred);

    void on_read(beast::error_code ec, std::size_t bytes_transferred);

    void on_close(beast::error_code ec);
};


#endif //CALCULATOR_PRICEWS_H
