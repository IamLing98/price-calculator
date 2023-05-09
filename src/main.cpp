#include <iostream>

#include "headers.h"

void start() {
    BinanceStreamService *priceService = new BinanceStreamService();
//    streamService->start();
}

void wsServerStart() {
    BinanceAPIService *binanceService = new BinanceAPIService();
    binanceService->getListenKey();
    string serverTime = binanceService->getServerTime();
    string signature = binanceService->getSignature(serverTime);
    binanceService->getAccountInfo(serverTime, signature);
    BinanceStreamService *streamService = new BinanceStreamService();
    streamService->start();
}

int main(int argc, char **argv) {
//    unique_ptr<BinanceStreamService> streamService(new BinanceStreamService());
    thread priceServiceThread(start);
    thread socketServerThread(wsServerStart);
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}