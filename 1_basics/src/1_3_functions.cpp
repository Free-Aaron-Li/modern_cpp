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

using namespace std;

/**
 * @brief 重载函数 1：接收整数和浮点数
 * @param a 整数参数
 * @param b 浮点数参数
 *
 * 展示了当编译器发现多个同名函数但参数签名（Signature）不同时，会自动选择匹配的
 * 函数进行调用。
 */
void
print(int a, double b) {
    cout << "a=" << a << ", b=" << b << " (int, double)" << endl;
}

/**
 * @brief 重载函数 2：接收浮点数和整数
 * @param a 浮点数参数
 * @param b 整数参数
 *
 * 与 print(int, double) 构成重载，两者的参数顺序不同，这也属于不同的函数签名。
 */
void
print(double a, int b) {
    cout << "a=" << a << ", b=" << b << " (double, int)" << endl;
}

/**
 * @ingroup basics_group
 * @brief 1.3 函数：重载与声明
 *
 * 演示 C++ 的函数重载（Overloading）机制。
 * 重载机制允许程序员对不同的参数类型集合使用相同的名字，从而提高代码的可读性。
 *
 * 对应《C++ 之旅》1.3 节。
 */
void
tutorial_functions() {
    cout << "--- 1.3 Functions ---" << endl;

    // 自动匹配最合适的重载版本
    print(1, 2.0); // 调用 print(int, double)
    print(1.0, 2); // 调用 print(double, int)

    /*
     * ⚠️ 注意：调用 `print(1, 2)`
     * 会产生歧义，因为两个版本都需要隐式类型转换，且优先级相同。
     */
}
