//
// Created by linhdv on 5/5/23.
//

#include "Session.h"

Session::Session(tcp::socket &&socket) : ws_(std::move(socket)) {
}


void Session::run() {
    // We need to be executing within a strand to perform async operations
    // on the I/O objects in this session. Although not strictly necessary
    // for single-threaded contexts, this example code is written to be
    // thread-safe by default.
    net::dispatch(ws_.get_executor(),
                  beast::bind_front_handler(
                          &Session::on_run,
                          shared_from_this()));
}

void Session::on_run() {
    // Set suggested timeout settings for the websocket
    ws_.set_option(
            websocket::stream_base::timeout::suggested(
                    beast::role_type::server));

    // Set a decorator to change the Server of the handshake
    ws_.set_option(websocket::stream_base::decorator(
            [](websocket::response_type &res) {
                res.set(http::field::server,
                        std::string(BOOST_BEAST_VERSION_STRING) +
                        "websocket-server-async");
            }));

    // Accept the websocket handshake
    ws_.async_accept(
            beast::bind_front_handler(
                    &Session::on_accept,
                    shared_from_this()));
}

void Session::on_accept(beast::error_code ec) {
    if (ec)
        return fail(ec, "accept");
    // Read a message
    do_read();
}

void Session::do_read() {
    // Read a message into our buffer
    ws_.async_read(
            buffer_,
            beast::bind_front_handler(
                    &Session::on_read,
                    shared_from_this()));
}

void Session::on_read(beast::error_code ec, std::size_t bytes_transferred) {
    boost::ignore_unused(bytes_transferred);

    // This indicates that the session was closed
    if (ec == websocket::error::closed)
        return;

    if (ec)
        return fail(ec, "read");

    // Echo the message
    ws_.text(ws_.got_text());
    ws_.async_write(
            buffer_.data(),
            beast::bind_front_handler(
                    &Session::on_write,
                    shared_from_this()));
}

void Session::on_write(beast::error_code ec, std::size_t bytes_transferred) {
    boost::ignore_unused(bytes_transferred);
    if (ec)
        return fail(ec, "write");
    // Clear the buffer
    buffer_.consume(buffer_.size());

    // Do another read
    do_read();
}