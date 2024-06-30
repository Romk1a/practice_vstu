#include <gtest/gtest.h>
#include "triangle.h"

TEST(TriangleTest, ValidTriangleBySides) {
    Triangle t;
    t.setSides(3, 4, 5);
    EXPECT_NEAR(t.getArea(), 6.0, 1e-9);
    EXPECT_NEAR(t.getPerimeter(), 12.0, 1e-9);
}

TEST(TriangleTest, InvalidTriangleBySides) {
    Triangle t;
    t.setSides(1, 2, 3);
    EXPECT_NE(t.getArea(), 6.0);
    EXPECT_NE(t.getPerimeter(), 6.0);
}

TEST(TriangleTest, ValidTriangleByAngles) {
    Triangle t;
    t.setAngles(60, 60, 60);
    EXPECT_TRUE(t.isValidTriangleByAngles(60, 60, 60));
}

TEST(TriangleTest, InvalidTriangleByAngles) {
    Triangle t;
    t.setAngles(60, 60, 50);
    EXPECT_FALSE(t.isValidTriangleByAngles(60, 60, 50));
}

TEST(TriangleTest, ValidTriangleByCoordinates) {
    Triangle t;
    t.setCoordinates(0, 0, 3, 0, 0, 4);
    EXPECT_NEAR(t.getArea(), 6.0, 1e-9);
    EXPECT_NEAR(t.getPerimeter(), 12.0, 1e-9);
}

TEST(TriangleTest, InvalidTriangleByCoordinates) {
    Triangle t;
    t.setCoordinates(0, 0, 1, 1, 2, 2);
    EXPECT_NE(t.getArea(), 6.0);
    EXPECT_NE(t.getPerimeter(), 6.0);
}

TEST(TriangleTest, ValidTriangleBySideAndTwoAngles) {
    Triangle t;
    t.setSideAndTwoAngles(3, 60, 60);
    EXPECT_TRUE(t.isValidTriangleByAngles(60, 60, 60));
}

TEST(TriangleTest, InvalidTriangleBySideAndTwoAngles) {
    Triangle t;
    t.setSideAndTwoAngles(3, 90, 90);
    EXPECT_FALSE(t.isValidTriangleByAngles(90, 90, 0));
}

TEST(TriangleTest, ValidTriangleByTwoSidesAndAngle) {
    Triangle t;
    t.setTwoSidesAndAngle(3, 4, 90);
    EXPECT_NEAR(t.getArea(), 6.0, 1e-9);
}

TEST(TriangleTest, InvalidTriangleByTwoSidesAndAngle) {
    Triangle t;
    t.setTwoSidesAndAngle(1, 2, 180);
    EXPECT_FALSE(t.isValidTriangleByAngles(0, 0, 180));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
