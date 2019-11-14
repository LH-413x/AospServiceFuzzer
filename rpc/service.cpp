//
// Created by alex on 2019/11/14.
//

#include "service.h"


namespace Rpc{
    void Service::Loop(){
        int new_socket;
        int addrlen;

        if (listen(server_fd, 3) < 0){
            perror("listen");
            exit(EXIT_FAILURE);
        }
        while (true){
            int id;
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                     (socklen_t*)&addrlen))<0){
                perror("accept");
                exit(EXIT_FAILURE);
            }
            read( new_socket , &id, sizeof(id));
            Call(id);
        }
    }

    void Service::Call(int id){
        RpcData* data = (*rpc_map)[id]();
        send(server_fd, data, data->len+sizeof(int),0);
        free(data);
    }

    Service::Service(std::string _name, std::shared_ptr<RpcMap> rpcmap){
        int server_fd;
        int opt = 1;
	this->name=_name;
	this->rpc_map=rpcmap;
        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
            perror("socket failed");
            exit(EXIT_FAILURE);
        }

        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                       &opt, sizeof(opt))){
            perror("setsockopt");
            exit(EXIT_FAILURE);
        }
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons( port );

        if (bind(server_fd, (struct sockaddr *)&address,
                 sizeof(address))<0){
            perror("bind failed");
            exit(EXIT_FAILURE);
        }

    }
}
