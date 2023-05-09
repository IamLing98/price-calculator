//
// Created by linhdv on 4/20/23.
//

#include "DataUtils.h"

std::ifstream f("/home/linhdv/JSProjects/exchange/calculator/config.json");
json config = json::parse(f);

const string DataUtils::BASE_URL = config["API_URL"]["BASE_URL"];
const string DataUtils::SERVER_TIME_BASE_URL = config["API_URL"]["SERVER_TIME_BASE_URL"];
const string DataUtils::API_KEY = config["API_KEY"];
const string DataUtils::USER_DATA_STREAM_URL = config["STREAM_URL"]["USER_STREAM"];
const string DataUtils::SECRET_KEY = config["SECRET_KEY"];
const string DataUtils::REDIS_URL = config["REDIS_URL"];