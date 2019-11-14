link_directories(${CMAKE_BINARY_DIR}/lib)
include_directories(include)
include_directories(${PROJECT_SOURCE_DIR}/rpc)
set(src LocalTracePC.cpp
        Reporter.cpp
        ReporterMain.cpp)

add_library(Reporter ${src})
target_link_libraries(Reporter cov_rpc)