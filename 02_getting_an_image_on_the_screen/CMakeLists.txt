cmake_minimum_required(VERSION 3.10)

project(02_getting_an_image_on_the_screen CXX)

add_executable(02_getting_an_image_on_the_screen main.cpp)

target_include_directories(02_getting_an_image_on_the_screen PRIVATE ${SDL2_INCLUDE_DIRS})

target_link_libraries(
  02_getting_an_image_on_the_screen PRIVATE project_options project_warnings ${SDL2_LIBRARIES})
