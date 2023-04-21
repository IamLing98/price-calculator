//
// Created by linhdv on 4/20/23.
//

#ifndef CALCULATOR_POSITION_H
#define CALCULATOR_POSITION_H

#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
using namespace nlohmann;
using namespace std;

class Position {
private:
    string symbol;
    double initialMargin;
    double maintMargin;
    double unrealizedProfit;
    double positionInitialMargin;
    double openOrderInitialMargin;
    int leverage;
    bool isolated;
    double entryPrice;
    long maxNotional;
    string positionSide;
    long positionAmt;
    double notional;
    long isolatedWallet;
    long updateTime;
    string bidNotional;
    string askNotional;
public:
    Position();
    Position(json json);

    json toJson();

    const string &getSymbol() const;

    void setSymbol(const string &symbol);

    double getInitialMargin() const;

    void setInitialMargin(double initialMargin);

    double getMaintMargin() const;

    void setMaintMargin(double maintMargin);

    double getUnrealizedProfit() const;

    void setUnrealizedProfit(double unrealizedProfit);

    double getPositionInitialMargin() const;

    void setPositionInitialMargin(double positionInitialMargin);

    double getOpenOrderInitialMargin() const;

    void setOpenOrderInitialMargin(double openOrderInitialMargin);

    int getLeverage() const;

    void setLeverage(int leverage);

    bool isIsolated() const;

    void setIsolated(bool isolated);

    double getEntryPrice() const;

    void setEntryPrice(double entryPrice);

    long getMaxNotional() const;

    void setMaxNotional(long maxNotional);

    const string &getPositionSide() const;

    void setPositionSide(const string &positionSide);

    long getPositionAmt() const;

    void setPositionAmt(long positionAmt);

    double getNotional() const;

    void setNotional(double notional);

    long getIsolatedWallet() const;

    void setIsolatedWallet(long isolatedWallet);

    long getUpdateTime() const;

    void setUpdateTime(long updateTime);

    const string &getBidNotional() const;

    void setBidNotional(const string &bidNotional);

    const string &getAskNotional() const;

    void setAskNotional(const string &askNotional);

};


#endif //CALCULATOR_POSITION_H
