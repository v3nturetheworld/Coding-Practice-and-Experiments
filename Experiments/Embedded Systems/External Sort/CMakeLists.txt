cmake_minimum_required(VERSION 3.5)


option (test "Build All Tests" off)

set(PROJECT_NAME ExternalSort)
set(library_SOURCES src/external-sort.cpp)
set(CMAKE_CXX_FLAGS "-g -Wall")

add_library(ExternalSortlib SHARED ${library_SOURCES})

target_include_directories(ExternalSortlib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(ExternalSort src/main.cpp)

target_link_libraries(ExternalSort ExternalSortlib)

if(test)
    find_package(GTest)
    if(GTEST_FOUND)
        include_directories(${GTEST_INCLUDE_DIRS})
        message("Google Tests External Library found.")
    else()
        message("GTest library not found on system. Looking in lib/googletest/googletest.")
        add_subdirectory(lib/googletest/googletest)
        set(GTEST_ROOT ${gtest_SOURCE_DIR})
        find_package(GTest REQUIRED)
        include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
    endif()

    enable_testing()

    set(test_SOURCES tests/test_external_sort.cpp tests/test_generate_data.cpp)

    add_executable(ExternalSort_UnitTests ${test_SOURCES})
    target_link_libraries(ExternalSort_UnitTests gtest gtest_main ExternalSortlib)
    add_test(NAME all_tests COMMAND ExternalSort_UnitTests)
endif()


