cmake_minimum_required(VERSION 3.10)
project(tests)

set(CMAKE_CXX_STANDARD 11)

# Добавление исполняемого файла для модульных тестов
add_executable(tests
    test/test_triangle.cpp
)

# Добавление Google Test в качестве сабмодуля
add_subdirectory(libs/googletest)

# Линковка с библиотекой Google Test и основным проектом
target_link_libraries(tests PRIVATE gtest gtest_main)
target_link_libraries(tests PRIVATE TriangleProject)

# Добавление директории с заголовочными файлами для модульных тестов
target_include_directories(tests PRIVATE 
    include  # заголовочные файлы основного проекта
    libs/googletest/googletest/include  # заголовочные файлы Google Test
)

# Настройка сборки и дополнительных параметров для модульных тестов
# Например, линковка необходимых библиотек или добавление опций компилятора
