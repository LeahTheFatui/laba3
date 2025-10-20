#include "../include/square.h"
#include <iostream>

Square::Square() : side(0) {
    vertices.resize(4);
    vertices[0] = {0, 0};
    vertices[1] = {0, 0};
    vertices[2] = {0, 0};
    vertices[3] = {0, 0};
}

Square::Square(double side) : side(side) {
    vertices.resize(4);
    vertices[0] = {0, 0};
    vertices[1] = {side, 0};
    vertices[2] = {side, side};
    vertices[3] = {0, side};
}

Square::Square(const Square& other) : side(other.side) {
    vertices = other.vertices;
}

Square::Square(Square&& other) noexcept : side(other.side) {
    vertices = std::move(other.vertices);
    other.side = 0;
}

std::pair<double, double> Square::calculateGeometricCenter() const {
    return {side / 2, side / 2};
}

double Square::calculateArea() const {
    return side * side;
}

Square& Square::operator=(const Square& other) {
    if (this != &other) {
        side = other.side;
        vertices = other.vertices;
    }
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
    if (this != &other) {
        side = other.side;
        vertices = std::move(other.vertices);
        other.side = 0;
    }
    return *this;
}

bool Square::operator==(const Square& other) const {
    return side == other.side && vertices == other.vertices;
}

std::istream& operator>>(std::istream& is, Square& square) {
    is >> square.side;
    square.vertices[0] = {0, 0};
    square.vertices[1] = {square.side, 0};
    square.vertices[2] = {square.side, square.side};
    square.vertices[3] = {0, square.side};
    return is;
}