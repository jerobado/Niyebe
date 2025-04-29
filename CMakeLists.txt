#[[
Build instruction

Windows
> cmake -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=x86_64-w64-mingw32-g++ -DCMAKE_BUILD_TYPE=Debug -B build/debug
> cmake --build build/debug
> .\build\debug\bin\niyebe.exe 

Linux
$ cmake -H. -Bbuild
$ make -C build
$ ./build/bin/niyebe

]]

cmake_minimum_required(VERSION 3.10)

project(Niyebe VERSION 1.1.0)

function(windows_setup)    
    set(OPENSSL_ROOT_DIR "C:/Qt/Tools/OpenSSLv3/Win_x64")
    set(OPENSSL_INCLUDE_DIR "${OPENSSL_ROOT_DIR}/include")
    set(OPENSSL_LIBRARIES "${OPENSSL_ROOT_DIR}/lib/libssl.lib;${OPENSSL_ROOT_DIR}/lib/libcrypto.lib")
    find_package(OpenSSL REQUIRED)
endfunction()

function(linux_setup)
    set(OPENSSL_ROOT_DIR "/usr/local/ssl")
    set(OPENSSL_INCLUDE_DIR "/usr/local/include")
    find_package(OpenSSL REQUIRED)
endfunction()

if(WIN32)
    windows_setup()
elseif(UNIX)
    linux_setup()
endif()


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -g")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -Wextra -O2")

set(${PROJECT_NAME}_VERSION_MAJOR 1)
set(${PROJECT_NAME}_VERSION_MINOR 1)
set(${PROJECT_NAME}_VERSION_PATCH 0)

configure_file(include/NiyebeConfig.h.in ../include/NiyebeConfig.h)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(OPENSSL_ROOT_DIR)
include_directories(include)

add_executable(niyebe
               src/main.cpp
               src/niyebe.cpp
               src/encryption.cpp
               include/NiyebeConfig.h)

target_link_libraries(niyebe PRIVATE OpenSSL::SSL OpenSSL::Crypto)

# Install
# cmake --build build --config Release --target install
if(UNIX)
    message("Platform: ${CMAKE_SYSTEM_NAME}")
    install(PROGRAMS "${CMAKE_BINARY_DIR}/bin/niyebe"
            DESTINATION "~/Documents/Niyebe")
elseif(WIN32)
    message("Platform: ${CMAKE_SYSTEM_NAME}")
    install(PROGRAMS "${CMAKE_BINARY_DIR}/bin/niyebe"
            DESTINATION "{CMAKE_INSTALL_PREFIX}")
endif()
