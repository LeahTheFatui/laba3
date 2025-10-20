#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include <sstream>

#include "../include/figure.h"

class Trapezoid : public Figure {
public:
    Trapezoid();
    Trapezoid(double topBase, double bottomBase, double height);
    Trapezoid(const Trapezoid& other);
    Trapezoid(Trapezoid&& other) noexcept;
    
    std::pair<double, double> calculateGeometricCenter() const override;
    double calculateArea() const override;
    
    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other) noexcept;
    bool operator==(const Trapezoid& other) const;
    
    friend std::istream& operator>>(std::istream& is, Trapezoid& trapezoid);
    
private:
    double topBase, bottomBase, height;
};

#endif