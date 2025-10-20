#include <iostream>
#include <memory>
#include "../include/square.h"
#include "../include/rectangle.h"
#include "../include/trapezoid.h"
#include "../include/array.h"

int main() {
    Array figures;
    int choice;
    
    std::cout << "Geometry Figures Program" << std::endl;
    
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Square\n";
        std::cout << "2. Add Rectangle\n";
        std::cout << "3. Add Trapezoid\n";
        std::cout << "4. Remove Figure\n";
        std::cout << "5. Print All Figures\n";
        std::cout << "6. Calculate Total Area\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1: {
                auto square = std::make_shared<Square>();
                std::cout << "Enter square side: ";
                std::cin >> *square;
                figures.addFigure(square);
                break;
            }
            case 2: {
                auto rectangle = std::make_shared<Rectangle>();
                std::cout << "Enter rectangle width and height: ";
                std::cin >> *rectangle;
                figures.addFigure(rectangle);
                break;
            }
            case 3: {
                auto trapezoid = std::make_shared<Trapezoid>();
                std::cout << "Enter trapezoid topBase, bottomBase and height: ";
                std::cin >> *trapezoid;
                figures.addFigure(trapezoid);
                break;
            }
            case 4: {
                int index;
                std::cout << "Enter index to remove: ";
                std::cin >> index;
                figures.removeFigure(index);
                break;
            }
            case 5:
                figures.printAllFigures();
                break;
            case 6:
                std::cout << "Total area: " << figures.calculateTotalArea() << std::endl;
                break;
            case 0:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 0);
    
    return 0;
}