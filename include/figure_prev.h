#pragma once

#include <iostream>
#include <cmath>

class Figure { //задает абстрактный тип класса для остальных фигур
public:
    virtual ~Figure() {}

    virtual void center(double& x, double& y) const = 0; //центра фигуры по 2м координатам
    virtual double area() const = 0; //площадь

    virtual bool operator==(const Figure& other) const = 0; //сравнение
    virtual bool operator!=(const Figure& other) const { return !(*this == other); } //сравнение через operator==

    virtual void print(std::ostream& os) const = 0; //вывод фигуры

    // Выводы/вводы через стандарт потоки
    friend std::ostream& operator<<(std::ostream& os, const Figure& fig); 
    friend std::istream& operator>>(std::istream& is, Figure& fig);

    //копия текущего объекта
    virtual Figure* clone() const = 0;
};

//Вызывает метод print() для вывода информации о фигуре, и возвращает поток для последовательных операций
inline std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    fig.print(os);
    return os;
}

inline std::istream& operator>>(std::istream is, Figure& fig) { return is; } //для базового класса нереализуем, он переопределен для каждого

class Square : public Figure {
private:
    double x[4][2]; // координаты
public:
    Square(); // дефолтный конструктор
    Square(const double coords[4][2]); // конструктор, создающий квадрат по массиву координат вершин
    Square(const Square& other); // конструктор копирования
    Square& operator=(const Square& other); // оператор присваивания
    ~Square() override = default; // объявляет деструктор класса

    void center(double& cx, double& cy) const override;
    double area() const override;

    bool operator==(const Figure& other) const override;
    bool operator!=(const Figure& other) const override { return !(*this == other); }

    void print(std::ostream& os) const override;

    friend std::istream& operator>>(std::istream& is, Square& s);

    Figure* clone() const override { return new Square(*this); }
};

class Rectangle : public Figure {
private:
    double x[4][2];
public:
    Rectangle();
    Rectangle(const double coords[4][2]);
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    ~Rectangle() override {}

    void center(double& center_x, double& center_y) const override;
    double area() const override;

    bool operator==(const Figure& other) const override;
    bool operator!=(const Figure& other) const override { return !(*this == other); }

    void print(std::ostream& os) const override;

    friend std::istream& operator>>(std::istream& is, Rectangle& rectange);

    Figure* clone() const override { return new Rectangle(*this); }
};

class Trapezoid : public Figure {
private:
    double x[4][2];
public:
    Trapezoid();
    Trapezoid(const double coords[4][2]);
    Trapezoid(const Trapezoid& other);
    Trapezoid& operator=(const Trapezoid& other);
    ~Trapezoid() override {}

    void center(double& cx, double& cy) const override;
    double area() const override;

    bool operator==(const Figure& other) const override;
    bool operator!=(const Figure& other) const override { return !(*this == other); }

    void print(std::ostream& os) const override;

    friend std::istream& operator>>(std::istream& is, Trapezoid& rectange);

    Figure* clone() const override { return new Trapezoid(*this); }
};
