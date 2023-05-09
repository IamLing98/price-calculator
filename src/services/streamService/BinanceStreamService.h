//
// Created by linhdv on 5/5/23.
//

#ifndef CALCULATOR_BINANCESTREAMSERVICE_H
#define CALCULATOR_BINANCESTREAMSERVICE_H

#include "../wsPriceStream/PriceWs.h"

#include "../../utils/logger/Logger.h"

class BinanceStreamService : public Logger {
private:
    string _target;
    string _host;
    string _port;
    int  _type;

public:
    BinanceStreamService();

    BinanceStreamService(string host, string port, string target, int type);

    int start();

    const string &getTarget() const;

    void setTarget(const string &target);

    const string &getHost() const;

    void setHost(const string &host);

    const string &getPort() const;

    void setPort(const string &port);

    int getType() const;

    void setType(int type);

};


#endif //CALCULATOR_BINANCESTREAMSERVICE_H
