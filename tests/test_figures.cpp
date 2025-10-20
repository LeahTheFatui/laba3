#include <gtest/gtest.h>
#include "../include/square.h"
#include "../include/rectangle.h"
#include "../include/trapezoid.h"
#include "../include/array.h"

#include <sstream>
#include <memory>
#include <cmath>

// Тесты для класса Square
TEST(SquareTest, DefaultConstructor) {
    Square square;
    EXPECT_DOUBLE_EQ(0.0, square.calculateArea());
}

TEST(SquareTest, ParameterizedConstructor) {
    Square square(5.0);
    EXPECT_DOUBLE_EQ(25.0, square.calculateArea());
}

TEST(SquareTest, AreaCalculation) {
    Square square(4.0);
    EXPECT_DOUBLE_EQ(16.0, square.calculateArea());
}

TEST(SquareTest, GeometricCenter) {
    Square square(6.0);
    auto center = square.calculateGeometricCenter();
    EXPECT_DOUBLE_EQ(3.0, center.first);
    EXPECT_DOUBLE_EQ(3.0, center.second);
}

TEST(SquareTest, CopyConstructor) {
    Square square1(3.0);
    Square square2(square1);
    EXPECT_TRUE(square1 == square2);
    EXPECT_DOUBLE_EQ(square1.calculateArea(), square2.calculateArea());
}

TEST(SquareTest, MoveConstructor) {
    Square square1(4.0);
    Square square2(std::move(square1));
    EXPECT_DOUBLE_EQ(16.0, square2.calculateArea());
}

TEST(SquareTest, CopyAssignment) {
    Square square1(5.0);
    Square square2;
    square2 = square1;
    EXPECT_TRUE(square1 == square2);
}

TEST(SquareTest, MoveAssignment) {
    Square square1(3.0);
    Square square2;
    square2 = std::move(square1);
    EXPECT_DOUBLE_EQ(9.0, square2.calculateArea());
}

TEST(SquareTest, EqualityOperator) {
    Square square1(4.0);
    Square square2(4.0);
    Square square3(5.0);
    EXPECT_TRUE(square1 == square2);
    EXPECT_FALSE(square1 == square3);
}

TEST(SquareTest, InputOperator) {
    Square square;
    std::istringstream iss("7.5");
    iss >> square;
    EXPECT_DOUBLE_EQ(56.25, square.calculateArea()); // 7.5 * 7.5 = 56.25
}

// Тесты для класса Rectangle
TEST(RectangleTest, DefaultConstructor) {
    Rectangle rectangle;
    EXPECT_DOUBLE_EQ(0.0, rectangle.calculateArea());
}

TEST(RectangleTest, ParameterizedConstructor) {
    Rectangle rectangle(4.0, 5.0);
    EXPECT_DOUBLE_EQ(20.0, rectangle.calculateArea());
}

TEST(RectangleTest, AreaCalculation) {
    Rectangle rectangle(3.0, 7.0);
    EXPECT_DOUBLE_EQ(21.0, rectangle.calculateArea());
}

TEST(RectangleTest, GeometricCenter) {
    Rectangle rectangle(8.0, 6.0);
    auto center = rectangle.calculateGeometricCenter();
    EXPECT_DOUBLE_EQ(4.0, center.first);
    EXPECT_DOUBLE_EQ(3.0, center.second);
}

TEST(RectangleTest, CopyConstructor) {
    Rectangle rect1(4.0, 5.0);
    Rectangle rect2(rect1);
    EXPECT_TRUE(rect1 == rect2);
}

TEST(RectangleTest, MoveConstructor) {
    Rectangle rect1(3.0, 4.0);
    Rectangle rect2(std::move(rect1));
    EXPECT_DOUBLE_EQ(12.0, rect2.calculateArea());
}

TEST(RectangleTest, EqualityOperator) {
    Rectangle rect1(3.0, 4.0);
    Rectangle rect2(3.0, 4.0);
    Rectangle rect3(4.0, 3.0);
    EXPECT_TRUE(rect1 == rect2);
    EXPECT_FALSE(rect1 == rect3);
}

TEST(RectangleTest, InputOperator) {
    Rectangle rectangle;
    std::istringstream iss("5.0 6.0");
    iss >> rectangle;
    EXPECT_DOUBLE_EQ(30.0, rectangle.calculateArea()); // 5.0 * 6.0 = 30.0
}

