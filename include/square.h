#ifndef SQUARE_H
#define SQUARE_H

#include <sstream>

#include "../include/figure.h"

class Square : public Figure {
public:
    Square();
    Square(double side);
    Square(const Square& other);
    Square(Square&& other) noexcept;
    
    std::pair<double, double> calculateGeometricCenter() const override;
    double calculateArea() const override;
    
    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
    bool operator==(const Square& other) const;
    
    friend std::istream& operator>>(std::istream& is, Square& square);
    
private:
    double side;
};

#endif