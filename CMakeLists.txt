cmake_minimum_required(VERSION 3.16)
project(MyGame)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 3.0 COMPONENTS System Window Graphics Audio REQUIRED)

add_executable(MyGame src/main.cpp)

target_link_libraries(MyGame PRIVATE sfml-system sfml-window sfml-graphics sfml-audio)

target_include_directories(MyGame PRIVATE include)