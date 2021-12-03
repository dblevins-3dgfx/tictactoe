cmake_minimum_required(VERSION 3.0.0)

project(ttt VERSION 0.1.0)

add_executable(${PROJECT_NAME} src/main.cpp src/application.cpp)
target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image)
target_include_directories(${PROJECT_NAME} PUBLIC include)