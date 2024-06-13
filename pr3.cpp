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
            std::cout << "����� ����� � ������ ��������." << std::endl;
        }
        else if (x < 0 && y > 0) {
            std::cout << "����� ����� �� ������ ��������." << std::endl;
        }
        else if (x < 0 && y < 0) {
            std::cout << "����� ����� � ������� ��������." << std::endl;
        }
        else if (x > 0 && y < 0) {
            std::cout << "����� ����� � ��������� ��������." << std::endl;
        }
        else {
            std::cout << "����� ��������� �� ����� �� ���� ��� � ������ ���������." << std::endl;
        }
    }

    void checkPositionOnLine(double m, double c) {
        double lineY = m * x + c;

        if (y > lineY) {
            std::cout << "����� ��������� ���� ����� y = " << m << "x + " << c << std::endl;
        }
        else if (y < lineY) {
            std::cout << "����� ��������� ���� �����  y = " << m << "x + " << c << std::endl;
        }
        else {
            std::cout << "����� ��������� �� ����� y = " << m << "x + " << c << std::endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Point p;

    std::cout << "������� ���������� ����� (x, y): ";
    std::cin >> p;

    std::cout << "��������� �����: " << p << std::endl;

    p.checkQuadrant();

    double m, c;
    std::cout << "������� (m) � ����� ����������� ��� Y (c) ��� ����� (y = mx + c): ";
    std::cin >> m >> c;

    p.checkPositionOnLine(m, c);

    return 0;
}