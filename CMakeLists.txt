cmake_minimum_required(VERSION 3.19)

project(calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CppKafka REQUIRED)

add_executable(calculator
        src/main.cpp
        src/services/PriceService.cpp
        src/services/PriceService.h
        src/models/accountInfo/AccountInfo.cpp
        src/models/accountInfo/AccountInfo.h
        src/models/markPrice/MarkPrice.cpp
        src/models/markPrice/MarkPrice.h
        src/models/asset/Asset.cpp
        src/models/asset/Asset.h
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