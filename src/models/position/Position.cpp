//
// Created by linhdv on 4/20/23.
//

#include "Position.h"

#include<string>

using namespace std;

Position::Position(json input) {
    try {
        cout << "Init position" << input.dump() << endl;
        this->symbol = input["symbol"];
        this->initialMargin = stod(input["initialMargin"].get<std::string>());
        this->maintMargin = stod(input["maintMargin"].get<std::string>());
        this->unrealizedProfit = stod(input["unrealizedProfit"].get<std::string>());
        this->positionInitialMargin = stod(input["positionInitialMargin"].get<std::string>());
        this->openOrderInitialMargin = stod(input["openOrderInitialMargin"].get<std::string>());
        this->leverage = stoi(input["leverage"].get<std::string>());
        this->isolated = input["isolated"];
        this->entryPrice = stod(input["entryPrice"].get<std::string>());
        this->maxNotional = stol(input["maxNotional"].get<std::string>());
        this->positionSide = input["positionSide"];
        this->positionAmt = stol(input["positionAmt"].get<std::string>());
        this->notional = stod(input["notional"].get<std::string>());
        this->isolatedWallet = stol(input["isolatedWallet"].get<std::string>());
        this->updateTime = input["updateTime"];
        this->bidNotional = input["bidNotional"];
        this->askNotional = input["askNotional"];
    } catch (exception &ex) {
        cout << "Init position failed" << endl;
    }
}

const string &Position::getSymbol() const {
    return symbol;
}

void Position::setSymbol(const string &symbol) {
    Position::symbol = symbol;
}

double Position::getInitialMargin() const {
    return initialMargin;
}

void Position::setInitialMargin(double initialMargin) {
    Position::initialMargin = initialMargin;
}

double Position::getMaintMargin() const {
    return maintMargin;
}

void Position::setMaintMargin(double maintMargin) {
    Position::maintMargin = maintMargin;
}

double Position::getUnrealizedProfit() const {
    return unrealizedProfit;
}

void Position::setUnrealizedProfit(double unrealizedProfit) {
    Position::unrealizedProfit = unrealizedProfit;
}

double Position::getPositionInitialMargin() const {
    return positionInitialMargin;
}

void Position::setPositionInitialMargin(double positionInitialMargin) {
    Position::positionInitialMargin = positionInitialMargin;
}

double Position::getOpenOrderInitialMargin() const {
    return openOrderInitialMargin;
}

void Position::setOpenOrderInitialMargin(double openOrderInitialMargin) {
    Position::openOrderInitialMargin = openOrderInitialMargin;
}

int Position::getLeverage() const {
    return leverage;
}

void Position::setLeverage(int leverage) {
    Position::leverage = leverage;
}

bool Position::isIsolated() const {
    return isolated;
}

void Position::setIsolated(bool isolated) {
    Position::isolated = isolated;
}

double Position::getEntryPrice() const {
    return entryPrice;
}

void Position::setEntryPrice(double entryPrice) {
    Position::entryPrice = entryPrice;
}

long Position::getMaxNotional() const {
    return maxNotional;
}

void Position::setMaxNotional(long maxNotional) {
    Position::maxNotional = maxNotional;
}

const string &Position::getPositionSide() const {
    return positionSide;
}

void Position::setPositionSide(const string &positionSide) {
    Position::positionSide = positionSide;
}

long Position::getPositionAmt() const {
    return positionAmt;
}

void Position::setPositionAmt(long positionAmt) {
    Position::positionAmt = positionAmt;
}

double Position::getNotional() const {
    return notional;
}

void Position::setNotional(double notional) {
    Position::notional = notional;
}

long Position::getIsolatedWallet() const {
    return isolatedWallet;
}

void Position::setIsolatedWallet(long isolatedWallet) {
    Position::isolatedWallet = isolatedWallet;
}

long Position::getUpdateTime() const {
    return updateTime;
}

void Position::setUpdateTime(long updateTime) {
    Position::updateTime = updateTime;
}

const string &Position::getBidNotional() const {
    return bidNotional;
}

void Position::setBidNotional(const string &bidNotional) {
    Position::bidNotional = bidNotional;
}

const string &Position::getAskNotional() const {
    return askNotional;
}

void Position::setAskNotional(const string &askNotional) {
    Position::askNotional = askNotional;
}
