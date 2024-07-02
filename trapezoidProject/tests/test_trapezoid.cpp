#include <gtest/gtest.h>
#include "trapezoid.h"
#include <cmath>
// Тест конструктора
TEST(TrapezoidTest, DefaultConstructor) {
    Trapezoid t;
    EXPECT_EQ(t.getBase1(), 0);
    EXPECT_EQ(t.getBase2(), 0);
    EXPECT_EQ(t.getHeight(), 0);
    EXPECT_EQ(t.getArea(), 0);
    EXPECT_EQ(t.getPerimeter(), 0);
}

// Тест метода setBasesAndHeight
TEST(TrapezoidTest, SetBasesAndHeight) {
    Trapezoid t;
    EXPECT_TRUE(t.setBasesAndHeight(3.0, 4.0, 5.0));
    EXPECT_EQ(t.getBase1(), 3.0);
    EXPECT_EQ(t.getBase2(), 4.0);
    EXPECT_EQ(t.getHeight(), 5.0);
    EXPECT_NEAR(t.getArea(), 17.5, 1e-5);
    EXPECT_NEAR(t.getPerimeter(), 18.4031, 1e-4);

    EXPECT_FALSE(t.setBasesAndHeight(-3.0, 4.0, 5.0));
    EXPECT_FALSE(t.setBasesAndHeight(3.0, -4.0, 5.0));
    EXPECT_FALSE(t.setBasesAndHeight(3.0, 4.0, -5.0));
}

// Тест метода setDiagonalsAndAngle
TEST(TrapezoidTest, SetDiagonalsAndAngle) {
    Trapezoid t;
    EXPECT_TRUE(t.setDiagonalsAndAngle(5.0, 5.0, 60.0));
    EXPECT_EQ(t.getDiagonal1(), 5.0);
    EXPECT_EQ(t.getDiagonal2(), 5.0);
    EXPECT_EQ(t.getAngle(), 60.0);
    EXPECT_NEAR(t.getArea(), 10.8253, 1e-4);

    EXPECT_FALSE(t.setDiagonalsAndAngle(-5.0, 5.0, 60.0));
    EXPECT_FALSE(t.setDiagonalsAndAngle(5.0, -5.0, 60.0));
    EXPECT_FALSE(t.setDiagonalsAndAngle(5.0, 5.0, -60.0));
    EXPECT_FALSE(t.setDiagonalsAndAngle(5.0, 5.0, 180.0));
    EXPECT_FALSE(t.setDiagonalsAndAngle(5.0, 6.0, 60.0)); // Диагонали не равны
}

// Тест метода setMedianAndHeight
TEST(TrapezoidTest, SetMedianAndHeight) {
    Trapezoid t;
    EXPECT_TRUE(t.setMedianAndHeight(3.5, 4.0));
    EXPECT_EQ(t.getMedian(), 3.5);
    EXPECT_EQ(t.getHeight(), 4.0);
    EXPECT_NEAR(t.getArea(), 14.0, 1e-4);

    EXPECT_FALSE(t.setMedianAndHeight(-3.5, 4.0));
    EXPECT_FALSE(t.setMedianAndHeight(3.5, -4.0));
}

// Тест метода resetProperties
TEST(TrapezoidTest, ResetProperties) {
    Trapezoid t;
    t.setBasesAndHeight(3.0, 4.0, 5.0);
    t.resetProperties();
    EXPECT_EQ(t.getBase1(), 0);
    EXPECT_EQ(t.getBase2(), 0);
    EXPECT_EQ(t.getHeight(), 0);
    EXPECT_EQ(t.getArea(), 0);
    EXPECT_EQ(t.getPerimeter(), 0);
}

// Тест метода isIsosceles
TEST(TrapezoidTest, IsIsosceles) {
    Trapezoid t;
    t.setBasesAndHeight(3.0, 3.0, 5.0);
    EXPECT_TRUE(t.isIsosceles());

    t.setBasesAndHeight(3.0, 4.0, 5.0);
    EXPECT_FALSE(t.isIsosceles());
}
