#include "../include/figure.h"

//TODO Разделить фигуры по разным файлам 

// вычисляет площадь многоугольника по формуле площади по вершинам
static double Area(const double x[], const double y[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        sum += x[i] * y[j] - y[i] * x[j];
    }
    return std::abs(sum) / 2.0;
}

// квадраты

// конструктор по умолчанию для класса Square
Square::Square() {
    for (int i = 0; i < 4; i++) {
        x[i][0] = 0;
        x[i][1] = 0;
    }
}

// конструктор, который создает квадрат, используя заданные координаты вершин
Square::Square(const double coords[4][2]) {
    for (int i = 0; i < 4; i++) {
        x[i][0] = coords[i][0];
        x[i][1] = coords[i][1];
    }
}

// конструктор копирования
Square::Square(const Square& other) {
    for (int i = 0; i < 4; i++) {
        x[i][0] = other.x[i][0];
        x[i][1] = other.x[i][1];
    }
}

// оператор присваивания
Square& Square::operator=(const Square& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            x[i][0] = other.x[i][0];
            x[i][1] = other.x[i][1];
        }
    }
    return *this;
}

// центр квадрата
void Square::center(double& center_x, double& center_y) const {
    center_x = 0; center_y = 0;
    for (int i = 0; i < 4; i++) {
        center_x += x[i][0]; center_y += x[i][1];
    }
    center_x /= 4; center_y /= 4;
}

// площадь квадрата
double Square::area() const {
    double xs[4], ys[4];
    for (int i = 0; i < 4; i++) {
        xs[i] = x[i][0]; ys[i] = x[i][1];
    }
    return Area(xs, ys, 4);
}

// проверяет, равен ли текущий квадрат другому объекту Figure
bool Square::operator==(const Figure& other) const {
    const Square* s = dynamic_cast<const Square*>(&other);
    if (!s) return false;
    for (int i = 0; i < 4; i++) {
        if (x[i][0] != s->x[i][0] || x[i][1] != s->x[i][1])
            return false;
    }
    return true;
}

// реализация != внутри класса уже 

// выводит координаты вершин квадрата
void Square::print(std::ostream& os) const {
    os << "Square verticies:\n";
    for (int i = 0; i < 4; i++) {
        os << "(" << x[i][0] << ", " << x[i][1] << ")\n";
    }
}

// ввод из потока или с клавиатуры
std::istream& operator>>(std::istream& is, Square& s) {
    std::cout << "Enter 4 vertices (x y):\n";
    for (int i = 0; i < 4; i++) {
        is >> s.x[i][0] >> s.x[i][1];
    }
    return is;
}

// прямоугольник 

Rectangle::Rectangle() {
    for (int i = 0; i < 4; i++) {
        x[i][0] = 0;
        x[i][1] = 0;
    }
}

Rectangle::Rectangle(const double coords[4][2]) {
    for (int i = 0; i < 4; i++) {
        x[i][0] = coords[i][0];
        x[i][1] = coords[i][1];
    }
}

Rectangle::Rectangle(const Rectangle& other) {
    for (int i = 0; i < 4; i++) {
        x[i][0] = other.x[i][0];
        x[i][1] = other.x[i][1];
    }
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            x[i][0] = other.x[i][0];
            x[i][1] = other.x[i][1];
        }
    }
    return *this;
}

void Rectangle::center(double& center_x, double& center_y) const {
    center_x = 0; center_y = 0;
    for (int i = 0; i < 4; i++) {
        center_x += x[i][0]; center_y += x[i][1];
    }
    center_x /= 4; center_y /= 4;
}

double Rectangle::area() const {
    double xs[4], ys[4];
    for (int i = 0; i < 4; i++) {
        xs[i] = x[i][0]; ys[i] = x[i][1];
    }
    return Area(xs, ys, 4);
}

bool Rectangle::operator==(const Figure& other) const {
    const Rectangle* s = dynamic_cast<const Rectangle*>(&other);
    if (!s) return false;
    for (int i = 0; i < 4; i++) {
        if (x[i][0] != s->x[i][0] || x[i][1] != s->x[i][1])
            return false;
    }
    return true;
}

void Rectangle::print(std::ostream& os) const {
    os << "Rectangle verticies:\n";
    for (int i = 0; i < 4; i++) {
        os << "(" << x[i][0] << ", " << x[i][1] << ")\n";
    }
}

std::istream& operator>>(std::istream& is, Rectangle& s) {
    std::cout << "Enter 4 vertices (x y):\n";
    for (int i = 0; i < 4; i++) {
        is >> s.x[i][0] >> s.x[i][1];
    }
    return is;
}

// трапеция

Trapezoid::Trapezoid() {
    for (int i = 0; i < 4; i++) {
        x[i][0] = 0;
        x[i][1] = 0;
    }
}

Trapezoid::Trapezoid(const double coords[4][2]) {
    for (int i = 0; i < 4; i++) {
        x[i][0] = coords[i][0];
        x[i][1] = coords[i][1];
    }
}

Trapezoid::Trapezoid(const Trapezoid& other) {
    for (int i = 0; i < 4; i++) {
        x[i][0] = other.x[i][0];
        x[i][1] = other.x[i][1];
    }
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            x[i][0] = other.x[i][0];
            x[i][1] = other.x[i][1];
        }
    }
    return *this;
}

void Trapezoid::center(double& center_x, double& center_y) const {
    center_x = 0; center_y = 0;
    for (int i = 0; i < 4; i++) {
        center_x += x[i][0]; center_y += x[i][1];
    }
    center_x /= 4; center_y /= 4;
}

double Trapezoid::area() const {
    double xs[4], ys[4];
    for (int i = 0; i < 4; i++) {
        xs[i] = x[i][0]; ys[i] = x[i][1];
    }
    return Area(xs, ys, 4);
}

bool Trapezoid::operator==(const Figure& other) const {
    const Trapezoid* s = dynamic_cast<const Trapezoid*>(&other);
    if (!s) return false;
    for (int i = 0; i < 4; i++) {
        if (x[i][0] != s->x[i][0] || x[i][1] != s->x[i][1])
            return false;
    }
    return true;
}

void Trapezoid::print(std::ostream& os) const {
    os << "Trapezoid verticies:\n";
    for (int i = 0; i < 4; i++) {
        os << "(" << x[i][0] << ", " << x[i][1] << ")\n";
    }
}

std::istream& operator>>(std::istream& is, Trapezoid& s) {
    std::cout << "Enter 4 vertices (x y):\n";
    for (int i = 0; i < 4; i++) {
        is >> s.x[i][0] >> s.x[i][1];
    }
    return is;
}
