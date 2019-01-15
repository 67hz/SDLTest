cmake_minimum_required(VERSION 3.13)
project(SDLTest)

set(CMAKE_CXX_STANDARD 14)
find_package(SDL2 REQUIRED)
add_executable(SDLTest main.cpp)
include_directories("/usr/local/include/SDL2")
include_directories(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} "/usr/local/lib/libSDL2.dylib")
