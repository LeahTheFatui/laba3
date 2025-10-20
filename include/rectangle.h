#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <sstream>

#include "../include/figure.h"

class Rectangle : public Figure {
public:
    Rectangle();
    Rectangle(double width, double height);
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;
    
    std::pair<double, double> calculateGeometricCenter() const override;
    double calculateArea() const override;
    
    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;
    bool operator==(const Rectangle& other) const;
    
    friend std::istream& operator>>(std::istream& is, Rectangle& rectangle);
    
private:
    double width, height;
};

#endif