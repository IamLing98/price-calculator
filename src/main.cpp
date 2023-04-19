#include <iostream>

#include "headers.h"

int main() {
    unique_ptr<PriceService> priceService(new PriceService());
    priceService->init();
}
