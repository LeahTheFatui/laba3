#include "include/figure.h"
#include <iostream>

const int MAX_FIGURES = 100;

int main() {
    Figure* figures[MAX_FIGURES];
    int count = 0;

    while (true) {
        std::cout << "\nMenu: \n";
        std::cout << "1. Add Square\n";
        std::cout << "2. Add Rectangle\n";
        std::cout << "3. Add Trapezoid\n";
        std::cout << "4. Show existing figures & their center\n";
        std::cout << "5. Total area\n";
        std::cout << "6. Remove figure\n";
        std::cout << "0. Exit\n";

        int choice;
        std::cin >> choice;

        if (choice == 0) break;

        if (count >= MAX_FIGURES) {
            std::cout << "Maximum capacity reached\n";
            continue;
        }

        if (choice == 1) {
            Square* s = new Square();
            std::cin >> *s;
            figures[count++] = s;
        } else if (choice == 2) {
            Rectangle* r = new Rectangle();
            std::cin >> *r;
            figures[count++] = r;
        } else if (choice == 3) {
            Trapezoid* t = new Trapezoid();
            std::cin >> *t;
            figures[count++] = t;
        } else if (choice == 4) {
            for (int i = 0; i < count; i++) {
                std::cout << "Figure " << i << ":\n";
                std::cout << *figures[i] << "\n";
                double cx, cy;
                figures[i]->center(cx, cy);
                std::cout << "Center: (" << cx << "," << cy <<")\n";
            }
        } else if (choice == 5) {
            double total_area = 0;
            for (int i = 0; i < count; i++) {
                total_area += figures[i]->area();
            }
            std::cout << "Total area of all figures: " << total_area << "\n";
        } else if (choice == 6) {
            std::cout << "Enter index to remove (0 -" << (count - 1) << "): ";
            int index;
            std::cin >> index;
            if (index >= 0 && index < count) {
                delete figures[index];
                for (int i = index; i < count - 1; i++) {
                    figures[i] = figures[i + 1];
                }
                count--;
                std::cout << "Done\n";
            } else {
                std::cout << "Invalid index\n";
            }
        } else {
            std::cout << "Invalid choice\n";
        }
    }
    for (int i = 0; i < count; i++) {
        delete figures[i];
    }
    return 0;
}