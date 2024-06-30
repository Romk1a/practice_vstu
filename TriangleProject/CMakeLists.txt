cmake_minimum_required(VERSION 3.10)
project(TriangleProject)

set(CMAKE_CXX_STANDARD 11)

# Добавление исходных файлов
include_directories(include)
add_library(triangle src/triangle.cpp)

# Добавление исполняемого файла для main.cpp (если нужно)
# add_executable(main main.cpp)
# target_link_libraries(main triangle)

# Добавление исполняемого файла для тестов
enable_testing()
add_subdirectory(tests)
