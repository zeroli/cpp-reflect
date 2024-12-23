cmake_minimum_required(VERSION 3.18)

add_executable(ut
    main.cc
    class-register-test.cc
    test-class.cc
)

target_include_directories(ut PRIVATE ../src)
target_link_libraries(ut PRIVATE cpp-reflect)
target_link_libraries(ut PRIVATE gtest)
