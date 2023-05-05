//
// Created by linhdv on 5/5/23.
//

#include "Logger.h"

void Logger::fail(beast::error_code ec, char const *what) {
    std::cerr << what << ": " << ec.message() << "\n";
}