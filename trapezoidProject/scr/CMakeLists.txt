# Добавление всех cpp файлов из текущего каталога в библиотеку
add_library(triangle_library triangle.cpp triangle.h)

# Указание пути к заголовочным файлам для этой библиотеки
target_include_directories(triangle_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
