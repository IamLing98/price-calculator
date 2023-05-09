//
// Created by linhdv on 5/9/23.
//

#include "RedisService.h"

RedisService::RedisService() {
    this->_url = DataUtils::REDIS_URL;
    this->_client = new Redis(this->_url);
    cout << "Init redis connection successfully" << endl;
    this->_client->set("key", "val");
}

void RedisService::set(string key, string value) {
    this->_client->set(key, value);
}

string RedisService::get(string key) {
    OptionalString value = this->_client->get(key);
    return value.value();
}