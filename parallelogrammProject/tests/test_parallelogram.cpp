#include <gtest/gtest.h>
#include "parallelogram.h"

// Тест конструктора с двумя сторонами и углом
TEST(ParallelogramTest, ConstructorTwoSidesAndAngle) {
    double a = 5.0, b = 7.0, alpha = 45.0;
    Parallelogram p(a, b, alpha);
    
    EXPECT_DOUBLE_EQ(p.getSideA(), a);
    EXPECT_DOUBLE_EQ(p.getSideB(), b);
    EXPECT_DOUBLE_EQ(p.getAngleA(), alpha);
    EXPECT_DOUBLE_EQ(p.calculateArea(), a * b * sin(alpha * M_PI / 180.0));
    EXPECT_DOUBLE_EQ(p.calculatePerimeter(), 2 * (a + b));
}

// Тест конструктора с четырьмя сторонами
TEST(ParallelogramTest, ConstructorFourSides) {
    double a = 5.0, b = 7.0, c = 5.0, d = 7.0;
    Parallelogram p(a, b, c, d, 0);
    
    EXPECT_DOUBLE_EQ(p.getSideA(), a);
    EXPECT_DOUBLE_EQ(p.getSideB(), b);
    EXPECT_DOUBLE_EQ(p.getSideC(), c);
    EXPECT_DOUBLE_EQ(p.getSideD(), d);
    EXPECT_NEAR(p.calculateArea(), a * b * sin(acos((a * a + b * b - c * c) / (2 * a * b))), 1e-6);
    EXPECT_DOUBLE_EQ(p.calculatePerimeter(), 2 * (a + b));
}

// Тест конструктора с двумя сторонами и двумя углами
TEST(ParallelogramTest, ConstructorTwoSidesAndTwoAngles) {
    double a = 5.0, b = 7.0, alpha = 45.0, beta = 135.0;
    Parallelogram p(alpha * M_PI / 180.0, beta * M_PI / 180.0, a, b);
    
    EXPECT_DOUBLE_EQ(p.getSideA(), a);
    EXPECT_DOUBLE_EQ(p.getSideB(), b);
    EXPECT_DOUBLE_EQ(p.getAngleA(), alpha);
    EXPECT_DOUBLE_EQ(p.getAngleB(), beta);
    EXPECT_DOUBLE_EQ(p.calculateArea(), a * b * sin(alpha * M_PI / 180.0));
    EXPECT_DOUBLE_EQ(p.calculatePerimeter(), 2 * (a + b));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
