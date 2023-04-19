//
// Created by linhdv on 4/19/23.
//

#ifndef CALCULATOR_ASSET_H
#define CALCULATOR_ASSET_H

#include <iostream>
#include <string>

using namespace std;

#include <nlohmann/json.hpp>

using namespace nlohmann;

class Asset {

private:
    string asset;
    string walletBalance;
    string unrealizedProfit;
    string marginBalance;
    string maintMargin;
    string initialMargin;
    string positionInitialMargin;
    string openOrderInitialMargin;
    string maxWithdrawAmount;
    string crossWalletBalance;
    string crossUnPnl;
    string availableBalance;
    bool marginAvailable;
    double updateTime;
public:
    Asset();

    Asset(json assetJson);
    json toJSON();
};


#endif //CALCULATOR_ASSET_H
