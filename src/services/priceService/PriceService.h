//
// Created by linhdv on 5/5/23.
//

#ifndef CALCULATOR_PRICESERVICE_H
#define CALCULATOR_PRICESERVICE_H

#include "../wsPriceStream/PriceWs.h"

#include "../../utils/logger/Logger.h"

class PriceService : public Logger {

public:
    PriceService();

    int start();

};


#endif //CALCULATOR_PRICESERVICE_H
