//
// Created by alex on 2019/11/14.
//

#include <client.h>

int main(){
    std::shared_ptr< Rpc::Client> client=std::make_shared<Rpc::Client>();
    client->Call(RESET_RIGION);

    RpcData* data = client->Call(GET_RIGION);
    uint8_t* start = (uint8_t*)(((size_t*)data->content)[0]);
    uint8_t* stop = (uint8_t*)(((size_t*)data->content)[1]);
    std::cout << "start: " << (size_t)(start) << std::endl;
    std::cout << "stop: " << (size_t)(start) << std::endl;


    free(data);
}