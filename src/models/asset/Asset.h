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

    const string &getAsset() const;

    void setAsset(const string &asset);

    const string &getWalletBalance() const;

    void setWalletBalance(const string &walletBalance);

    const string &getUnrealizedProfit() const;

    void setUnrealizedProfit(const string &unrealizedProfit);

    const string &getMarginBalance() const;

    void setMarginBalance(const string &marginBalance);

    const string &getMaintMargin() const;

    void setMaintMargin(const string &maintMargin);

    const string &getInitialMargin() const;

    void setInitialMargin(const string &initialMargin);

    const string &getPositionInitialMargin() const;

    void setPositionInitialMargin(const string &positionInitialMargin);

    const string &getOpenOrderInitialMargin() const;

    void setOpenOrderInitialMargin(const string &openOrderInitialMargin);

    const string &getMaxWithdrawAmount() const;

    void setMaxWithdrawAmount(const string &maxWithdrawAmount);

    const string &getCrossWalletBalance() const;

    void setCrossWalletBalance(const string &crossWalletBalance);

    const string getCrossUnPnl() const;

    void setCrossUnPnl(const string &crossUnPnl);

    const string &getAvailableBalance() const;

    void setAvailableBalance(const string &availableBalance);

    bool isMarginAvailable() const;

    void setMarginAvailable(bool marginAvailable);

    double getUpdateTime() const;

    void setUpdateTime(double updateTime);
};


#endif //CALCULATOR_ASSET_H
