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
#include "1_basics.hpp"

using namespace std; /* 使用std中的名称在不用std::时可见 */

double
square(double x) { /* 求双精度浮点数的平方（square） */
    return x * x;
}

void
print_square(double x) {
    cout << "the square of " << x << " is " << square(x) << endl;
}

/**
 * @ingroup basics_group
 * @brief 演示 C++ 程序的基本结构
 * 
 * 对应《C++之旅》1.2 节
 */
void
tutorial_program() { /* 花括号用于标识函数体的开始与结束 */
    std::cout << "Hello World!" << std::endl; /* std:: 代表cout来自标准库命名空间。 */
    cout << "not using std::" << endl;
    print_square(1.234); /* 输出：the square of 1.234 is 1.52276 */
}
