#include <iostream>

#include "headers.h"

void start() {
    PriceService *priceService = new PriceService();
    priceService->start();
}

void wsServerStart(){

}

int main(int argc, char **argv) {
//    unique_ptr<PriceService> priceService(new PriceService());
    thread priceServiceThread(start);
    thread socketServerThread(wsServerStart);
    while(true){
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}