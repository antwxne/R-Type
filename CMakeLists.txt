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
include_directories(include/Network)

#Sources

set(CLIENT_MAIN src/Client/main.cpp )
set(SERVER_MAIN src/Server/main.cpp)
set(CLIENT_SRC
            src/Client/RtypeClient.cpp
            src/Client/RtypeClient.hpp
            src/Client/Client.cpp
            src/Client/Client.hpp
            src/Client/TcpClient/TcpClient.cpp
            src/Client/TcpClient/TcpClient.hpp
            src/Client/TcpClient/TcpClientConnection.cpp
            src/Client/TcpClient/TcpClientConnection.hpp
            src/Client/TcpClient/TcpClientMessageHandler.cpp
            src/Client/TcpClient/TcpClientMessageHandler.hpp
            src/Client/UdpClient/UdpClient.cpp
            src/Client/UdpClient/UdpClient.hpp
            src/Client/UdpClient/UdpClientMessageHandler.cpp
            src/Client/UdpClient/UdpClientMessageHandler.hpp
            src/Client/UdpClient/UdpGameClient.cpp
            src/Client/UdpClient/UdpGameClient.hpp
)

set(SERVER_SRC 
            src/Server/ClientInformations.cpp
            src/Server/ClientInformations.hpp
            src/Server/GameInstance/GameInstance.cpp
            src/Server/GameInstance/GameInstance.hpp
            src/Server/GameInstance/GameInstancesHandler.cpp
            src/Server/GameInstance/GameInstancesHandler.hpp
            src/Server/TcpServer/TcpAsioServer.cpp
            src/Server/TcpServer/TcpAsioServer.hpp
            src/Server/TcpServer/TcpClientInstance.cpp
            src/Server/TcpServer/TcpClientInstance.hpp
            src/Server/TcpServer/TcpClientInstanceMessageHandler.cpp
            src/Server/TcpServer/TcpClientInstanceMessageHandler.hpp
            src/Server/UdpServer/GameUdpServer.cpp
            src/Server/UdpServer/GameUdpServer.hpp
            src/Server/UdpServer/UdpAsioServer.cpp
            src/Server/UdpServer/UdpAsioServer.hpp
            src/Server/UdpServer/UdpGameMessageHandler.cpp
            src/Server/UdpServer/UdpGameMessageHandler.hpp
)
set(SHARED_SRC 
        src/ECS/Entity/Entity.cpp
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
        src/ECS/System/MoveSystem.hpp
        src/ECS/System/MoveSystem.cpp
        src/ECS/System/Draw/DrawSystem.cpp
        src/ECS/System/Draw/DrawSystem.hpp
        src/ECS/System/Draw/SfmlDrawSystem.cpp
        src/ECS/System/Draw/SfmlDrawSystem.hpp
        src/ECS/System/Audio/AudioSystem.cpp
        src/ECS/System/Audio/AudioSystem.hpp
        src/ECS/System/Audio/SfmlSoundSystem.cpp
        src/ECS/System/Audio/SfmlSoundSystem.hpp
        src/ECS/Component/Audio.hpp
        src/ECS/Component/SfmlSound.hpp
        src/Graphical/SfmlDisplay.cpp
        src/Graphical/SfmlDisplay.hpp
        src/Graphical/SfmlButton.cpp
        src/Graphical/SfmlButton.hpp
        src/Graphical/SfmlMenu.cpp
        src/Graphical/SfmlMenu.hpp
        src/Graphical/SfmlEventFactory.hpp
        src/Graphical/SfmlEventFactory.cpp
        src/Graphical/IGraphical.hpp
        src/Graphical/SfmlParallax.cpp
        src/Graphical/SfmlParallax.hpp
        src/ECS/System/EventSystem/EventSystem.hpp
        src/ECS/System/EventSystem/EventSystem.cpp
        )

#Compilation
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/")

if(NOT UNIT_TESTS STREQUAL TRUE)
    add_executable(${SERVER_NAME} ${SERVER_MAIN} ${SERVER_SRC} ${SHARED_SRC})
    conan_target_link_libraries(${SERVER_NAME} ${CONAN_LIBS})

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