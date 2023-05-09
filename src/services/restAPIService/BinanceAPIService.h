//
// Created by linhdv on 5/8/23.
//

#ifndef CALCULATOR_BINANCEAPISERVICE_H
#define CALCULATOR_BINANCEAPISERVICE_H
#define CPPHTTPLIB_OPENSSL_SUPPORT

#include <iostream>
#include <string>
#include <openssl/hmac.h>
using namespace std;

#include "nlohmann/json.hpp"
using json = nlohmann::json;

#include "httplib.h"
using namespace httplib;

#include "../../utils/DataUtils.h"

class BinanceAPIService {

private:
    Client *client;

public:
    BinanceAPIService();

    string getListenKey();

    string getServerTime();

    string getAccountInfo(string timeServer, string signature);

    string getSignature(string timestamp);

    string getPositionRisk(string serverTime, string signature);
};

#endif //CALCULATOR_BINANCEAPISERVICE_H
