# Engine build file
#
# Matthew Todd Geiger

cmake_minimum_required(VERSION 3.10)
project(ether2d)

# Set C++ version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Export compile commands for intellisense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include fetch content modules
include(FetchContent)

# Set options before fetching SDL3
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_TEST OFF CACHE BOOL "" FORCE)
set(SDL_VIRTUAL_JOYSTICK ON CACHE BOOL "" FORCE)
set(CMAKE_POSITION_INDEPENDENT_CODE ON CACHE BOOL "" FORCE)

# Fetch SDL3
FetchContent_Declare(
	SDL3
	GIT_REPOSITORY https://github.com/lowlevelmetal/SDL.git
	GIT_TAG main
)

FetchContent_MakeAvailable(SDL3)

# Fetch spdlog
FetchContent_Declare(
	spdlog
	GIT_REPOSITORY https://github.com/lowlevelmetal/spdlog.git
	GIT_TAG v1.x
)

# Set options for spdlog before fetching it
set(SPDLOG_BUILD_SHARED OFF CACHE BOOL "" FORCE)  # Build static library
set(SPDLOG_INSTALL OFF CACHE BOOL "" FORCE)       # Prevent global install

FetchContent_MakeAvailable(spdlog)

# Glob sources
file(GLOB SOURCES "src/*.cpp")

# Create libraries
add_library(ether2d SHARED ${SOURCES})
add_library(ether2d_static STATIC ${SOURCES})

# Setup includes
target_include_directories(ether2d PUBLIC ${SDL3_SOURCE_DIR}/include src/include)
target_include_directories(ether2d_static PUBLIC ${SDL3_SOURCE_DIR}/include src/include)

# Link with deps
target_link_libraries(ether2d PUBLIC SDL3::SDL3-static spdlog::spdlog)
target_link_libraries(ether2d_static PUBLIC SDL3::SDL3-static spdlog::spdlog)

# Set output name
set_target_properties(ether2d PROPERTIES OUTPUT_NAME "ether2d")
set_target_properties(ether2d_static PROPERTIES OUTPUT_NAME "ether2d")

# Build example programs
add_subdirectory(examples)
