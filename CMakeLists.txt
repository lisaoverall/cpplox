cmake_minimum_required(VERSION 3.0.0)
project(cpplox VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB SRC_FILES *.cc)
add_executable(cpplox ${SRC_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
