cmake_minimum_required(3.0)
find_package(PkgConfig)
pkg_check_modules(GTEST REQUIRED gtest>=1.7.0)
include_directories(${GTEST_INCLUDE_DIRS})