add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../googletest ${CMAKE_CURRENT_BINARY_DIR}/googletest-build)

add_executable(test_circle test_circle.cpp)

target_link_libraries(test_circle gtest gtest_main circle_library)

include(GoogleTest)
gtest_discover_tests(test_circle)
