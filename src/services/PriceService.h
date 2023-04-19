//
// Created by linhdv on 4/19/23.
//

#ifndef CALCULATOR_PRICESERVICE_H
#define CALCULATOR_PRICESERVICE_H

#include <stdexcept>
#include <iostream>
#include <csignal>
#include <boost/program_options.hpp>
#include "cppkafka/consumer.h"
#include "cppkafka/configuration.h"

#include <sw/redis++/redis++.h>
using namespace sw::redis;

using std::string;
using std::exception;
using std::cout;
using std::endl;

using cppkafka::Consumer;
using cppkafka::Configuration;
using cppkafka::Message;
using cppkafka::TopicPartitionList;

namespace po = boost::program_options;

#include <nlohmann/json.hpp>
using namespace nlohmann;

#include <chrono>
using namespace std::chrono;

#include <memory>
using namespace std;

#include "../models/markPrice/MarkPrice.h"
#include "../models/accountInfo/AccountInfo.h"

class PriceService {
private:

public:
    PriceService();
    void *init();
};


#endif //CALCULATOR_PRICESERVICE_H
