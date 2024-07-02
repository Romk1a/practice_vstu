# Указываем исходный каталог и каталог сборки для GoogleTest
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../googletest ${CMAKE_CURRENT_BINARY_DIR}/googletest-build)

# Создание исполняемого файла тестов
add_executable(test_trapezoid test_trapezoid.cpp)

# Добавление зависимостей
target_link_libraries(test_trapezoid gtest gtest_main trapezoid_library)

# Добавление тестов
include(GoogleTest)
gtest_discover_tests(test_trapezoid)
