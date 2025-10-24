#include <gtest/gtest.h>
#include "FigureArray.h"
#include "Rhombus.h"
#include "Rectangle.h"
#include "Trapezoid.h"

class FigureArrayTest : public ::testing::Test {
protected:
    void SetUp() override {
        Points r1(0, 0), r2(3, 4), r3(6, 0);
        rhombus = new Rhombus(r1, r2, r3);
        
        Points rect1(1, 1), rect2(5, 1), rect3(5, 4), rect4(1, 4);
        rectangle = new Rectangle(rect1, rect2, rect3, rect4);
        
        Points trap1(0, 0), trap2(6, 0), trap3(4, 3), trap4(2, 3);
        trapezoid = new Trapezoid(trap1, trap2, trap3, trap4);
    }
    
    void TearDown() override {
        delete rhombus;
        delete rectangle;
        delete trapezoid;
    }
    
    Rhombus* rhombus;
    Rectangle* rectangle;
    Trapezoid* trapezoid;
};

TEST_F(FigureArrayTest, DefaultConstructor) {
    FigureArray array;
    EXPECT_EQ(array.getSize(), 0);
}

TEST_F(FigureArrayTest, PushBack) {
    FigureArray array;
    array.pushBack(rhombus->clone());
    
    EXPECT_EQ(array.getSize(), 1);
    EXPECT_NE(array[0], nullptr);
}

TEST_F(FigureArrayTest, PushFront) {
    FigureArray array;
    array.pushBack(rectangle->clone());
    array.pushFront(rhombus->clone());
    
    EXPECT_EQ(array.getSize(), 2);
    EXPECT_TRUE(dynamic_cast<Rhombus*>(array[0]) != nullptr);
}

TEST_F(FigureArrayTest, PopBack) {
    FigureArray array;
    array.pushBack(rhombus->clone());
    array.pushBack(rectangle->clone());
    
    EXPECT_EQ(array.getSize(), 2);
    array.popBack();
    EXPECT_EQ(array.getSize(), 1);
}

TEST_F(FigureArrayTest, PopFront) {
    FigureArray array;
    array.pushBack(rhombus->clone());
    array.pushBack(trapezoid->clone());
    
    EXPECT_EQ(array.getSize(), 2);
    array.popFront();
    EXPECT_EQ(array.getSize(), 1);
}

TEST_F(FigureArrayTest, PopByIndex) {
    FigureArray array;
    array.pushBack(rhombus->clone());
    array.pushBack(rectangle->clone());
    array.pushBack(trapezoid->clone());
    
    EXPECT_EQ(array.getSize(), 3);
    array.popByIndex(1);
    EXPECT_EQ(array.getSize(), 2);
}

TEST_F(FigureArrayTest, TotalAreaCalculation) {
    FigureArray array;
    array.pushBack(rhombus->clone());
    array.pushBack(rectangle->clone());
    array.pushBack(trapezoid->clone());
    
    double totalArea = array.getTotalArea();
    EXPECT_GT(totalArea, 0.0);
    
    double expectedTotal = rhombus->area() + rectangle->area() + trapezoid->area();
    EXPECT_NEAR(totalArea, expectedTotal, 1e-9);
}

TEST_F(FigureArrayTest, CopyConstructor) {
    FigureArray array1;
    array1.pushBack(rhombus->clone());
    array1.pushBack(rectangle->clone());
    
    FigureArray array2(array1);
    EXPECT_EQ(array1.getSize(), array2.getSize());
    
    EXPECT_NE(array1[0], array2[0]);
}

TEST_F(FigureArrayTest, EmptyArrayOperations) {
    FigureArray array;
    
    EXPECT_NO_THROW(array.popBack());
    EXPECT_NO_THROW(array.popFront());
    EXPECT_NO_THROW(array.popByIndex(0));
    
    EXPECT_EQ(array.getTotalArea(), 0.0);
}

TEST_F(FigureArrayTest, AccessOperator) {
    FigureArray array;
    array.pushBack(trapezoid->clone());
    
    EXPECT_NO_THROW({
        Figure* figure = array[0];
        EXPECT_NE(figure, nullptr);
    });
}

TEST_F(FigureArrayTest, PolymorphicBehavior) {
    FigureArray array;
    array.pushBack(rhombus->clone());
    array.pushBack(rectangle->clone());
    array.pushBack(trapezoid->clone());
    
    for (size_t i = 0; i < array.getSize(); ++i) {
        Figure* figure = array[i];
        EXPECT_NE(figure, nullptr);
        
        EXPECT_GT(figure->area(), 0.0);
        
        Points center = figure->geometricalCenter();
        EXPECT_TRUE(center.getX() == center.getX());
        EXPECT_TRUE(center.getY() == center.getY());
    }
}

TEST_F(FigureArrayTest, MoveConstructor) {
    FigureArray array1;
    array1.pushBack(rhombus->clone());
    array1.pushBack(rectangle->clone());
    
    FigureArray array2(std::move(array1));
    EXPECT_EQ(array2.getSize(), 2);
    EXPECT_EQ(array1.getSize(), 0);
}

TEST_F(FigureArrayTest, PrintMethods) {
    FigureArray array;
    array.pushBack(rhombus->clone());
    array.pushBack(rectangle->clone());
    
    EXPECT_NO_THROW(array.printAllCenters());
    EXPECT_NO_THROW(array.printAllAreas());
    EXPECT_NO_THROW(array.printAllInfo());
}
