# Укажите файлы тестов
set(TEST_SOURCES test_circle.cpp)

# Создайте исполняемый файл для тестов
add_executable(RunTests ${TEST_SOURCES})

# Подключите библиотеку Google Test
target_link_libraries(RunTests gtest gtest_main)

# Подключите вашу библиотеку
target_link_libraries(RunTests CircleLibrary)

# Укажите пути к заголовочным файлам
target_include_directories(RunTests PUBLIC ../src)

# Добавьте команду для запуска тестов
add_test(NAME RunTests COMMAND RunTests)