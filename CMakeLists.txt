cmake_minimum_required(VERSION 3.24.2)

project(TicTacToe)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)
include_directories(include)

file(GLOB_RECURSE SRC src/*.cpp)
list(REMOVE_ITEM SRC "src/main.cpp")

file(GLOB_RECURSE INCLUDE include/*.hpp)

add_library(core ${INCLUDE} ${SRC})

add_executable(ticTacToe src/main.cpp)

target_link_libraries(ticTacToe core)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB_RECURSE TEST tests/*.cpp)
add_executable(tests ${TEST})

target_link_libraries(
    tests
    core
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)