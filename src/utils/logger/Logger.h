//
// Created by linhdv on 5/5/23.
//

#ifndef CALCULATOR_LOGGER_H
#define CALCULATOR_LOGGER_H

#include <iostream>
#include <boost/beast/core.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/beast/websocket/ssl.hpp>
#include <boost/asio/strand.hpp>

namespace beast = boost::beast;         // from <boost/beast.hpp>
//------------------------------------------------------------------------------


class Logger {
public:
    static void fail(beast::error_code ec, char const *what);

};


#endif //CALCULATOR_LOGGER_H
