cmake_minimum_required(VERSION 3.10)
project(сircleProject)

# Укажите путь к Google Test
add_subdirectory(../googletest googletest-build)

# Добавьте каталог с исходным кодом
add_subdirectory(src)

# Добавьте каталог с тестами
add_subdirectory(tests)