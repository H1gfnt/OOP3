#include <gtest/gtest.h>
#include "Rectangle.h"

TEST(RectangleTest, ValidRectangleCreation) {
    Points p1(0, 0), p2(4, 0), p3(4, 3), p4(0, 3);
    
    EXPECT_NO_THROW({
        Rectangle rectangle(p1, p2, p3, p4);
    });
}

TEST(RectangleTest, InvalidRectangleCreation) {
    Points p1(0, 0), p2(1, 1), p3(2, 2), p4(3, 3);
    
    EXPECT_THROW({
        Rectangle rectangle(p1, p2, p3, p4);
    }, std::invalid_argument);
}

TEST(RectangleTest, AreaCalculation) {
    Points p1(0, 0), p2(5, 0), p3(5, 4), p4(0, 4);
    Rectangle rectangle(p1, p2, p3, p4);
    
    double area = rectangle.area();
    EXPECT_NEAR(area, 20.0, 1e-9);
}

TEST(RectangleTest, GeometricalCenter) {
    Points p1(1, 1), p2(5, 1), p3(5, 4), p4(1, 4);
    Rectangle rectangle(p1, p2, p3, p4);
    
    Points center = rectangle.geometricalCenter();
    EXPECT_NEAR(center.getX(), 3.0, 1e-9);
    EXPECT_NEAR(center.getY(), 2.5, 1e-9);
}

TEST(RectangleTest, CopyConstructor) {
    Points p1(0, 0), p2(4, 0), p3(4, 3), p4(0, 3);
    Rectangle rectangle1(p1, p2, p3, p4);
    Rectangle rectangle2(rectangle1);
    
    EXPECT_EQ(rectangle1, rectangle2);
}

TEST(RectangleTest, AssignmentOperator) {
    Points p1(0, 0), p2(4, 0), p3(4, 3), p4(0, 3);
    Rectangle rectangle1(p1, p2, p3, p4);
    Rectangle rectangle2 = rectangle1;
    
    EXPECT_EQ(rectangle1, rectangle2);
}

TEST(RectangleTest, MoveConstructor) {
    Points p1(0, 0), p2(4, 0), p3(4, 3), p4(0, 3);
    Rectangle rectangle1(p1, p2, p3, p4);
    Rectangle rectangle2(std::move(rectangle1));
    
    EXPECT_NEAR(rectangle2.area(), 12.0, 1e-9);
}

TEST(RectangleTest, DoubleConversion) {
    Points p1(0, 0), p2(3, 0), p3(3, 2), p4(0, 2);
    Rectangle rectangle(p1, p2, p3, p4);
    
    double area = static_cast<double>(rectangle);
    EXPECT_NEAR(area, 6.0, 1e-9);
}

TEST(RectangleTest, EqualityOperator) {
    Points p1(0, 0), p2(4, 0), p3(4, 3), p4(0, 3);
    Rectangle rectangle1(p1, p2, p3, p4);
    Rectangle rectangle2(p1, p2, p3, p4);
    
    EXPECT_TRUE(rectangle1 == rectangle2);
}

TEST(RectangleTest, CloneMethod) {
    Points p1(0, 0), p2(4, 0), p3(4, 3), p4(0, 3);
    Rectangle rectangle(p1, p2, p3, p4);
    
    Rectangle* clone = rectangle.clone();
    EXPECT_EQ(rectangle, *clone);
    
    delete clone;
}

TEST(RectangleTest, SquareCase) {
    Points p1(0, 0), p2(3, 0), p3(3, 3), p4(0, 3);
    Rectangle square(p1, p2, p3, p4);
    
    EXPECT_NEAR(square.area(), 9.0, 1e-9);
    Points center = square.geometricalCenter();
    EXPECT_NEAR(center.getX(), 1.5, 1e-9);
    EXPECT_NEAR(center.getY(), 1.5, 1e-9);
}
