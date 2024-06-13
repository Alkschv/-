#include <iostream>

class Color {
private:
    int red;
    int green;
    int blue;

public:
    Color(int _red = 0, int _green = 0, int _blue = 0) : red(_red), green(_green), blue(_blue) {}

    bool operator==(const Color& other) const {
        return red == other.red && green == other.green && blue == other.blue;
    }

    bool operator!=(const Color& other) const {
        return !(*this == other);
    }

    bool isValidColorValue(int value) const {
        return value >= 0 && value <= 255;
    }

    bool isValidColor() const {
        return isValidColorValue(red) && isValidColorValue(green) && isValidColorValue(blue);
    }

    friend std::istream& operator>>(std::istream& is, Color& color) {
        is >> color.red >> color.green >> color.blue;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Color& color) {
        os << "RGB(" << color.red << ", " << color.green << ", " << color.blue << ")";
        return os;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Color color1, color2;

    std::cout << "¬ведите значени€ RGB дл€ цвета 1 (0-255): ";
    std::cin >> color1;

    std::cout << "¬ведите значени€ RGB дл€ цвета 2 (0-255): ";
    std::cin >> color2;

    std::cout << "÷вет 1: " << color1 << std::endl;
    std::cout << "÷вет 2: " << color2 << std::endl;

    if (color1.isValidColor()) {
        std::cout << "÷вет 1 - допустимый RGB." << std::endl;
    }
    else {
        std::cout << "÷вет 1 - недопустимый RGB." << std::endl;
    }

    if (color2.isValidColor()) {
        std::cout << "÷вет 2 - допустимый RGB." << std::endl;
    }
    else {
        std::cout << "÷вет 2 - недопустимый RGB." << std::endl;
    }

    if (color1 == color2) {
        std::cout << "÷вет 1 и цвет 2 одинаковые." << std::endl;
    }
    else {
        std::cout << "÷вет 1 и цвет 2 неодинаковые." << std::endl;
    }

    return 0;
}