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
#include <complex>

using namespace std;

/**
 * @ingroup basics_group
 * @brief 演示内置类型与算术运算
 * 
 * 对应《C++之旅》1.4 节
 */
void
tutorial_types() {
    cout << "--- 1.4 Types, Variables, and Arithmetic ---" << endl;

    int a = 1;
    double d = 2.2;
    complex<double> z = {1, 2}; // 统一初始化
    auto b = true; // 自动类型推导

    cout << "int: " << a << ", double: " << d << ", complex: " << z << ", bool: " << b << endl;

    // 算术运算
    a = a + 1;
    d = d * a;

    cout << "After arithmetic: a=" << a << ", d=" << d << endl;
}