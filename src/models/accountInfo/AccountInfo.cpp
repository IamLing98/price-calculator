//
// Created by linhdv on 4/19/23.
//

#include "AccountInfo.h"

AccountInfo::AccountInfo(json accountInfoJson) {
    this->feeTier = accountInfoJson["feeTier"];
    this->canTrade = accountInfoJson["canTrade"];
    this->canDeposit = accountInfoJson["canDeposit"];
    this->canWithdraw = accountInfoJson["canWithdraw"];
    this->updateTime = accountInfoJson["updateTime"];
    this->multiAssetsMargin = accountInfoJson["multiAssetsMargin"];
    this->totalInitialMargin = accountInfoJson["totalInitialMargin"];
    this->totalMaintMargin = accountInfoJson["totalMaintMargin"];
    this->totalWalletBalance = accountInfoJson["totalWalletBalance"];
    this->totalUnrealizedProfit = accountInfoJson["totalUnrealizedProfit"];
    this->totalMarginBalance = accountInfoJson["totalMarginBalance"];
    this->totalPositionInitialMargin = accountInfoJson["totalPositionInitialMargin"];
    this->totalOpenOrderInitialMargin = accountInfoJson["totalOpenOrderInitialMargin"];
    this->totalCrossWalletBalance = accountInfoJson["totalCrossWalletBalance"];
    this->totalCrossUnPnl = accountInfoJson["totalCrossUnPnl"];
    this->availableBalance = accountInfoJson["availableBalance"];
    this->maxWithdrawAmount = accountInfoJson["maxWithdrawAmount"];
    json assets = accountInfoJson["assets"];
    string usdt = "USDT";
    string busd = "BUSD";
    cout << "Find usdt asset and busd asset" << endl;
    for (int i = 0; i < assets.size(); i++) {
        json asset = assets[i];
        if (usdt.compare(asset["asset"]) == 0) {
            this->assetUSDT = new Asset(asset);
        }
        if (busd.compare(asset["asset"]) == 0) {
            this->assetBUSD = new Asset(asset);
        }
    }
}

json AccountInfo::toJSON() {
    json accountInfoJson;
    accountInfoJson["feeTier"] = this->feeTier;
    accountInfoJson["canTrade"] = this->canTrade;
    accountInfoJson["canDeposit"] = this->canDeposit;
    accountInfoJson["canWithdraw"] = this->canWithdraw;
    accountInfoJson["updateTime"] = this->updateTime;
    accountInfoJson["multiAssetsMargin"] = this->multiAssetsMargin;
    accountInfoJson["totalInitialMargin"] = this->totalInitialMargin;
    accountInfoJson["totalMaintMargin"] = this->totalMaintMargin;
    accountInfoJson["totalWalletBalance"] = this->totalWalletBalance;
    accountInfoJson["totalUnrealizedProfit"] = this->totalUnrealizedProfit;
    accountInfoJson["totalMarginBalance"] = this->totalMarginBalance;
    accountInfoJson["totalPositionInitialMargin"] = this->totalPositionInitialMargin;
    accountInfoJson["totalOpenOrderInitialMargin"] = this->totalOpenOrderInitialMargin;
    accountInfoJson["totalCrossWalletBalance"] = this->totalCrossWalletBalance;
    accountInfoJson["totalCrossUnPnl"] = this->totalCrossUnPnl;
    accountInfoJson["availableBalance"] = this->availableBalance;
    accountInfoJson["maxWithdrawAmount"] = this->maxWithdrawAmount;
    accountInfoJson["assetBUSD"] = this->assetBUSD->toJSON();
    accountInfoJson["assetUSDT"] = this->assetUSDT->toJSON();
    return accountInfoJson;
}

double AccountInfo::getFeeTier() const {
    return feeTier;
}

void AccountInfo::setFeeTier(double feeTier) {
    AccountInfo::feeTier = feeTier;
}

bool AccountInfo::isCanTrade() const {
    return canTrade;
}

