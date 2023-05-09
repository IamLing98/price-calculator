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
    const static string baseUrl;
    const static string serverTimeBaseUrl;
    const static string apiKey;
    const static string userDataStreamURL;
    const static string secret;
};


#endif //CALCULATOR_DATAUTILS_H
