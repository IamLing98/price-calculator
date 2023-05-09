//
// Created by linhdv on 5/5/23.
//

#include "BinanceStreamService.h"

BinanceStreamService::BinanceStreamService() {}

BinanceStreamService::BinanceStreamService(string host, string port, string target, int type) {
    this->_host = host;
    this->_port = port;
    this->_target = target;

    /*
     1 Mark price
     2 User data stream
     */
    this->_type = type;
    cout << "Create new binance stream service: " << host << ":" << port << target << endl;
}

int BinanceStreamService::start() {
    auto const text = "/ws/!markPrice@arr@1s";

// The io_context is required for all I/O
    net::io_context ioc;

// The SSL context is required, and holds certificates
    ssl::context ctx{ssl::context::tlsv12_client};

// This holds the root certificate used for verification
    load_root_certificates(ctx);

// Launch the asynchronous operation
    std::shared_ptr<PriceWs> p = std::make_shared<PriceWs>(ioc, ctx);
    p->run(this->_host.c_str(), this->_port.c_str(), text, this->_target.c_str(), this->_type);
    ioc.run();

// Run the I/O service. The call will return when
// the socket is closed.
    while (p->is_socket_open()) {
        ioc.restart();
        p->enable_async_read();
        ioc.run();
    }
    return EXIT_SUCCESS;
}


const string &BinanceStreamService::getTarget() const {
    return _target;
}

void BinanceStreamService::setTarget(const string &target) {
    _target = target;
}

const string &BinanceStreamService::getHost() const {
    return _host;
}

void BinanceStreamService::setHost(const string &host) {
    _host = host;
}

const string &BinanceStreamService::getPort() const {
    return _port;
}

void BinanceStreamService::setPort(const string &port) {
    _port = port;
}

int BinanceStreamService::getType() const {
    return _type;
}

void BinanceStreamService::setType(int type) {
    _type = type;
}
