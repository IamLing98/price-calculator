//
// Created by linhdv on 5/5/23.
//

#include "TickerPrice.h"


TickerPrice::TickerPrice() {

}

TickerPrice::TickerPrice(json objectJson) {
    this->objectJson = objectJson;
    this->eventType = objectJson["e"];
    this->eventTime = objectJson["E"];
    this->symbol = objectJson["s"];
    this->markPrice = objectJson["p"];
    this->indexPrice = objectJson["i"];
    this->estimatedSettlePrice = objectJson["P"];
    this->fundingRate = objectJson["r"];
    this->nextFundingTime = objectJson["T"];
}

const json &TickerPrice::getObjectJson() const {
    return objectJson;
}

void TickerPrice::setObjectJson(const json &objectJson) {
    TickerPrice::objectJson = objectJson;
}

const string &TickerPrice::getEventType() const {
    return eventType;
}

void TickerPrice::setEventType(const string &eventType) {
    TickerPrice::eventType = eventType;
}

long TickerPrice::getEventTime() const {
    return eventTime;
}

void TickerPrice::setEventTime(long eventTime) {
    TickerPrice::eventTime = eventTime;
}

const string &TickerPrice::getSymbol() const {
    return symbol;
}

void TickerPrice::setSymbol(const string &symbol) {
    TickerPrice::symbol = symbol;
}

const string &TickerPrice::getMarkPrice() const {
    return markPrice;
}

void TickerPrice::setMarkPrice(const string &markPrice) {
    TickerPrice::markPrice = markPrice;
}

const string &TickerPrice::getIndexPrice() const {
    return indexPrice;
}

void TickerPrice::setIndexPrice(const string &indexPrice) {
    TickerPrice::indexPrice = indexPrice;
}

const string &TickerPrice::getEstimatedSettlePrice() const {
    return estimatedSettlePrice;
}

void TickerPrice::setEstimatedSettlePrice(const string &estimatedSettlePrice) {
    TickerPrice::estimatedSettlePrice = estimatedSettlePrice;
}

const string &TickerPrice::getFundingRate() const {
    return fundingRate;
}

void TickerPrice::setFundingRate(const string &fundingRate) {
    TickerPrice::fundingRate = fundingRate;
}

long TickerPrice::getNextFundingTime() const {
    return nextFundingTime;
}

void TickerPrice::setNextFundingTime(long nextFundingTime) {
    TickerPrice::nextFundingTime = nextFundingTime;
}
