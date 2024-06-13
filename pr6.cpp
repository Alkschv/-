#include <iostream>

class Deposit {
private:
    double interestRate; // ���������� ������
    int term; // ���� � �������
    bool canDepositWithdraw; // ����������� ����������/������ �����
    double balance; // ������� ������

public:
    Deposit(double rate, int months, bool canDeposit) : interestRate(rate), term(months), canDepositWithdraw(canDeposit), balance(0.0) {}

    void deposit(double amount) {
        if (canDepositWithdraw) {
            balance += amount;
            std::cout << "������� " << amount << " �������." << std::endl;
        }
        else {
            std::cout << "���������� ������ ������ �� ���� �����." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (canDepositWithdraw && balance >= amount) {
            balance -= amount;
            std::cout << "�������� " << amount << " �������." << std::endl;
        }
        else {
            std::cout << "���������� ������� ������ � ����� ������ ��� �� ������� ������������ �������." << std::endl;
        }
    }

    double calculateIncome() {
        double income = balance * interestRate * term / 12 / 100;
        return income;
    }

    friend std::ostream& operator<<(std::ostream& os, const Deposit& deposit) {
        os << "���������� ������: " << deposit.interestRate << "%" << std::endl;
        os << "����: " << deposit.term << " �������" << std::endl;
        os << "����������� ��������/������ �������: " << (deposit.canDepositWithdraw ? "��" : "���") << std::endl;
        os << "������: " << deposit.balance << std::endl;
        return os;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Deposit myDeposit(4.5, 12, true);

    std::cout << "������ ������:" << std::endl;
    std::cout << myDeposit << std::endl;

    myDeposit.deposit(1000);
    std::cout << "����� ������: " << std::endl;
    std::cout << myDeposit << std::endl;

    myDeposit.withdraw(500);
    std::cout << "����� ������: " << std::endl;
    std::cout << myDeposit << std::endl;

    double income = myDeposit.calculateIncome();
    std::cout << "��������� ����� ����� ��������� ����� ������: " << income << std::endl;

    return 0;
}