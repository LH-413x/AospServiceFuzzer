//
// Created by alex on 2019/11/12.
//
#include "Reporter.h"
#include "LocalTracePC.h"
#include <thread>
#include <sys/mman.h>



namespace reporter{

    std::shared_ptr<Rpc::Service> cov_service=nullptr;

    RpcData* getRegion(){
        int size= sizeof(int)+sizeof(pc.start)+sizeof(pc.stop);
        RpcData* data=(RpcData*)malloc( + size);
        data->len=size;
        size_t* p = (size_t*)data->content;
        p[0]=(size_t)pc.start;
        p[1]=(size_t)pc.stop;
        return data;
    }

    RpcData* resetRegion(){
        pc.ClearInlineCounters();
        return nullptr;
    }

    void startCoverageService(char* skpath){
        std::shared_ptr<RpcMap> rpc_map=std::make_shared<RpcMap>();
        (*rpc_map)[GET_RIGION]=getRegion;
        (*rpc_map)[RESET_RIGION]=resetRegion;
        cov_service=std::make_shared<Rpc::Service>(std::string(skpath),rpc_map);
        cov_service->Loop();
    }

    int Reporter(int argc, char** argv, std::function<int(int argc , char** argv)> CB, char* skpath){
        std::thread service_thread(startCoverageService,skpath);
        int ret = CB(argc, argv);
        service_thread.join();
        return ret;
    }
}
