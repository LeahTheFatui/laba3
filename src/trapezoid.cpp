#include "../include/trapezoid.h"
#include <iostream>

Trapezoid::Trapezoid() : topBase(0), bottomBase(0), height(0) {
    vertices.resize(4);
    vertices[0] = {0, 0};
    vertices[1] = {0, 0};
    vertices[2] = {0, 0};
    vertices[3] = {0, 0};
}

Trapezoid::Trapezoid(double topBase, double bottomBase, double height) 
    : topBase(topBase), bottomBase(bottomBase), height(height) {
    vertices.resize(4);
    double offset = (bottomBase - topBase) / 2;
    vertices[0] = {offset, 0};
    vertices[1] = {offset + topBase, 0};
    vertices[2] = {bottomBase, height};
    vertices[3] = {0, height};
}

Trapezoid::Trapezoid(const Trapezoid& other) 
    : topBase(other.topBase), bottomBase(other.bottomBase), height(other.height) {
    vertices = other.vertices;
}

Trapezoid::Trapezoid(Trapezoid&& other) noexcept 
    : topBase(other.topBase), bottomBase(other.bottomBase), height(other.height) {
    vertices = std::move(other.vertices);
    other.topBase = 0;
    other.bottomBase = 0;
    other.height = 0;
}

std::pair<double, double> Trapezoid::calculateGeometricCenter() const {
    double centerX = bottomBase / 2;
    double centerY = height * (bottomBase + 2 * topBase) / (3 * (bottomBase + topBase));
    return {centerX, centerY};
}

double Trapezoid::calculateArea() const {
    return (topBase + bottomBase) * height / 2;
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this != &other) {
        topBase = other.topBase;
        bottomBase = other.bottomBase;
        height = other.height;
        vertices = other.vertices;
    }
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    if (this != &other) {
        topBase = other.topBase;
        bottomBase = other.bottomBase;
        height = other.height;
        vertices = std::move(other.vertices);
        other.topBase = 0;
        other.bottomBase = 0;
        other.height = 0;
    }
    return *this;
}

bool Trapezoid::operator==(const Trapezoid& other) const {
    return topBase == other.topBase && bottomBase == other.bottomBase && 
           height == other.height && vertices == other.vertices;
}

std::istream& operator>>(std::istream& is, Trapezoid& trapezoid) {
    is >> trapezoid.topBase >> trapezoid.bottomBase >> trapezoid.height;
    double offset = (trapezoid.bottomBase - trapezoid.topBase) / 2;
    trapezoid.vertices[0] = {offset, 0};
    trapezoid.vertices[1] = {offset + trapezoid.topBase, 0};
    trapezoid.vertices[2] = {trapezoid.bottomBase, trapezoid.height};
    trapezoid.vertices[3] = {0, trapezoid.height};
    return is;
}