cmake_minimum_required(VERSION 3.14)

project(ttt VERSION 0.1.0)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=-*,readability-*,bugprone-*,clang-analyzer-*)

add_executable(${PROJECT_NAME} 
  src/main.cpp
  src/application.cpp
  src/assetmanager.cpp
  src/gamestate.cpp
)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} SDL2_image)
target_include_directories(${PROJECT_NAME} PUBLIC include)

enable_testing()

add_executable(
  testbench
  src/application.cpp
  src/assetmanager.cpp
  src/gamestate.cpp
  test/application_tb.cpp
  test/configuration_tb.cpp
  test/gamestate_tb.cpp
  test/gamelogic_tb.cpp
)
target_link_libraries(
  testbench
  gtest_main
  ${SDL2_LIBRARIES} 
  SDL2_image
)
target_include_directories(testbench PUBLIC include)

include(GoogleTest)
gtest_discover_tests(testbench)
