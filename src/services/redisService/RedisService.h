//
// Created by linhdv on 5/9/23.
//

#ifndef CALCULATOR_REDISSERVICE_H
#define CALCULATOR_REDISSERVICE_H

#include <cstdlib>
#include <iostream>

#include <sw/redis++/redis++.h>
using namespace sw::redis;

#include <string>

#include "../../utils/DataUtils.h"

using namespace std;

class RedisService {
private:
    string _url;
    Redis *_client;
public:
    RedisService();
    void set(string key, string value);
    string get(string key);
};


#endif //CALCULATOR_REDISSERVICE_H
