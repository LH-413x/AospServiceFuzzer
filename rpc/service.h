//
// Created by alex on 2019/11/14.
//

#ifndef AOSP_SERVICE_FUZZER_SERVICE_H
#define AOSP_SERVICE_FUZZER_SERVICE_H

#include "rpc.h"



namespace Rpc{
    class Service{
    public:
        Service(std::string _name, std::shared_ptr<RpcMap> RpcMap);
        void Loop();
    private:
        void Call(int id);
    private:
        std::shared_ptr<RpcMap> rpc_map;
        struct sockaddr_in address;
        int port=9000;
        int server_fd;
        std::string name;
    };
}
#endif //AOSP_SERVICE_FUZZER_SERVICE_H