//
// Created by linhdv on 4/19/23.
//

#ifndef CALCULATOR_ACCOUNTINFO_H
#define CALCULATOR_ACCOUNTINFO_H

#include <nlohmann/json.hpp>
using namespace nlohmann;
using namespace std;

#include "../asset/Asset.h"

#include <vector>

class AccountInfo {
private:
    double feeTier;
    bool canTrade;
    bool canDeposit;
    bool canWithdraw;
    double updateTime;
    bool multiAssetsMargin;
    string totalInitialMargin;
    string totalMaintMargin;
    string totalWalletBalance;
    string totalUnrealizedProfit;
    string totalMarginBalance;
    string totalPositionInitialMargin;
    string totalOpenOrderInitialMargin;
    string totalCrossWalletBalance;
    string totalCrossUnPnl;
    string availableBalance;
    string maxWithdrawAmount;
    Asset *assetUSDT;
    Asset *assetBUSD;
public:
    AccountInfo();

    AccountInfo(json accountInfoJson);

    json toJSON();

    double getFeeTier() const;

    void setFeeTier(double feeTier);

    bool isCanTrade() const;

    void setCanTrade(bool canTrade);

    bool isCanDeposit() const;

    void setCanDeposit(bool canDeposit);

    bool isCanWithdraw() const;

    void setCanWithdraw(bool canWithdraw);

    double getUpdateTime() const;

    void setUpdateTime(double updateTime);

    bool isMultiAssetsMargin() const;

    void setMultiAssetsMargin(bool multiAssetsMargin);

    const string &getTotalInitialMargin() const;

    void setTotalInitialMargin(const string &totalInitialMargin);

    const string &getTotalMaintMargin() const;

    void setTotalMaintMargin(const string &totalMaintMargin);

    const string &getTotalWalletBalance() const;

    void setTotalWalletBalance(const string &totalWalletBalance);

    const string &getTotalUnrealizedProfit() const;

    void setTotalUnrealizedProfit(const string &totalUnrealizedProfit);

    const string &getTotalMarginBalance() const;

    void setTotalMarginBalance(const string &totalMarginBalance);

    const string &getTotalPositionInitialMargin() const;

    void setTotalPositionInitialMargin(const string &totalPositionInitialMargin);

    const string &getTotalOpenOrderInitialMargin() const;

    void setTotalOpenOrderInitialMargin(const string &totalOpenOrderInitialMargin);

    const string &getTotalCrossWalletBalance() const;

    void setTotalCrossWalletBalance(const string &totalCrossWalletBalance);

    const string &getTotalCrossUnPnl() const;

    void setTotalCrossUnPnl(const string &totalCrossUnPnl);

    const string &getAvailableBalance() const;

    void setAvailableBalance(const string &availableBalance);

    const string &getMaxWithdrawAmount() const;

    void setMaxWithdrawAmount(const string &maxWithdrawAmount);

    string toString();
};

#endif //CALCULATOR_ACCOUNTINFO_H
