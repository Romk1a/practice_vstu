cmake_minimum_required(VERSION 3.10)
project(parallelogramProject)

# Установка стандарта языка
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавление подкаталога для исходных файлов библиотеки
add_subdirectory(src)

# Добавление подкаталога для тестов
add_subdirectory(tests)
