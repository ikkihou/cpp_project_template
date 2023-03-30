cmake_minimum_required(VERSION 3.20)

enable_testing()

add_executable(unit_test main.cpp)

target_link_libraries(unit_test 
                    PRIVATE
                    GTest::gtest_main
                    leekle
                    )


include(GoogleTest)
gtest_discover_tests(unit_test)
