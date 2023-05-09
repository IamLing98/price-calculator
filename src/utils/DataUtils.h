//
// Created by linhdv on 4/20/23.
//

#ifndef CALCULATOR_DATAUTILS_H
#define CALCULATOR_DATAUTILS_H

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

using namespace std;

using json = nlohmann::json;

class DataUtils {
public:
    const static string BASE_URL;
    const static string SERVER_TIME_BASE_URL;
    const static string API_KEY;
    const static string USER_DATA_STREAM_URL;
    const static string SECRET_KEY;
    const static string REDIS_URL;

};


#endif //CALCULATOR_DATAUTILS_H
