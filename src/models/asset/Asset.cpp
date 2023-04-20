//
// Created by linhdv on 4/19/23.
//

#include "Asset.h"

Asset::Asset(json json) {
    this->asset = json["asset"];
    this->walletBalance = json["walletBalance"];
    this->unrealizedProfit = json["unrealizedProfit"];
    this->marginBalance = json["marginBalance"];
    this->maintMargin = json["maintMargin"];
    this->initialMargin = json["initialMargin"];
    this->positionInitialMargin = json["positionInitialMargin"];
    this->openOrderInitialMargin = json["openOrderInitialMargin"];
    this->maxWithdrawAmount = json["maxWithdrawAmount"];
    this->crossWalletBalance = json["crossWalletBalance"];
    this->crossUnPnl = json["crossUnPnl"];
    this->availableBalance = json["availableBalance"];
    this->marginAvailable = json["marginAvailable"];
    this->updateTime = json["updateTime"];
}

json Asset::toJSON() {
    json json;
    json["asset"] = this->asset;
    json["walletBalance"] = this->walletBalance;
    json["unrealizedProfit"] = this->unrealizedProfit;
    json["marginBalance"] = this->marginBalance;
    json["maintMargin"] = this->maintMargin;
    json["initialMargin"] = this->initialMargin;
    json["positionInitialMargin"] = this->positionInitialMargin;
    json["openOrderInitialMargin"] = this->openOrderInitialMargin;
    json["maxWithdrawAmount"] = this->maxWithdrawAmount;
    json["crossWalletBalance"] = this->crossWalletBalance;
    json["crossUnPnl"] = this->crossUnPnl;
    json["availableBalance"] = this->availableBalance;
    json["marginAvailable"] = this->marginAvailable;
    json["updateTime"] = this->updateTime;
    return json;
}

const string &Asset::getAsset() const {
    return asset;
}

void Asset::setAsset(const string &asset) {
    Asset::asset = asset;
}

const string &Asset::getWalletBalance() const {
    return walletBalance;
}

void Asset::setWalletBalance(const string &walletBalance) {
    Asset::walletBalance = walletBalance;
}

const string &Asset::getUnrealizedProfit() const {
    return unrealizedProfit;
}

void Asset::setUnrealizedProfit(const string &unrealizedProfit) {
    Asset::unrealizedProfit = unrealizedProfit;
}

const string &Asset::getMarginBalance() const {
    return marginBalance;
}

void Asset::setMarginBalance(const string &marginBalance) {
    Asset::marginBalance = marginBalance;
}

const string &Asset::getMaintMargin() const {
    return maintMargin;
}

void Asset::setMaintMargin(const string &maintMargin) {
    Asset::maintMargin = maintMargin;
}

const string &Asset::getInitialMargin() const {
    return initialMargin;
}

void Asset::setInitialMargin(const string &initialMargin) {
    Asset::initialMargin = initialMargin;
}

const string &Asset::getPositionInitialMargin() const {
    return positionInitialMargin;
}

void Asset::setPositionInitialMargin(const string &positionInitialMargin) {
    Asset::positionInitialMargin = positionInitialMargin;
}

const string &Asset::getOpenOrderInitialMargin() const {
    return openOrderInitialMargin;
}

void Asset::setOpenOrderInitialMargin(const string &openOrderInitialMargin) {
    Asset::openOrderInitialMargin = openOrderInitialMargin;
}

const string &Asset::getMaxWithdrawAmount() const {
    return maxWithdrawAmount;
}

void Asset::setMaxWithdrawAmount(const string &maxWithdrawAmount) {
    Asset::maxWithdrawAmount = maxWithdrawAmount;
}

const string &Asset::getCrossWalletBalance() const {
    return crossWalletBalance;
}

void Asset::setCrossWalletBalance(const string &crossWalletBalance) {
    Asset::crossWalletBalance = crossWalletBalance;
}

const string Asset::getCrossUnPnl() const {
    return crossUnPnl;
}

void Asset::setCrossUnPnl(const string &crossUnPnl) {
    Asset::crossUnPnl = crossUnPnl;
}

const string &Asset::getAvailableBalance() const {
    return availableBalance;
}

void Asset::setAvailableBalance(const string &availableBalance) {
    Asset::availableBalance = availableBalance;
}

bool Asset::isMarginAvailable() const {
    return marginAvailable;
}

void Asset::setMarginAvailable(bool marginAvailable) {
    Asset::marginAvailable = marginAvailable;
}

double Asset::getUpdateTime() const {
    return updateTime;
}

void Asset::setUpdateTime(double updateTime) {
    Asset::updateTime = updateTime;
}