// Тесты для класса Trapezoid
TEST(TrapezoidTest, DefaultConstructor) {
    Trapezoid trapezoid;
    EXPECT_DOUBLE_EQ(0.0, trapezoid.calculateArea());
}

TEST(TrapezoidTest, ParameterizedConstructor) {
    Trapezoid trapezoid(3.0, 5.0, 4.0);
    EXPECT_DOUBLE_EQ(16.0, trapezoid.calculateArea()); // (3+5)*4/2 = 16
}

TEST(TrapezoidTest, AreaCalculation) {
    Trapezoid trapezoid(2.0, 6.0, 3.0);
    EXPECT_DOUBLE_EQ(12.0, trapezoid.calculateArea()); // (2+6)*3/2 = 12
}

TEST(TrapezoidTest, GeometricCenter) {
    Trapezoid trapezoid(3.0, 5.0, 4.0);
    auto center = trapezoid.calculateGeometricCenter();
    
    // Проверяем, что центр находится в пределах фигуры
    EXPECT_GT(center.first, 0.0);
    EXPECT_LT(center.first, 5.0);
    EXPECT_GT(center.second, 0.0);
    EXPECT_LT(center.second, 4.0);
    
    // Проверяем симметричность по X
    EXPECT_NEAR(2.5, center.first, 0.1); // Ожидаем центр около середины по X
}

TEST(TrapezoidTest, CopyConstructor) {
    Trapezoid trap1(2.0, 4.0, 3.0);
    Trapezoid trap2(trap1);
    EXPECT_TRUE(trap1 == trap2);
    EXPECT_DOUBLE_EQ(trap1.calculateArea(), trap2.calculateArea());
}

TEST(TrapezoidTest, MoveConstructor) {
    Trapezoid trap1(3.0, 5.0, 4.0);
    Trapezoid trap2(std::move(trap1));
    EXPECT_DOUBLE_EQ(16.0, trap2.calculateArea());
}

TEST(TrapezoidTest, MoveAssignment) {
    Trapezoid trap1(2.0, 4.0, 3.0);
    Trapezoid trap2;
    trap2 = std::move(trap1);
    EXPECT_DOUBLE_EQ(9.0, trap2.calculateArea()); // (2+4)*3/2 = 9
}

TEST(TrapezoidTest, EqualityOperator) {
    Trapezoid trap1(2.0, 4.0, 3.0);
    Trapezoid trap2(2.0, 4.0, 3.0);
    Trapezoid trap3(3.0, 5.0, 4.0);
    EXPECT_TRUE(trap1 == trap2);
    EXPECT_FALSE(trap1 == trap3);
}

TEST(TrapezoidTest, InputOperator) {
    Trapezoid trapezoid;
    std::istringstream iss("2.0 6.0 4.0");
    iss >> trapezoid;
    EXPECT_DOUBLE_EQ(16.0, trapezoid.calculateArea()); // (2+6)*4/2 = 16
}

// Тесты для класса Array
TEST(ArrayTest, DefaultConstructor) {
    Array array;
    EXPECT_EQ(0, array.size());
    EXPECT_DOUBLE_EQ(0.0, array.calculateTotalArea());
}

TEST(ArrayTest, AddFigures) {
    Array array;
    auto square = std::make_shared<Square>(2.0);
    auto rectangle = std::make_shared<Rectangle>(3.0, 4.0);
    
    array.addFigure(square);
    array.addFigure(rectangle);
    
    EXPECT_EQ(2, array.size());
}

TEST(ArrayTest, RemoveFigures) {
    Array array;
    array.addFigure(std::make_shared<Square>(2.0));
    array.addFigure(std::make_shared<Rectangle>(3.0, 4.0));
    array.addFigure(std::make_shared<Trapezoid>(2.0, 4.0, 3.0));
    
    EXPECT_EQ(3, array.size());
    
    array.removeFigure(1);
    EXPECT_EQ(2, array.size());
    
    // Проверяем, что удалился правильный элемент
    EXPECT_DOUBLE_EQ(4.0, array[0]->calculateArea()); // Square area
    EXPECT_DOUBLE_EQ(9.0, array[1]->calculateArea()); // Trapezoid area
}

