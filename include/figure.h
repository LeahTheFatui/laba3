#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>
#include <utility>

class Figure {
protected:
    std::vector<std::pair<double, double>> vertices;

public:
    virtual ~Figure() = default;
    
    virtual std::pair<double, double> calculateGeometricCenter() const = 0;
    virtual double calculateArea() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& figure);
    friend std::istream& operator>>(std::istream& is, Figure& figure);
    
    virtual bool operator==(const Figure& other) const {
        return vertices == other.vertices;
    }
    
    Figure& operator=(const Figure& other) {
        if (this != &other) {
            vertices = other.vertices;
        }
        return *this;
    }
    
    Figure& operator=(Figure&& other) noexcept {
        if (this != &other) {
            vertices = std::move(other.vertices);
        }
        return *this;
    }
    
    const std::vector<std::pair<double, double>>& getVertices() const { return vertices; }
};

#endif