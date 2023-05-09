#!/bin/bash

#Using redis-plus-plus https://github.com/sewenew/redis-plus-plus
function installRedis(){
  git clone https://github.com/redis/hiredis.git
  cd hiredis
  make
  sudo make install
  git clone https://github.com/sewenew/redis-plus-plus.git
  cd redis-plus-plus
  mkdir build
  cd build
  cmake ..
  make
  sudo make install
  cd ..
}