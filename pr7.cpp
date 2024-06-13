#include <iostream>
#include <ctime>

class Stopwatch {
private:
    clock_t startTime;
    clock_t stopTime;
    bool isRunning;
    double elapsedTime;

public:
    Stopwatch() : startTime(0), stopTime(0), isRunning(false), elapsedTime(0) {}

    void start() {
        if (!isRunning) {
            startTime = clock();
            isRunning = true;
            std::cout << "���������� ����������." << std::endl;
        }
        else {
            std::cout << "���������� ��� ��������." << std::endl;
        }
    }

    void stop() {
        if (!isRunning) {
            std::cout << "���������� �� ��������." << std::endl;
        }
        else {
            stopTime = clock();
            elapsedTime += static_cast<double>(stopTime - startTime) / CLOCKS_PER_SEC;
            isRunning = false;
            std::cout << "���������� �����������." << std::endl;
        }
    }

    void reset() {
        startTime = 0;
        stopTime = 0;
        isRunning = false;
        elapsedTime = 0;
        std::cout << "����� �����������." << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Stopwatch& stopwatch) {
        os << "���������� �����: " << stopwatch.elapsedTime << " �������" << std::endl;
        return os;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Stopwatch timer;

    timer.start();
    for (int i = 0; i < 1000000000; ++i) {} // Some time-consuming operation
    timer.stop();

    std::cout << "���������� �� ������� : " << timer << std::endl;

    timer.reset();

    return 0;
}