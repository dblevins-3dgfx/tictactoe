cmake_minimum_required(VERSION 3.14.0)

project(ttt VERSION 0.1.0)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/05CC6081FCBD0071053DE78238E136B3.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} src/main.cpp src/application.cpp)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} SDL2_image)
target_include_directories(${PROJECT_NAME} PUBLIC include)

enable_testing()

add_executable(
  application_tb
  src/application.cpp
  test/application_tb.cpp
)
target_link_libraries(
  application_tb
  gtest_main
  ${SDL2_LIBRARIES} 
  SDL2_image
)
target_include_directories(application_tb PUBLIC include)


include(GoogleTest)
gtest_discover_tests(application_tb)