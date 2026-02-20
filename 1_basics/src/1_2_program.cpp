/*
 * Copyright (C) 2026 Aaron <communicate_aaron@outlook.com>
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "basics.hpp"

using namespace std; /* 使 std 中的名称在不加 std:: 前缀时可见 */

/**
 * @brief 计算双精度浮点数的平方
 * @param x 需要计算平方的数值
 * @return x 的平方值
 *
 * 这是一个简单的数学辅助函数，用于演示函数的定义和返回值。
 * 位置：1_basics/src/1_2_program.cpp
 */
double
square(double x) {
    return x * x;
}

/**
 * @brief 在标准输出中打印一个数值及其平方结果
 * @param x 需要打印的数值
 *
 * 该函数内部调用了 square() 函数，演示了函数间的相互调用以及 std::cout 的格式化
 * 输出。
 */
void
print_square(double x) {
    cout << "the square of " << x << " is " << square(x) << endl;
}

/**
 * @ingroup basics_group
 * @brief 1.2 程序：入口函数
 *
 * 展示 C++ 程序的基本结构、命名空间的使用和辅助函数的调用。
 * 对应《C++ 之旅》1.2 节。
 */
void
tutorial_program() {
    cout << "--- 1.2 Program ---" << endl;
    std::cout << "Hello World!" << std::endl;
    /* std:: 前缀明确指定了 cout 的命名空间。 */
    cout << "not using std::" << endl;
    /* 由于使用了 'using namespace std;'，可以直接调用。 */
    print_square(1.234);
}
