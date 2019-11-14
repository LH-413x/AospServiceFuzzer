link_directories(${CMAKE_BINARY_DIR}/Lib)

set(srcs client.cpp
        service.cpp)
add_library(cov_rpc ${srcs})