//===- FuzzerLocalTracePC.h - Internal header for the Fuzzer ---------*- C++ -* ===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
// fuzzer::LocalTracePC
//===----------------------------------------------------------------------===//

#ifndef LLVM_FUZZER_TRACE_PC
#define LLVM_FUZZER_TRACE_PC


#include "FuzzerDefs.h"


namespace reporter{

    struct Module {
        struct Region {
            uint8_t *Start, *Stop;
            bool Enabled;
            bool OneFullPage;
        };
        Region *Regions;
        size_t NumRegions;
        uint8_t *Start() { return Regions[0].Start; }
        uint8_t *Stop()  { return Regions[NumRegions - 1].Stop; }
        size_t Size()   { return Stop() - Start(); }
        size_t  Idx(uint8_t *P) {
            assert(P >= Start() && P < Stop());
            return P - Start();
        }
    };

    struct LocalTracePC{
    public:
        uint8_t* start;
        uint8_t* stop;
        size_t NumModules;
        Module Modules[4096];

        void setRegin(uint8_t* start, uint8_t* stop){
            this->start=start;
            this->stop=stop;
        }

        void ClearInlineCounters() {
            IterateCounterRegions([](const Module::Region &R){
                if (R.Enabled)
                    memset(R.Start, 0, R.Stop - R.Start);
            });
        }

        template <class Callback>
        void IterateCounterRegions(Callback CB) {
            for (size_t m = 0; m < NumModules; m++)
                for (size_t r = 0; r < Modules[m].NumRegions; r++)
                    CB(Modules[m].Regions[r]);
        }
    };

    extern LocalTracePC pc;
}



#endif  // LLVM_FUZZER_TRACE_PC
