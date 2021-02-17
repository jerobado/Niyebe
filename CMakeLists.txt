# Build instruction
# $ cmake -H. -Bbuild
# $ make -C build
# $ ./build/bin/niyebe


cmake_minimum_required(VERSION 3.10)

# Project name
project(Niyebe)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(UNIX)
    message("Platform: ${CMAKE_SYSTEM_NAME}")
elseif(WIN32)
    message("Platform: ${CMAKE_SYSTEM_NAME}")    
endif()

# Executable
add_executable(niyebe src/main.cpp)
