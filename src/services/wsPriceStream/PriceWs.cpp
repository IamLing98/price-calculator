//
// Created by linhdv on 5/5/23.
//

#include "PriceWs.h"

bool sortByFundingRate(TickerPrice *tickerA, TickerPrice *tickerB) {
    std::string::size_type sz;
    float tickerAFoundingRate = std::stof(tickerA->getFundingRate(), &sz);
    float tickerBFoundingRate = std::stof(tickerB->getFundingRate(), &sz);

    return tickerAFoundingRate < tickerBFoundingRate;
}

void PriceWs::onMarkPriceMessage(beast::error_code ec, std::size_t bytes_transferred) {
    cout << "On read mark price message" << endl;
    boost::ignore_unused(bytes_transferred);
    if (ec)
        return fail(ec, "read");
    string jsonData = boost::beast::buffers_to_string(buffer_.data());
    json allMarkPrice = json::parse(jsonData);
    if (allMarkPrice != NULL && allMarkPrice.is_array()) {
        TickerPrice *tickerPrice;
        vector<TickerPrice *> markPriceVector;
        for (int i = 0; i < allMarkPrice.size(); i++) {
            tickerPrice = new TickerPrice(allMarkPrice[i]);
            markPriceVector.push_back(tickerPrice);
        }
        // using default comparison (operator <):
        std::sort(markPriceVector.begin(), markPriceVector.end(), sortByFundingRate);
        for (int i = 0; i < markPriceVector.size(); i++) {
            tickerPrice = markPriceVector[i];
            tickerPrice->toString();
        }
        for (auto p : markPriceVector) {
            delete p;
        }
        markPriceVector.clear();
    }
    std::cout << "On mark price message finished" << std::endl;
}

// Resolver and socket require an io_context
PriceWs::PriceWs(net::io_context &ioc, ssl::context &ctx)
        : resolver_(net::make_strand(ioc)), ws_(net::make_strand(ioc), ctx) {
}

// Start the asynchronous operation
void PriceWs::run(char const *host, char const *port, char const *text, char const *target, int type) {
    // Save these for later
    host_ = host;
    text_ = text;
    target_ = target;
    type_ = type;

    // Look up the domain name
    resolver_.async_resolve(host, port, beast::bind_front_handler(
            &PriceWs::on_resolve,
            shared_from_this())
    );
}

void PriceWs::enable_async_read() {
    buffer_.clear();

    switch (this->type_) {
        case 1:
            ws_.async_read(
                    buffer_,
                    beast::bind_front_handler(
                            &PriceWs::onMarkPriceMessage,
                            shared_from_this()));
            break;
        default:
            ws_.async_read(
                    buffer_,
                    beast::bind_front_handler(
                            &PriceWs::on_read,
                            shared_from_this()));
    }

}

bool PriceWs::is_socket_open() {
    return ws_.is_open();
}

void PriceWs::on_resolve(beast::error_code ec, tcp::resolver::results_type results) {
    if (ec)
        return fail(ec, "resolve");

    // Set a timeout on the operation
    beast::get_lowest_layer(ws_).expires_after(std::chrono::seconds(30));

    // Make the connection on the IP address we get from a lookup
    beast::get_lowest_layer(ws_).async_connect(
            results,
            beast::bind_front_handler(
                    &PriceWs::on_connect,
                    shared_from_this()));
}

void PriceWs::on_connect(beast::error_code ec, tcp::resolver::results_type::endpoint_type ep) {
    if (ec)
        return fail(ec, "connect");

    // Set a timeout on the operation
    beast::get_lowest_layer(ws_).expires_after(std::chrono::seconds(30));

    // Set SNI Hostname (many hosts need this to handshake successfully)
    if (!SSL_set_tlsext_host_name(
            ws_.next_layer().native_handle(),
            host_.c_str())) {
        ec = beast::error_code(static_cast<int>(::ERR_get_error()),
                               net::error::get_ssl_category());
        return fail(ec, "connect");
    }

    // Update the host_ string. This will provide the value of the
    // Host HTTP header during the WebSocket handshake.
    // See https://tools.ietf.org/html/rfc7230#section-5.4
    host_ += ':' + std::to_string(ep.port());

    // Perform the SSL handshake
    ws_.next_layer().async_handshake(
            ssl::stream_base::client,
            beast::bind_front_handler(
                    &PriceWs::on_ssl_handshake,
                    shared_from_this()));
}

void PriceWs::on_ssl_handshake(beast::error_code ec) {
    if (ec)
        return fail(ec, "ssl_handshake");

    // Turn off the timeout on the tcp_stream, because
    // the websocket stream has its own timeout system.
    beast::get_lowest_layer(ws_).expires_never();

    // Set suggested timeout settings for the websocket
    ws_.set_option(
            websocket::stream_base::timeout::suggested(
                    beast::role_type::client));

    // Set a decorator to change the User-Agent of the handshake
    ws_.set_option(websocket::stream_base::decorator(
            [](websocket::request_type &req) {
                req.set(http::field::user_agent,
                        std::string(BOOST_BEAST_VERSION_STRING) +
                        " websocket-client-async-ssl");
            }));

    // Perform the websocket handshake
    ws_.async_handshake(host_, target_,
                        beast::bind_front_handler(
                                &PriceWs::on_handshake,
                                shared_from_this()));
}

void PriceWs::on_handshake(beast::error_code ec) {
    cout << "On handshake" << endl;
    if (ec)
        return fail(ec, "handshake");

//        // Send the message
//        ws_.async_write(
//                net::buffer(text_),
//                beast::bind_front_handler(
//                        &session::on_write,
//                        shared_from_this()));

    ws_.async_read(
            buffer_,
            beast::bind_front_handler(
                    &PriceWs::on_read,
                    shared_from_this()));
}

void PriceWs::on_write(beast::error_code ec, std::size_t bytes_transferred) {
    cout << "On write" << endl;
    boost::ignore_unused(bytes_transferred);
    if (ec)
        return fail(ec, "write");

    // Read a message into our buffer
    ws_.async_read(
            buffer_,
            beast::bind_front_handler(
                    &PriceWs::on_read,
                    shared_from_this()));
}

void PriceWs::on_read(beast::error_code ec, std::size_t bytes_transferred) {
    cout << "On read" << endl;
    boost::ignore_unused(bytes_transferred);
    if (ec)
        return fail(ec, "read");

    // Close the WebSocket connection
//        ws_.async_close(websocket::close_code::normal,
//                        beast::bind_front_handler(
//                                &session::on_close,
//                                shared_from_this()));
    std::cout << beast::make_printable(buffer_.data()) << std::endl;
//    auto start = std::chrono::system_clock::now();
//    std::time_t end_time = std::chrono::system_clock::to_time_t(start);
//    cout<<"New message"<<ctime(&end_time)<<endl;
}

void PriceWs::on_close(beast::error_code ec) {
    cout << "On close" << endl;
    if (ec)
        return fail(ec, "close");

    // If we get here then the connection is closed gracefully

    // The make_printable() function helps print a ConstBufferSequence
//        std::cout << beast::make_printable(buffer_.data()) << std::endl;
    cout << "New message" << endl;
}
