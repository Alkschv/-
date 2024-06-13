#include <iostream>

class Point {
private:
    double x;
    double y;

public:
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    friend std::istream& operator>>(std::istream& is, Point& point) {
        is >> point.x >> point.y;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }

    void checkQuadrant() {
        if (x > 0 && y > 0) {
            std::cout << "Точка лежит в первой четверти." << std::endl;
        }
        else if (x < 0 && y > 0) {
            std::cout << "Точка лежит во второй четверти." << std::endl;
        }
        else if (x < 0 && y < 0) {
            std::cout << "Точка лежит в третьей четверти." << std::endl;
        }
        else if (x > 0 && y < 0) {
            std::cout << "Точка лежит в четвертой четверти." << std::endl;
        }
        else {
            std::cout << "Точка находится на одной из осей или в начале координат." << std::endl;
        }
    }

    void checkPositionOnLine(double m, double c) {
        double lineY = m * x + c;

        if (y > lineY) {
            std::cout << "Точка находится ниже линии y = " << m << "x + " << c << std::endl;
        }
        else if (y < lineY) {
            std::cout << "Точка находится выше линии  y = " << m << "x + " << c << std::endl;
        }
        else {
            std::cout << "Точка находится на линии y = " << m << "x + " << c << std::endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Point p;

    std::cout << "Введите координаты точки (x, y): ";
    std::cin >> p;

    std::cout << "Введенная точка: " << p << std::endl;

    p.checkQuadrant();

    double m, c;
    std::cout << "Введите (m) и точку пересечения оси Y (c) для линии (y = mx + c): ";
    std::cin >> m >> c;

    p.checkPositionOnLine(m, c);

    return 0;
}