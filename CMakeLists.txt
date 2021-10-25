#Cmake version
cmake_minimum_required(VERSION 3.16)

#Project name
project(RType)

#Flags
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall -Wextra -g -ggdb -g3")

#Bin name
set(SERVER_NAME r-type_server)
set(CLIENT_NAME r-type_client)

#Truc conan
include(${CMAKE_SOURCE_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup(TARGETS KEEP_RPATHS)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

#include
include_directories(src)

#Sources
set(CLIENT_SRC )
set(SERVER_SRC )
set(SHARED_SRC )

#Compilation
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/")

add_executable(${SERVER_NAME} ${SERVER_SRC} ${SHARED_SRC})
add_executable(${CLIENT_NAME} ${CLIENT_SRC} ${SHARED_SRC})

conan_target_link_libraries(${SERVER_NAME} ${CONAN_LIBS})
conan_target_link_libraries(${CLIENT_NAME} ${CONAN_LIBS})
