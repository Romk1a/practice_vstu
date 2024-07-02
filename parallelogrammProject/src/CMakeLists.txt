# Добавление всех cpp файлов из текущего каталога в библиотеку
add_library(parallelogramm_library parallelogramm.cpp parallelogramm.h)

# Указание пути к заголовочным файлам для этой библиотеки
target_include_directories(parallelogramm_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