void AccountInfo::setCanTrade(bool canTrade) {
    AccountInfo::canTrade = canTrade;
}

bool AccountInfo::isCanDeposit() const {
    return canDeposit;
}

void AccountInfo::setCanDeposit(bool canDeposit) {
    AccountInfo::canDeposit = canDeposit;
}

bool AccountInfo::isCanWithdraw() const {
    return canWithdraw;
}

void AccountInfo::setCanWithdraw(bool canWithdraw) {
    AccountInfo::canWithdraw = canWithdraw;
}

double AccountInfo::getUpdateTime() const {
    return updateTime;
}

void AccountInfo::setUpdateTime(double updateTime) {
    AccountInfo::updateTime = updateTime;
}

bool AccountInfo::isMultiAssetsMargin() const {
    return multiAssetsMargin;
}

void AccountInfo::setMultiAssetsMargin(bool multiAssetsMargin) {
    AccountInfo::multiAssetsMargin = multiAssetsMargin;
}

const string &AccountInfo::getTotalInitialMargin() const {
    return totalInitialMargin;
}

void AccountInfo::setTotalInitialMargin(const string &totalInitialMargin) {
    AccountInfo::totalInitialMargin = totalInitialMargin;
}

const string &AccountInfo::getTotalMaintMargin() const {
    return totalMaintMargin;
}

void AccountInfo::setTotalMaintMargin(const string &totalMaintMargin) {
    AccountInfo::totalMaintMargin = totalMaintMargin;
}

const string &AccountInfo::getTotalWalletBalance() const {
    return totalWalletBalance;
}

void AccountInfo::setTotalWalletBalance(const string &totalWalletBalance) {
    AccountInfo::totalWalletBalance = totalWalletBalance;
}

const string &AccountInfo::getTotalUnrealizedProfit() const {
    return totalUnrealizedProfit;
}

void AccountInfo::setTotalUnrealizedProfit(const string &totalUnrealizedProfit) {
    AccountInfo::totalUnrealizedProfit = totalUnrealizedProfit;
}

const string &AccountInfo::getTotalMarginBalance() const {
    return totalMarginBalance;
}

void AccountInfo::setTotalMarginBalance(const string &totalMarginBalance) {
    AccountInfo::totalMarginBalance = totalMarginBalance;
}

const string &AccountInfo::getTotalPositionInitialMargin() const {
    return totalPositionInitialMargin;
}

void AccountInfo::setTotalPositionInitialMargin(const string &totalPositionInitialMargin) {
    AccountInfo::totalPositionInitialMargin = totalPositionInitialMargin;
}

const string &AccountInfo::getTotalOpenOrderInitialMargin() const {
    return totalOpenOrderInitialMargin;
}

void AccountInfo::setTotalOpenOrderInitialMargin(const string &totalOpenOrderInitialMargin) {
    AccountInfo::totalOpenOrderInitialMargin = totalOpenOrderInitialMargin;
}

const string &AccountInfo::getTotalCrossWalletBalance() const {
    return totalCrossWalletBalance;
}

void AccountInfo::setTotalCrossWalletBalance(const string &totalCrossWalletBalance) {
    AccountInfo::totalCrossWalletBalance = totalCrossWalletBalance;
}

const string &AccountInfo::getTotalCrossUnPnl() const {
    return totalCrossUnPnl;
}

void AccountInfo::setTotalCrossUnPnl(const string &totalCrossUnPnl) {
    AccountInfo::totalCrossUnPnl = totalCrossUnPnl;
}

const string &AccountInfo::getAvailableBalance() const {
    return availableBalance;
}

void AccountInfo::setAvailableBalance(const string &availableBalance) {
    AccountInfo::availableBalance = availableBalance;
}

const string &AccountInfo::getMaxWithdrawAmount() const {
    return maxWithdrawAmount;
}

void AccountInfo::setMaxWithdrawAmount(const string &maxWithdrawAmount) {
    AccountInfo::maxWithdrawAmount = maxWithdrawAmount;
}
