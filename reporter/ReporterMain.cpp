#include "Reporter.h"
extern "C" {
// This function should be defined by the user.
int     LLVMFuzzerReporter(int argc, char** argv);
}  // extern "C"

ATTRIBUTE_INTERFACE int main(int argc, char **argv) {
    char *skpath=argv[0];
    return reporter::Reporter(argc, argv, LLVMFuzzerReporter, skpath);
}
