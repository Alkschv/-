#include <iostream>

class Deposit {
private:
    double interestRate; // процентная ставка
    int term; // срок в месяцах
    bool canDepositWithdraw; // возможность пополнения/снятия денег
    double balance; // текущий баланс

public:
    Deposit(double rate, int months, bool canDeposit) : interestRate(rate), term(months), canDepositWithdraw(canDeposit), balance(0.0) {}

    void deposit(double amount) {
        if (canDepositWithdraw) {
            balance += amount;
            std::cout << "Внесено " << amount << " успешно." << std::endl;
        }
        else {
            std::cout << "Невозможно внести деньги на этот вклад." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (canDepositWithdraw && balance >= amount) {
            balance -= amount;
            std::cout << "Выведено " << amount << " успешно." << std::endl;
        }
        else {
            std::cout << "Невозможно вывести деньги с этого вклада или на балансе недостаточно средств." << std::endl;
        }
    }

    double calculateIncome() {
        double income = balance * interestRate * term / 12 / 100;
        return income;
    }

    friend std::ostream& operator<<(std::ostream& os, const Deposit& deposit) {
        os << "Процентная ставка: " << deposit.interestRate << "%" << std::endl;
        os << "Срок: " << deposit.term << " месяцев" << std::endl;
        os << "Возможность внесения/вывода средств: " << (deposit.canDepositWithdraw ? "Да" : "Нет") << std::endl;
        os << "Баланс: " << deposit.balance << std::endl;
        return os;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Deposit myDeposit(4.5, 12, true);

    std::cout << "Детали вклада:" << std::endl;
    std::cout << myDeposit << std::endl;

    myDeposit.deposit(1000);
    std::cout << "После вклада: " << std::endl;
    std::cout << myDeposit << std::endl;

    myDeposit.withdraw(500);
    std::cout << "После вывода: " << std::endl;
    std::cout << myDeposit << std::endl;

    double income = myDeposit.calculateIncome();
    std::cout << "Ожидаемый доход после окончания срока вклада: " << income << std::endl;

    return 0;
}