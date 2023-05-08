//
// Created by linhdv on 5/8/23.
//

#ifndef CALCULATOR_BINANCESERVICE_H
#define CALCULATOR_BINANCESERVICE_H
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <iostream>
#include <string>

using namespace std;

#include "nlohmann/json.hpp"

using json = nlohmann::json;

#include "httplib.h"

using namespace httplib;



class BinanceService {

private:
    Client *client;

public:
    BinanceService();
    string getListenKey();
};


#endif //CALCULATOR_BINANCESERVICE_H
