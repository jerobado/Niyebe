# Build instruction
# $ cmake -H. -Bbuild
# $ make -C build
# $ ./build/bin/niyebe


cmake_minimum_required(VERSION 3.10)

# Project name and version
project(Niyebe VERSION 0.1.1)

set (${PROJECT_NAME}_VERSION_MAJOR 0)
set (${PROJECT_NAME}_VERSION_MINOR 1)
set (${PROJECT_NAME}_VERSION_PATCH 1)

configure_file(include/NiyebeConfig.h.in ../include/NiyebeConfig.h)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Directories
include_directories(include)

# Executable
add_executable(niyebe
               src/main.cpp
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
