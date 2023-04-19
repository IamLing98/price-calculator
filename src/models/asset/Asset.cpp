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
}
