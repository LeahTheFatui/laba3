#include "../include/rectangle.h"
#include <iostream>

Rectangle::Rectangle() : width(0), height(0) {
    vertices.resize(4);
    vertices[0] = {0, 0};
    vertices[1] = {0, 0};
    vertices[2] = {0, 0};
    vertices[3] = {0, 0};
}

Rectangle::Rectangle(double width, double height) : width(width), height(height) {
    vertices.resize(4);
    vertices[0] = {0, 0};
    vertices[1] = {width, 0};
    vertices[2] = {width, height};
    vertices[3] = {0, height};
}

Rectangle::Rectangle(const Rectangle& other) : width(other.width), height(other.height) {
    vertices = other.vertices;
}

Rectangle::Rectangle(Rectangle&& other) noexcept : width(other.width), height(other.height) {
    vertices = std::move(other.vertices);
    other.width = 0;
    other.height = 0;
}

std::pair<double, double> Rectangle::calculateGeometricCenter() const {
    return {width / 2, height / 2};
}

double Rectangle::calculateArea() const {
    return width * height;
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        width = other.width;
        height = other.height;
        vertices = other.vertices;
    }
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        width = other.width;
        height = other.height;
        vertices = std::move(other.vertices);
        other.width = 0;
        other.height = 0;
    }
    return *this;
}

bool Rectangle::operator==(const Rectangle& other) const {
    return width == other.width && height == other.height && vertices == other.vertices;
}

std::istream& operator>>(std::istream& is, Rectangle& rectangle) {
    is >> rectangle.width >> rectangle.height;
    rectangle.vertices[0] = {0, 0};
    rectangle.vertices[1] = {rectangle.width, 0};
    rectangle.vertices[2] = {rectangle.width, rectangle.height};
    rectangle.vertices[3] = {0, rectangle.height};
    return is;
}