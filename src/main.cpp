#include <iostream>

#include "headers.h"


void start() {
    BinanceStreamService *priceService = new BinanceStreamService();
//    streamService->start();
}

void wsServerStart() {
    BinanceAPIService *binanceService = new BinanceAPIService();
    string listenKey = binanceService->getListenKey();
    cout << "Listen key" << listenKey << endl;
    string serverTime = binanceService->getServerTime();
    string signature = binanceService->getSignature(serverTime);
//    binanceService->getAccountInfo(serverTime, signature);
    string target = "/ws?stream=!contractInfo&listenKey=" + listenKey;
    string host = "fstream-auth.binance.com";
    BinanceStreamService *userStream = new BinanceStreamService(host, "443", target, 2);
    userStream->start();
}

int main(int argc, char **argv) {
//    unique_ptr<BinanceStreamService> streamService(new BinanceStreamService());
    thread priceServiceThread(start);
    thread socketServerThread(wsServerStart);
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}