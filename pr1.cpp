#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;

public:
    Matrix(int rows, int cols) : data(rows, std::vector<int>(cols)) {}

    Matrix(const Matrix& other) : data(other.data) {}

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result(*this);
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[i].size(); ++j) {
                result.data[i][j] += other.data[i][j];
            }
        }
        return result;
    }

    Matrix& operator+=(const Matrix& other) {
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[i].size(); ++j) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result(*this);
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[i].size(); ++j) {
                result.data[i][j] -= other.data[i][j];
            }
        }
        return result;
    }

    Matrix& operator-=(const Matrix& other) {
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[i].size(); ++j) {
                data[i][j] -= other.data[i][j];
            }
        }
        return *this;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(data.size(), other.data[0].size());
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < other.data[0].size(); ++j) {
                for (size_t k = 0; k < data[i].size(); ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix& operator*=(const Matrix& other) {
        *this = *this * other;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (const auto& row : matrix.data) {
            for (int val : row) {
                os << val << " ";
            }
            os << std::endl;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
        for (auto& row : matrix.data) {
            for (int& val : row) {
                is >> val;
            }
        }
        return is;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Matrix A(2, 2);
    Matrix B(2, 2);

    std::cout << "¬ведите значени€ дл€ матрицы A (2x2):\n";
    std::cin >> A;

    std::cout << "¬ведите значени€ дл€ матрицы B (2x2):\n";
    std::cin >> B;

    Matrix C = A + B;
    std::cout << "A + B:\n" << C;

    Matrix D = A - B;
    std::cout << "A - B:\n" << D;

    Matrix E = A * B;
    std::cout << "A * B:\n" << E;

    return 0;
}
