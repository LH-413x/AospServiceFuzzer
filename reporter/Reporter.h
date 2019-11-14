//
// Created by alex on 2019/11/12.
//

#ifndef AOSP_SERVICE_FUZZER_REPORTER_H
#define AOSP_SERVICE_FUZZER_REPORTER_H


#include <sys/un.h>
#include <iostream>
#include <functional>
#include "service.h"
#include "LocalTracePC.h"



namespace reporter{
    int Reporter(int argc, char** argv, std::function<int(int argc, char** argv)>,char* skpath);
}



#endif //AOSP_SERVICE_FUZZER_REPORTER_H