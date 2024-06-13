#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    void convertTo12HourFormat() {
        if (hours > 12) {
            hours -= 12;
        }
    }

    bool operator>(const Time& other) const {
        if (hours != other.hours) {
            return hours > other.hours;
        }
        else if (minutes != other.minutes) {
            return minutes > other.minutes;
        }
        else {
            return seconds > other.seconds;
        }
    }

    bool operator<(const Time& other) const {
        return other > *this;
    }

    bool operator==(const Time& other) const {
        return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
    }

    bool operator!=(const Time& other) const {
        return !(*this == other);
    }

    Time operator+(const Time& other) const {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds + other.hours * 3600 + other.minutes * 60 + other.seconds;
        int h = totalSeconds / 3600;
        int m = (totalSeconds % 3600) / 60;
        int s = totalSeconds % 60;
        return Time(h, m, s);
    }

    Time operator*(int factor) const {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds;
        totalSeconds *= factor;
        int h = totalSeconds / 3600;
        int m = (totalSeconds % 3600) / 60;
        int s = totalSeconds % 60;
        return Time(h, m, s);
    }

    Time operator-(const Time& other) const {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds - (other.hours * 3600 + other.minutes * 60 + other.seconds);
        int h = totalSeconds / 3600;
        int m = (totalSeconds % 3600) / 60;
        int s = totalSeconds % 60;
        return Time(h, m, s);
    }

    Time operator/(int divisor) const {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds;
        totalSeconds /= divisor;
        int h = totalSeconds / 3600;
        int m = (totalSeconds % 3600) / 60;
        int s = totalSeconds % 60;
        return Time(h, m, s);
    }

    friend std::ostream& operator<<(std::ostream& os, const Time& time) {
        os << time.hours << ":" << time.minutes << ":" << time.seconds;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Time& time) {
        is >> time.hours >> time.minutes >> time.seconds;
        return is;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Time t1(10, 30, 45);
    Time t2(5, 15, 20);

    std::cout << "Т1: " << t1 << std::endl;
    std::cout << "Т2: " << t2 << std::endl;

    if (t1 > t2) {
        std::cout << "Т1 больше чем Т2" << std::endl;
    }

    Time sum = t1 + t2;
    std::cout << "Сумма: " << sum << std::endl;

    Time multiplication = t1 * 2;
    std::cout << "Деление: " << multiplication << std::endl;

    Time difference = t1 - t2;
    std::cout << "Разница: " << difference << std::endl;

    Time division = t1 / 2;
    std::cout << "Деление: " << division << std::endl;

    // Convert t1 to 12-hour format
    t1.convertTo12HourFormat();
    std::cout << "Т1 в 12-часовом формате: " << t1 << std::endl;

    return 0;
}