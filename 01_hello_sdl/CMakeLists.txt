cmake_minimum_required(VERSION 3.10)

project(01_hello_sdl CXX)

add_executable(01_hello_sdl main.cpp)

target_include_directories(01_hello_sdl PRIVATE ${SDL2_INCLUDE_DIRS})

target_link_libraries(
  01_hello_sdl PRIVATE project_options project_warnings ${SDL2_LIBRARIES})
