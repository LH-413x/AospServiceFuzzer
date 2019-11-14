//
// Created by alex on 2019/11/14.
//

#include "client.h"

namespace Rpc{

Client::Client() {
    if(connect(client_fd,(struct sockaddr *)&address,sizeof(address))==-1){
        perror("connect client fail");
        exit(0);
    }
}

uint8_t recv_buffer[0x10000];

RpcData* Client::Call(int id) {
    send(client_fd, &id, sizeof(id),0);
    recv(client_fd, recv_buffer, sizeof(recv_buffer),0);
    int size=*((int*)recv_buffer);
    RpcData* data=(RpcData*)malloc(size+sizeof(size));
    memcpy(data, recv_buffer, size);
    return data;
}

}