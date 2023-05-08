//
// Created by linhdv on 5/8/23.
//

#include "BinanceService.h"

std::ifstream f("/home/linhdv/JSProjects/exchange/calculator/config.json");
json config = json::parse(f);
string baseUrl = config["API_URL"]["BASE_URL"];
string apiKey = config["API_KEY"];

BinanceService::BinanceService() {
    this->client = new Client(baseUrl);
}

string BinanceService::getListenKey() {
    Headers headers = {
            {"X-MBX-APIKEY", apiKey},
            {"-m",           "3",}
    };
    auto res = this->client->Post("/fapi/v1/listenKey", headers);
    cout << "Body" << res->body << endl;

}