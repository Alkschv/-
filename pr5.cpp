#include <iostream>
#include <string>

class Password {
private:
    std::string password;

public:
    Password(const std::string& pass) : password(pass) {}

    std::string getStrength() {
        if (password.length() < 6) {
            return "Слабый ";
        }
        else if (password.length() >= 6 && password.length() <= 10) {
            return "Средний";
        }
        else {
            return "Сильный";
        }
    }

    bool operator==(const Password& other) const {
        return password == other.password;
    }

    bool operator!=(const Password& other) const {
        return !(*this == other);
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    std::string pass1, pass2;

    std::cout << "Введите пароль 1: ";
    std::cin >> pass1;
    Password password1(pass1);

    std::cout << "Введите пароль 2: ";
    std::cin >> pass2;
    Password password2(pass2);

    std::cout << "Надежность пароля 1: " << password1.getStrength() << std::endl;
    std::cout << "Надежность пароля 2: " << password2.getStrength() << std::endl;

    if (password1 == password2) {
        std::cout << "Пароли одинаковые." << std::endl;
    }
    else {
        std::cout << "Пароли разные." << std::endl;
    }

    return 0;
}