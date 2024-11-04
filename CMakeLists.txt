# Engine build file
#
# Matthew Todd Geiger

cmake_minimum_required(VERSION 3.0)
project(ether2d)

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

# Glob sources
file(GLOB SOURCES "src/*.cpp")

# Create shared library
add_library(ether2d SHARED ${SOURCES})

# Create static library
add_library(ether2d_static STATIC ${SOURCES})

# Include SDL3 libraries
target_include_directories(ether2d PRIVATE ${SDL3_SOURCE_DIR}/include)
target_include_directories(ether2d_static PRIVATE ${SDL3_SOURCE_DIR}/include)

# Link with static SDL3
target_link_libraries(ether2d PRIVATE SDL3-static)
target_link_libraries(ether2d_static PRIVATE SDL3-static)

# Set output name
set_target_properties(ether2d PROPERTIES OUTPUT_NAME "ether2d")
set_target_properties(ether2d_static PROPERTIES OUTPUT_NAME "ether2d")
