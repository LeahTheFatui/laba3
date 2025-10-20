#include "../include/figure.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Figure& figure) {
    os << "Vertices: ";
    for (const auto& vertex : figure.vertices) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Figure& figure) {
    return is;
}