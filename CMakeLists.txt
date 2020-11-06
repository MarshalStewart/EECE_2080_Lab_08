cmake_minimum_required(VERSION 2.6)
set(CMAKE_BUILD_TYPE Debug)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library (applibrary ADT.cpp) 

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread applibrary)


add_executable(runMain Main.cpp)
target_link_libraries(runMain applibrary)

