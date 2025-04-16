#[[
Build instruction

Windows
> cmake -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=x86_64-w64-mingw32-g++ -B build
> cmake --build build
> .\build\bin\niyebe.exe 

Linux
$ cmake -H. -Bbuild
$ make -C build
$ ./build/bin/niyebe

]]

cmake_minimum_required(VERSION 3.10)

# Project name and version
project(Niyebe VERSION 1.1.0)

set (${PROJECT_NAME}_VERSION_MAJOR 1)
set (${PROJECT_NAME}_VERSION_MINOR 1)
set (${PROJECT_NAME}_VERSION_PATCH "0-develop")

configure_file(include/NiyebeConfig.h.in ../include/NiyebeConfig.h)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Directories
include_directories(include)

# Executable
add_executable(niyebe
               src/main.cpp
               src/niyebe.cpp
               include/NiyebeConfig.h)

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
