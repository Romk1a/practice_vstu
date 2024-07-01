#include <gtest/gtest.h>
#include "circle_h.h"

TEST(CircleTest, RadiusConstructor) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getDiameter(), 10.0);
    EXPECT_DOUBLE_EQ(c.getCircumference(), 2 * 3.141592653589793 * 5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 3.141592653589793 * 5.0 * 5.0);
}

TEST(CircleTest, DiameterConstructor) {
    Circle c(10.0, true);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
}

TEST(CircleTest, CircumferenceConstructor) {
    Circle c(31.41592653589793, true, true);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
}

TEST(CircleTest, SetRadius) {
    Circle c(5.0);
    c.setRadius(10.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
}

TEST(CircleTest, Intersects) {
    Circle c1(5.0);
    Circle c2(5.0);
    EXPECT_TRUE(c1.intersects(c2));
}

TEST(CircleTest, Contains) {
    Circle c(5.0);
    EXPECT_TRUE(c.contains(3.0, 4.0));
    EXPECT_FALSE(c.contains(6.0, 0.0));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}