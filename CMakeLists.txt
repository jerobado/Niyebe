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

project(Niyebe VERSION 1.2.0)

function(windows_setup)    
    set(OPENSSL_ROOT_DIR "C:/msys64/ucrt64")
    set(OPENSSL_INCLUDE_DIR "${OPENSSL_ROOT_DIR}/include")
    set(OPENSSL_CRYPTO_LIBRARY "${OPENSSL_ROOT_DIR}/lib/libcrypto.a")
    set(OPENSSL_SSL_LIBRARY "${OPENSSL_ROOT_DIR}/lib/libssl.a")
    set(OPENSSL_LIBRARIES "${OPENSSL_SSL_LIBRARY};${OPENSSL_CRYPTO_LIBRARY}")
    find_package(OpenSSL REQUIRED)
endfunction()

function(linux_setup)
    find_package(OpenSSL REQUIRED)
endfunction()

if(WIN32)
    message("Using Windows setup")
    windows_setup()
elseif(UNIX)
    message("Using Linux setup")
    linux_setup()
endif()


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -g")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -Wextra -O2")

set(${PROJECT_NAME}_VERSION_MAJOR 1)
set(${PROJECT_NAME}_VERSION_MINOR 2)
set(${PROJECT_NAME}_VERSION_PATCH 0)

configure_file(${CMAKE_SOURCE_DIR}/include/NiyebeConfig.h.in
               ${CMAKE_BINARY_DIR}/include/NiyebeConfig.h)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(niyebe
               src/main.cpp
               src/niyebe.cpp
               src/encryption.cpp)

target_include_directories(niyebe PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}/include
)

target_link_libraries(niyebe PRIVATE 
    OpenSSL::SSL 
    OpenSSL::Crypto
)

# Install
# cmake --install build/release --prefix /opt/niyebe
if(UNIX)
    message("Platform: ${CMAKE_SYSTEM_NAME}")
    install(TARGETS niyebe
            RUNTIME DESTINATION bin)
elseif(WIN32)
    message("Platform: ${CMAKE_SYSTEM_NAME}")
    install(PROGRAMS "${CMAKE_BINARY_DIR}/bin/niyebe"
            DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")
endif()
