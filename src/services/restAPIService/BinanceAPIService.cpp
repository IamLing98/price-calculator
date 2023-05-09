//
// Created by linhdv on 5/8/23.
//

#include "BinanceAPIService.h"

//std::ifstream f("/home/linhdv/JSProjects/exchange/calculator/config.json");
//json config = json::parse(f);
//string baseUrl = config["API_URL"]["BASE_URL"];
//string serverTimeBaseUrl = config["API_URL"]["SERVER_TIME_BASE_URL"];
//string apiKey = config["API_KEY"];
//string secret = config["SECRET_KEY"];

BinanceAPIService::BinanceAPIService() {
    this->client = new Client(DataUtils::baseUrl);
}

string encryptWithHMAC(const char *key, const char *data) {
    unsigned char *result;
    static char res_hexstring[64];
    int result_len = 32;
    string signature;

    result = HMAC(EVP_sha256(), key, strlen((char *) key),
                  const_cast<unsigned char *>(reinterpret_cast<const unsigned char *>(data)), strlen((char *) data),
                  NULL, NULL);
    for (int i = 0; i < result_len; i++) {
        sprintf(&(res_hexstring[i * 2]), "%02x", result[i]);
    }

    for (int i = 0; i < 64; i++) {
        signature += res_hexstring[i];
    }

    return signature;
}

string BinanceAPIService::getSignature(string serverTime) {
    string query = "timestamp=" + serverTime;
    cout << "Query" << query << endl;
    string signature = encryptWithHMAC(DataUtils::secret.c_str(), query.c_str());
    cout << "Signature: " << signature << endl;
    return signature;
}

Headers getCommonHeader() {
    Headers headers = {
            {"X-MBX-APIKEY", DataUtils::apiKey},
            {"-m",           "3"},
            {"Content-Type", "application/json"}
    };
    return headers;
}

string BinanceAPIService::getListenKey() {
    this->client = new Client(DataUtils::baseUrl);
    try {
        Headers headers = getCommonHeader();
        auto res = this->client->Post("/fapi/v1/listenKey", headers);
        cout << "Body: " << res->body << endl;
        delete this->client;
        json json = json::parse(res->body);
        string listenKey = to_string(json["listenKey"]);

        return listenKey.substr(1, listenKey.size() - 2);
    } catch (exception &ex) {
        cout << "Get listen key error: " << ex.what() << endl;
    }
}

string BinanceAPIService::getServerTime() {
    this->client = new Client(DataUtils::serverTimeBaseUrl);
    try {
        Headers headers = getCommonHeader();
        auto res = this->client->Get("/api/v3/time", headers);
        cout << "Body: " << res->body << endl;
        json json = json::parse(res->body);
        delete this->client;
        return to_string(json["serverTime"]);
    } catch (exception &ex) {
        cout << "Get time server error: " << ex.what() << endl;
    }
}

string BinanceAPIService::getAccountInfo(string serverTime, string signature) {
    this->client = new Client(DataUtils::baseUrl);
    try {
        Headers headers = getCommonHeader();
        auto res = this->client->Get("/fapi/v2/account?timestamp=" + serverTime + "&signature=" + signature, headers);
        cout << "Body: " << res->body << endl;
        delete this->client;
        return res->body;
    } catch (exception &ex) {
        cout << "Get time server error: " << ex.what() << endl;
    }
}