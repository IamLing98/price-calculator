//
// Created by linhdv on 5/5/23.
//

#include "PriceService.h"

PriceService::PriceService(){}

int PriceService::start() {
    auto const host = "fstream.binance.com";
    auto const port = "443";
    auto const text = "/ws/!markPrice@arr";

// The io_context is required for all I/O
    net::io_context ioc;

// The SSL context is required, and holds certificates
    ssl::context ctx{ssl::context::tlsv12_client};

// This holds the root certificate used for verification
    load_root_certificates(ctx);

// Launch the asynchronous operation
    std::shared_ptr <PriceWs> p = std::make_shared<PriceWs>(ioc, ctx);
    p->run(host, port, text);
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