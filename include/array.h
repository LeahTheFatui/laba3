#ifndef ARRAY_H
#define ARRAY_H

#include "../include/figure.h"
#include <vector>
#include <memory>
#include <sstream>

class Array {
private:
    std::vector<std::shared_ptr<Figure>> figures;

public:
    void addFigure(std::shared_ptr<Figure> figure);
    void removeFigure(int index);
    void printAllFigures() const;
    double calculateTotalArea() const;
    size_t size() const { return figures.size(); }
    std::shared_ptr<Figure> operator[](int index) const { return figures[index]; }
};

#endif