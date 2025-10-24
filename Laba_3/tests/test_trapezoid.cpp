#include <gtest/gtest.h>
#include "Trapezoid.h"

TEST(TrapezoidTest, ValidTrapezoidCreation) {
    Points p1(0, 0), p2(6, 0), p3(4, 3), p4(2, 3);
    
    EXPECT_NO_THROW({
        Trapezoid trapezoid(p1, p2, p3, p4);
    });
}

TEST(TrapezoidTest, InvalidTrapezoidCreation) {
    Points p1(0, 0), p2(1, 1), p3(2, 2), p4(3, 3);
    
    EXPECT_THROW({
        Trapezoid trapezoid(p1, p2, p3, p4);
    }, std::invalid_argument);
}

TEST(TrapezoidTest, AreaCalculation) {
    Points p1(0, 0), p2(6, 0), p3(4, 3), p4(2, 3);
    Trapezoid trapezoid(p1, p2, p3, p4);
    
    double area = trapezoid.area();
    EXPECT_NEAR(area, 12.0, 1e-9);
}

TEST(TrapezoidTest, GeometricalCenter) {
    Points p1(0, 0), p2(6, 0), p3(4, 3), p4(2, 3);
    Trapezoid trapezoid(p1, p2, p3, p4);
    
    Points center = trapezoid.geometricalCenter();
    EXPECT_NEAR(center.getX(), 3.0, 1e-9);
    EXPECT_NEAR(center.getY(), 1.0, 1e-9);
}

TEST(TrapezoidTest, CopyConstructor) {
    Points p1(0, 0), p2(6, 0), p3(4, 3), p4(2, 3);
    Trapezoid trapezoid1(p1, p2, p3, p4);
    Trapezoid trapezoid2(trapezoid1);
    
    EXPECT_EQ(trapezoid1, trapezoid2);
}

TEST(TrapezoidTest, AssignmentOperator) {
    Points p1(0, 0), p2(6, 0), p3(4, 3), p4(2, 3);
    Trapezoid trapezoid1(p1, p2, p3, p4);
    Trapezoid trapezoid2 = trapezoid1;
    
    EXPECT_EQ(trapezoid1, trapezoid2);
}

TEST(TrapezoidTest, MoveConstructor) {
    Points p1(0, 0), p2(6, 0), p3(4, 3), p4(2, 3);
    Trapezoid trapezoid1(p1, p2, p3, p4);
    Trapezoid trapezoid2(std::move(trapezoid1));
    
    EXPECT_NEAR(trapezoid2.area(), 12.0, 1e-9);
}

TEST(TrapezoidTest, DoubleConversion) {
    Points p1(0, 0), p2(6, 0), p3(4, 3), p4(2, 3);
    Trapezoid trapezoid(p1, p2, p3, p4);
    
    double area = static_cast<double>(trapezoid);
    EXPECT_NEAR(area, 12.0, 1e-9);
}

TEST(TrapezoidTest, EqualityOperator) {
    Points p1(0, 0), p2(6, 0), p3(4, 3), p4(2, 3);
    Trapezoid trapezoid1(p1, p2, p3, p4);
    Trapezoid trapezoid2(p1, p2, p3, p4);
    
    EXPECT_TRUE(trapezoid1 == trapezoid2);
}

TEST(TrapezoidTest, CloneMethod) {
    Points p1(0, 0), p2(6, 0), p3(4, 3), p4(2, 3);
    Trapezoid trapezoid(p1, p2, p3, p4);
    
    Trapezoid* clone = trapezoid.clone();
    EXPECT_EQ(trapezoid, *clone);
    
    delete clone;
}

TEST(TrapezoidTest, IsoscelesTrapezoid) {
    Points p1(1, 0), p2(5, 0), p3(4, 2), p4(2, 2);
    Trapezoid trapezoid(p1, p2, p3, p4);
    
    EXPECT_NEAR(trapezoid.area(), 6.0, 1e-9);
}
