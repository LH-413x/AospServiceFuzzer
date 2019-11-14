//
// Created by alex on 2019/11/14.
//

#ifndef AOSP_SERVICE_FUZZER_CLIENT_H
#define AOSP_SERVICE_FUZZER_CLIENT_H
#include "rpc.h"

namespace Rpc{
class Client{
    public:
        Client();
        RpcData* Call(int id);
    private:
        int client_fd;
        struct sockaddr_in address;
};

}


#endif //AOSP_SERVICE_FUZZER_CLIENT_H
