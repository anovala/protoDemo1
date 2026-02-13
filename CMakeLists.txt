cmake_minimum_required(VERSION 3.10.0)
project(protoDemo1 VERSION 0.1.0 LANGUAGES C CXX)

find_package(protobuf CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_executable(protoDemo1 
    main.cpp 
    "${CMAKE_CURRENT_SOURCE_DIR}/user.proto"
)

set(PROTO_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")

protobuf_generate(
    TARGET protoDemo1
    LANGUAGE cpp
    IMPORT_DIRS "${CMAKE_CURRENT_SOURCE_DIR}"
    PROTOC_OUT_DIR "${PROTO_BINARY_DIR}"
)

target_link_libraries(protoDemo1 PRIVATE protobuf::libprotobuf fmt::fmt)

target_include_directories(protoDemo1 PRIVATE "${PROTO_BINARY_DIR}")