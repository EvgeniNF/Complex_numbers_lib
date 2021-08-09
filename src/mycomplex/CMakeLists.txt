message("   CREATE LIB!")

set(LIB_NAME my_complex)

message("   LIB_NAME = ${LIB_NAME}")
message("   SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
message("   BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}")

set(CMAKE_CXX_STANDARD 20)

set(LIB_PATH ${PROJECT_SOURCE_DIR}/include/mycomplex)
set(HEADER_LIST ${LIB_PATH}/mycomplex.hpp)

find_package(Threads REQUIRED)

set(SOURCE  mycomplex.cpp)

add_library(${LIB_NAME}
        ${SOURCE}
        ${HEADER_LIST})

target_include_directories(${LIB_NAME} PUBLIC
        ${PROJECT_SOURCE_DIR}/include/mycomplex)

target_compile_features(${LIB_NAME} PUBLIC cxx_std_20)
