// test_rectangle.cpp
#include "rectangle.h"
#include <gtest/gtest.h>


// Тест вычислений площади, периметра и диагонали
TEST(RectangleTest, Calculations) {
    Rectangle rect(3.0, 4.0);
    EXPECT_DOUBLE_EQ(rect.area(), 12.0);
    EXPECT_DOUBLE_EQ(rect.perimeter(), 14.0);
    EXPECT_DOUBLE_EQ(rect.diagonal(), 5.0);
}

// Тесты для конструктора по умолчанию
TEST(RectangleTest, DefaultConstructor) {
    Rectangle rect;
    EXPECT_DOUBLE_EQ(rect.getWidth(), 0);
    EXPECT_DOUBLE_EQ(rect.getHeight(), 0);
    EXPECT_FALSE(rect.checkValidity());
}
// Тест конструктора по умолчанию и геттеров
TEST(RectangleTest, DefaultConstructorAndGetters) {
    Rectangle rect;
    EXPECT_DOUBLE_EQ(rect.getWidth(), 0.0);
    EXPECT_DOUBLE_EQ(rect.getHeight(), 0.0);
    ASSERT_FALSE(rect.checkValidity());
}

// Тест вычисления площади
TEST(RectangleTest, AreaCalculation) {
    Rectangle rect(2.0, 2.0);
    EXPECT_DOUBLE_EQ(rect.area(), 4.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



