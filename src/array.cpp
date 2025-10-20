#include "../include/array.h"
#include <iostream>

void Array::addFigure(std::shared_ptr<Figure> figure) {
    figures.push_back(figure);
}

void Array::removeFigure(int index) {
    if (index >= 0 && index < figures.size()) {
        figures.erase(figures.begin() + index);
    }
}

void Array::printAllFigures() const {
    for (size_t i = 0; i < figures.size(); ++i) {
        auto center = figures[i]->calculateGeometricCenter();
        double area = figures[i]->calculateArea();
        std::cout << "Figure " << i << ": Center(" << center.first << ", " 
                  << center.second << "), Area: " << area << std::endl;
    }
}

double Array::calculateTotalArea() const {
    double total = 0;
    for (const auto& figure : figures) {
        total += figure->calculateArea();
    }
    return total;
}