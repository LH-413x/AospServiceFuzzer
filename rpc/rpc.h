//
// Created by alex on 2019/11/14.
//

#ifndef AOSP_SERVICE_FUZZER_RPC_H
#define AOSP_SERVICE_FUZZER_RPC_H

#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>

#include <unistd.h>
#include <sys/socket.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <functional>
#include <string>
#include <cstring>
#include <netinet/in.h>

enum{
    GET_RIGION,
    RESET_RIGION
};

struct RpcData{
    int len;
    uint8_t content[];
};

using RpcMap = std::unordered_map<int, std::function<RpcData*()>>;

#endif //AOSP_SERVICE_FUZZER_RPC_H
