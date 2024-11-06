# Asteroids build file

cmake_minimum_required(VERSION 3.10)

# Set C++ version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Export compile commands for intellisense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Glob sources
file(GLOB SOURCES "src/*.cpp")

# Set up executable
add_executable(asteroids ${SOURCES})

# Link with engine
target_link_libraries(asteroids PRIVATE ether2d_static)
