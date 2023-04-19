//
// Created by linhdv on 4/19/23.
//

#ifndef CALCULATOR_MARKPRICE_H
#define CALCULATOR_MARKPRICE_H

#include <nlohmann/json.hpp>
using namespace nlohmann;

#include <iostream>
using namespace std;

class MarkPrice {
private:
    json prices;
public:
    MarkPrice();
    MarkPrice(json markPriceJson);

    const json &getPrices() const;

    void setPrices(const json &prices);
};

#endif //CALCULATOR_MARKPRICE_H
