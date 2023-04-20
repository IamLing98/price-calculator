//
// Created by linhdv on 4/19/23.
//

#include "MarkPrice.h"

MarkPrice::MarkPrice() {

}

MarkPrice::MarkPrice(json markPriceJson) {
    cout<<"Mark price init"<<endl;
    if (markPriceJson != NULL) {
        for (int i = 0; i < markPriceJson.size(); i++) {
            this->prices[markPriceJson[i]["s"]] = markPriceJson[i];
        }
    }
}

const json &MarkPrice::getPrices() const {
    return prices;
}

void MarkPrice::setPrices(const json &prices) {
    MarkPrice::prices = prices;
}