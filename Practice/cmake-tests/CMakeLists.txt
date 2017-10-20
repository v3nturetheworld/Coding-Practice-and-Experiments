cmake_minimum_required(VERSION 3.5)

option(test "Build All Tests" off)

set(PROJECT_NAME hello-world)
set(library_SOURCES src/hello-world.cpp)
set(CMAKE_CXX_FLAGS "-g -Wall")

add_library(hello-world_lib SHARED ${library_SOURCES})

target_include_directories(hello-world_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(helloWorld src/main.cpp)

target_link_libraries(helloWorld hello-world_lib)

if(test)

    add_subdirectory(lib/googletest/googletest)
    enable_testing()
    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

    set(test_SOURCES tests/test_hello-world.cpp)
    # target_include_directories(runUnitTests ${PROJECT_SOURCE_DIR}/include)
    add_executable(runUnitTests ${test_SOURCES})
    target_link_libraries(runUnitTests gtest gtest_main)
    target_link_libraries(runUnitTests hello-world_lib)
    add_test(NAME all_tests COMMAND runUnitTests)

endif()
