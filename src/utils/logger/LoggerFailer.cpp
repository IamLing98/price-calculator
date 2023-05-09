//
// Created by linhdv on 5/5/23.
//

#include "LoggerFailer.h"

void LoggerFailer::fail(beast::error_code ec, char const *what) {
    std::cerr << what << ": " << ec.message() << "\n";
}