# Добавление всех cpp файлов из текущего каталога в библиотеку
add_library(parallelogram_library parallelogram.cpp parallelogram.h)

# Указание пути к заголовочным файлам для этой библиотеки
target_include_directories(parallelogram_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
