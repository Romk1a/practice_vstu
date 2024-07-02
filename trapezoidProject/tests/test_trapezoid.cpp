#include "gtest/gtest.h"
#include "trapezoid.h"

// Тесты для метода setBasesAndHeight
TEST(TrapezoidTest, SetBasesAndHeightValid) {
    Trapezoid trapezoid;
    EXPECT_TRUE(trapezoid.setBasesAndHeight(5.0, 7.0, 4.0));
    EXPECT_DOUBLE_EQ(trapezoid.getArea(), 24.0);
}

TEST(TrapezoidTest, SetBasesAndHeightInvalid) {
    Trapezoid trapezoid;
    EXPECT_FALSE(trapezoid.setBasesAndHeight(-5.0, 7.0, 4.0));
    EXPECT_FALSE(trapezoid.setBasesAndHeight(5.0, -7.0, 4.0));
    EXPECT_FALSE(trapezoid.setBasesAndHeight(5.0, 7.0, -4.0));
}

// Тесты для метода setDiagonalsAndAngle
TEST(TrapezoidTest, SetDiagonalsAndAngleValid) {
    Trapezoid trapezoid;
    EXPECT_TRUE(trapezoid.setDiagonalsAndAngle(5.0, 5.0, 60.0));
    EXPECT_NEAR(trapezoid.getArea(), 10.8253, 0.0001);
}

TEST(TrapezoidTest, SetDiagonalsAndAngleInvalid) {
    Trapezoid trapezoid;
    EXPECT_FALSE(trapezoid.setDiagonalsAndAngle(-5.0, 5.0, 60.0));
    EXPECT_FALSE(trapezoid.setDiagonalsAndAngle(5.0, -5.0, 60.0));
    EXPECT_FALSE(trapezoid.setDiagonalsAndAngle(5.0, 5.0, -60.0));
    EXPECT_FALSE(trapezoid.setDiagonalsAndAngle(5.0, 5.0, 180.0));
    EXPECT_FALSE(trapezoid.setDiagonalsAndAngle(5.0, 4.0, 60.0));
}

// Тесты для метода setMedianAndHeight
TEST(TrapezoidTest, SetMedianAndHeightValid) {
    Trapezoid trapezoid;
    EXPECT_TRUE(trapezoid.setMedianAndHeight(6.0, 4.0));
    EXPECT_DOUBLE_EQ(trapezoid.getArea(), 24.0);
}

TEST(TrapezoidTest, SetMedianAndHeightInvalid) {
    Trapezoid trapezoid;
    EXPECT_FALSE(trapezoid.setMedianAndHeight(-6.0, 4.0));
    EXPECT_FALSE(trapezoid.setMedianAndHeight(6.0, -4.0));
}

// Тесты для метода isIsosceles
TEST(TrapezoidTest, IsIsoscelesTrue) {
    Trapezoid trapezoid;
    trapezoid.setBasesAndHeight(5.0, 5.0, 4.0);
    EXPECT_TRUE(trapezoid.isIsosceles());
}

TEST(TrapezoidTest, IsIsoscelesFalse) {
    Trapezoid trapezoid;
    trapezoid.setBasesAndHeight(5.0, 7.0, 4.0);
    EXPECT_FALSE(trapezoid.isIsosceles());
}

// Вспомогательные функции
TEST(UtilFunctionsTest, IsValidNumber) {
    EXPECT_TRUE(isValidNumber(5.0));
    EXPECT_FALSE(isValidNumber(std::nan("")));
    EXPECT_FALSE(isValidNumber(std::numeric_limits<double>::infinity()));
}

TEST(UtilFunctionsTest, IsPositive) {
    EXPECT_TRUE(isPositive(5.0));
    EXPECT_FALSE(isPositive(-5.0));
    EXPECT_FALSE(isPositive(0.0));
}

// Главная функция
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
