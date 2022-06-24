cmake_minimum_required(VERSION 3.14)
project(cpplox VERSION 0.1.0)

# turn on with cmake -Dtest=ON
option(test "Build all tests." OFF)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -Wall")

file(GLOB SRC_FILES *.cc)
add_executable(cpplox ${SRC_FILES})

# Testing
if (test)
    include(CTest)
    enable_testing()

    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    include(GoogleTest)

    list(REMOVE_ITEM SRC_FILES "${CMAKE_SOURCE_DIR}/main.cc")
    add_executable(
    scanner_test
    test/scanner_test.cc
    ${SRC_FILES}
    )

    target_include_directories(
        scanner_test
        PRIVATE
        ${CMAKE_SOURCE_DIR}
    )

    target_link_libraries(
        scanner_test
        PRIVATE
        gtest_main
    )

    # gtest_discover_tests(scanner_test)

endif (test)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