TEST(ArrayTest, RemoveInvalidIndex) {
    Array array;
    array.addFigure(std::make_shared<Square>(2.0));
    
    // Попытка удалить несуществующий индекс не должна вызывать ошибку
    array.removeFigure(5);
    array.removeFigure(-1);
    
    EXPECT_EQ(1, array.size()); // Размер не должен измениться
}

TEST(ArrayTest, TotalAreaCalculation) {
    Array array;
    array.addFigure(std::make_shared<Square>(2.0));        // area = 4
    array.addFigure(std::make_shared<Rectangle>(3.0, 4.0)); // area = 12
    array.addFigure(std::make_shared<Trapezoid>(2.0, 4.0, 3.0)); // area = 9
    
    EXPECT_DOUBLE_EQ(25.0, array.calculateTotalArea()); // 4 + 12 + 9 = 25
}

TEST(ArrayTest, EmptyArrayTotalArea) {
    Array array;
    EXPECT_DOUBLE_EQ(0.0, array.calculateTotalArea());
}

TEST(ArrayTest, AccessOperator) {
    Array array;
    auto square = std::make_shared<Square>(3.0);
    array.addFigure(square);
    
    EXPECT_DOUBLE_EQ(9.0, array[0]->calculateArea());
    EXPECT_EQ(square.get(), array[0].get()); // Проверяем, что это тот же указатель
}

// Тесты полиморфизма и базового класса Figure
TEST(FigureTest, Polymorphism) {
    std::shared_ptr<Figure> square = std::make_shared<Square>(4.0);
    std::shared_ptr<Figure> rectangle = std::make_shared<Rectangle>(3.0, 5.0);
    std::shared_ptr<Figure> trapezoid = std::make_shared<Trapezoid>(2.0, 6.0, 4.0);
    
    EXPECT_DOUBLE_EQ(16.0, square->calculateArea());
    EXPECT_DOUBLE_EQ(15.0, rectangle->calculateArea());
    EXPECT_DOUBLE_EQ(16.0, trapezoid->calculateArea()); // (2+6)*4/2 = 16
}

TEST(FigureTest, GeometricCenterPolymorphism) {
    std::shared_ptr<Figure> square = std::make_shared<Square>(4.0);
    auto center = square->calculateGeometricCenter();
    EXPECT_DOUBLE_EQ(2.0, center.first);
    EXPECT_DOUBLE_EQ(2.0, center.second);
}

TEST(FigureTest, DoubleConversion) {
    Square square(5.0);
    double area = square.calculateArea();
    EXPECT_DOUBLE_EQ(25.0, area);
    
    Rectangle rectangle(4.0, 6.0);
    area = rectangle.calculateArea();
    EXPECT_DOUBLE_EQ(24.0, area);
}

// Тесты на граничные случаи
TEST(EdgeCaseTest, ZeroDimensions) {
    Square zeroSquare(0.0);
    EXPECT_DOUBLE_EQ(0.0, zeroSquare.calculateArea());
    
    Rectangle zeroRectangle(0.0, 5.0);
    EXPECT_DOUBLE_EQ(0.0, zeroRectangle.calculateArea());
    
    Trapezoid zeroTrapezoid(0.0, 0.0, 5.0);
    EXPECT_DOUBLE_EQ(0.0, zeroTrapezoid.calculateArea());
}

TEST(EdgeCaseTest, VerySmallDimensions) {
    Square smallSquare(0.001);
    EXPECT_DOUBLE_EQ(0.000001, smallSquare.calculateArea());
    
    Rectangle smallRectangle(0.001, 0.002);
    EXPECT_DOUBLE_EQ(0.000002, smallRectangle.calculateArea());
}

// Тесты производительности и корректности
TEST(PerformanceTest, MultipleOperations) {
    Array array;
    
    // Добавляем много фигур
    for (int i = 1; i <= 100; ++i) {
        array.addFigure(std::make_shared<Square>(static_cast<double>(i)));
    }
    
    EXPECT_EQ(100, array.size());
    
    // Удаляем каждую вторую фигуру
    for (int i = 49; i >= 0; --i) {
        array.removeFigure(i * 2);
    }
    
    EXPECT_EQ(50, array.size());
    
    // Проверяем, что площадь вычисляется корректно
    double totalArea = array.calculateTotalArea();
    EXPECT_GT(totalArea, 0.0);
}
