#Cmake version
cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
include_directories(include)

#Sources

set(CLIENT_MAIN src/Client/Main.cpp )
set(SERVER_MAIN )
set(CLIENT_SRC )
set(SERVER_SRC )
set(SHARED_SRC src/ECS/Entity/Entity.cpp
        src/ECS/Entity/Entity.hpp
        src/ECS/Entity/EntityManager.cpp
        src/ECS/Entity/EntityManager.hpp
        src/SparseArray/SparseArray.hpp
        src/ECS/Entity/EntityException.cpp
        src/ECS/Entity/EntityException.hpp
        src/ECS/Component/ComponentException.hpp
        src/ECS/System/SystemManager.cpp
        src/ECS/System/SystemManager.hpp
        src/ECS/Component/ComponentManager.hpp
        src/ECS/ECS.cpp
        src/ECS/ECS.hpp
        src/ECS/System/ASystem.hpp
        src/ECS/System/ASystem.cpp
        src/ECS/System/Audio.cpp
        src/ECS/System/Audio.hpp
        src/ECS/System/Drawable.hpp
        src/ECS/System/Drawable.cpp
        src/Graphical/SfmlDisplay.cpp
        src/Graphical/SfmlDisplay.hpp
        src/Graphical/IGraphical.hpp)

#Compilation
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/")

if(NOT UNIT_TESTS STREQUAL TRUE)
    #add_executable(${SERVER_NAME} ${SERVER_MAIN} ${SERVER_SRC} ${SHARED_SRC})
    #conan_target_link_libraries(${SERVER_NAME} ${CONAN_LIBS})

    add_executable(${CLIENT_NAME} ${CLIENT_MAIN} ${CLIENT_SRC} ${SHARED_SRC})
    conan_target_link_libraries(${CLIENT_NAME} ${CONAN_LIBS})
else()
    set(TESTS_NAME unit_tests)
    set(TESTS_SRC ${CLIENT_SRC} ${SERVER_SRC} ${SHARED_SRC})
    set(TESTS_SRC ${TESTS_SRC}
            tests/SparseArrayTests.cpp)

    set(CMAKE_CXX_FLAGS --coverage)

    add_executable(${TESTS_NAME} ${TESTS_SRC})
    find_library(CRITERION criterion)
    target_link_libraries(${TESTS_NAME} ${CRITERION})
    conan_target_link_libraries(${TESTS_NAME} ${CONAN_LIBS})

endif()