cmake_minimum_required(VERSION 3.19)

project(calculator)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CppKafka REQUIRED)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(calculator
        src/main.cpp
        src/models/accountInfo/AccountInfo.cpp
        src/models/accountInfo/AccountInfo.h
        src/models/markPrice/MarkPrice.cpp
        src/models/markPrice/MarkPrice.h
        src/models/asset/Asset.cpp
        src/models/asset/Asset.h
        src/utils/DataUtils.cpp
        src/utils/DataUtils.h
        src/models/position/Position.cpp
        src/models/position/Position.h
        src/models/tickerPrice/TickerPrice.cpp
        src/models/tickerPrice/TickerPrice.h
        src/services/wsServer/SocketServer.cpp
        src/services/wsServer/SocketServer.h
        src/services/wsServer/Session.cpp
        src/services/wsServer/Session.h
        src/services/wsPriceStream/PriceWs.cpp
        src/services/wsPriceStream/PriceWs.h
        src/utils/logger/Logger.cpp
        src/utils/logger/Logger.h
        src/services/priceService/PriceService.cpp
        src/services/priceService/PriceService.h
        src/services/binanceService/BinanceService.cpp
        src/services/binanceService/BinanceService.h
        )

target_link_libraries(calculator CppKafka::cppkafka)

# <------------ add hiredis dependency --------------->
find_path(HIREDIS_HEADER hiredis)
target_include_directories(calculator PUBLIC ${HIREDIS_HEADER})

find_library(HIREDIS_LIB hiredis)
target_link_libraries(calculator ${HIREDIS_LIB})

# <------------ add redis-plus-plus dependency -------------->
# NOTE: this should be *sw* NOT *redis++*
find_path(REDIS_PLUS_PLUS_HEADER sw)
target_include_directories(calculator PUBLIC ${REDIS_PLUS_PLUS_HEADER})

find_library(REDIS_PLUS_PLUS_LIB redis++)
target_link_libraries(calculator ${REDIS_PLUS_PLUS_LIB})

set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)

add_executable(calculator ${SOURCE_FILES})
target_link_libraries(calculator OpenSSL::Crypto)