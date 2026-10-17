/**
题目描述
设计一个 Matrix2 类表示 2×2 整数矩阵。

重载 + 运算符计算两个矩阵之和，重载 * 运算符计算两个矩阵之积，重载 << 运算符按两行两列输出矩阵。

矩阵乘法按照标准定义计算。
--------------------------------------------------------------------------------------------------
输入
输入四行，每行包含两个整数。
前两行表示第一个矩阵，后两行表示第二个矩阵。每个元素的绝对值不超过 1000
--------------------------------------------------------------------------------------------------
输出
先输出矩阵之和，再输出矩阵之积：

Sum:
和矩阵第1行
和矩阵第2行
Product:
积矩阵第1行
积矩阵第2行
每行两个元素之间用一个空格分隔。
--------------------------------------------------------------------------------------------------
样例输入
1 2
3 4
5 6
7 8
样例输出 
Sum:
6 8
10 12
Product:
19 22
--------------------------------------------------------------------------------------------------
正确答案：
**/
#include <iostream>

class Matrix {
private:
    int data[2][2]{};

public:
    Matrix() = default;

    int* operator[](int row) {
        return data[row];
    }

    const int* operator[](int row) const {
        return data[row];
    }

   //返回新结果的时候要选择创建副本
   //如果使用+=，会使用Matrix& return *this
    Matrix operator+(const Matrix& other) const {
        Matrix result;

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                result.data[i][j] =
                    data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result;

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    result.data[i][j] +=
                        data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

    friend std::ostream& operator<<(
        std::ostream& os, const Matrix& matrix) {

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                os << matrix[i][j];

                if (j == 1) {
                    os << std::endl;
                } else {
                    os << " ";
                }
            }
        }

        return os;
    }
};

int main() {
    Matrix mat1;
    Matrix mat2;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cin >> mat1[i][j];
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cin >> mat2[i][j];
        }
    }

    std::cout << "Sum:" << std::endl;
    std::cout << mat1 + mat2;

    std::cout << "Product:" << std::endl;
    std::cout << mat1 * mat2;

    return 0;
}
