cmake_minimum_required(VERSION 3.20)

file(GLOB TEST_SRCS *.cpp)
# add multiple test files here
foreach( file ${TEST_SRCS} )
    get_filename_component(name ${file} NAME_WE)
    add_executable(${name} ${file})
    target_link_libraries(${name}
                    PRIVATE
                    GTest::gtest_main
                    leekle
                    )
    add_test(NAME ${name} COMMAND ${name})
endforeach( file ${TEST_SRCS} )


enable_testing()

include(GoogleTest)
gtest_discover_tests(${name})