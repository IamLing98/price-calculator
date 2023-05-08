//
// Created by linhdv on 5/5/23.
//

#ifndef CALCULATOR_TICKERPRICE_H
#define CALCULATOR_TICKERPRICE_H

#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using namespace nlohmann;
using namespace std;

class TickerPrice {
private:
    json objectJson;
    string eventType;
    long eventTime;
    string symbol;
    string markPrice;
    string indexPrice;
    string estimatedSettlePrice;
    string fundingRate;
    long nextFundingTime;
public:
    TickerPrice();

    TickerPrice(json object_json);

    void toString() {
        cout << this->objectJson.dump() << endl;
    }

    const json &getObjectJson() const;

    void setObjectJson(const json &objectJson);

    const string &getEventType() const;

    void setEventType(const string &eventType);

    long getEventTime() const;

    void setEventTime(long eventTime);

    const string &getSymbol() const;

    void setSymbol(const string &symbol);

    const string &getMarkPrice() const;

    void setMarkPrice(const string &markPrice);

    const string &getIndexPrice() const;

    void setIndexPrice(const string &indexPrice);

    const string &getEstimatedSettlePrice() const;

    void setEstimatedSettlePrice(const string &estimatedSettlePrice);

    const string &getFundingRate() const;

    void setFundingRate(const string &fundingRate);

    long getNextFundingTime() const;

    void setNextFundingTime(long nextFundingTime);
};


#endif //CALCULATOR_TICKERPRICE_H
