//
// Created by linhdv on 4/20/23.
//

#include "DataUtils.h"

std::ifstream f("/home/linhdv/JSProjects/exchange/calculator/config.json");
json config = json::parse(f);

const string DataUtils::baseUrl =  config["API_URL"]["BASE_URL"];
const string DataUtils::serverTimeBaseUrl = config["API_URL"]["SERVER_TIME_BASE_URL"];
const string DataUtils::userDataStreamURL = config["STREAM_URL"]["USER_STREAM"];
const string DataUtils::apiKey = config["API_KEY"];
const string DataUtils::secret = config["SECRET_KEY"];