# Engine build file
#
# Matthew Todd Geiger

cmake_minimum_required(VERSION 3.0)
project(ether2d)

# Set C++ version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Export compile commands for intellisense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include fetch content modules
include(FetchContent)

# Fetch SDL3
FetchContent_Declare(
	SDL3
	GIT_REPOSITORY https://github.com/lowlevelmetal/SDL.git
	GIT_TAG main
)

# Set options before fetching SDL3
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_TEST OFF CACHE BOOL "" FORCE)
set(SDL_HIDAPI OFF CACHE BOOL "" FORCE)  # Disable HIDAPI if not needed
set(CMAKE_POSITION_INDEPENDENT_CODE ON CACHE BOOL "" FORCE)

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

# Create shared library
add_library(ether2d SHARED ${SOURCES})

# Create static library
add_library(ether2d_static STATIC ${SOURCES})

# Include SDL3 libraries
target_include_directories(ether2d PRIVATE ${SDL3_SOURCE_DIR}/include)
target_include_directories(ether2d_static PRIVATE ${SDL3_SOURCE_DIR}/include)

# Link with deps
target_link_libraries(ether2d PRIVATE SDL3-static spdlog::spdlog)
target_link_libraries(ether2d_static PRIVATE SDL3-static spdlog::spdlog)

# Set output name
set_target_properties(ether2d PROPERTIES OUTPUT_NAME "ether2d")
set_target_properties(ether2d_static PROPERTIES OUTPUT_NAME "ether2d")
