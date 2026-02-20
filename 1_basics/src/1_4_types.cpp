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

#include <complex>

#include "basics.hpp"

using namespace std;

/**
 * @brief 打印各内置类型占用的内存大小
 *
 * 演示 sizeof() 运算符，了解不同数据类型在硬件层面映射时的尺寸。
 * 位置：1_basics/src/1_4_types.cpp
 */
void
size_of_type() {
    cout << "--- size of type ---" << endl;
    cout << "size of char: " << sizeof(char) << " byte" << endl;
    cout << "size of bool: " << sizeof(bool) << " byte" << endl;
    cout << "size of int: " << sizeof(int) << " bytes" << endl;
    cout << "size of float: " << sizeof(float) << " bytes" << endl;
    cout << "size of double: " << sizeof(double) << " bytes" << endl;
    cout << "size of complex<double>: " << sizeof(complex<double>) << " bytes"
         << endl;
}

/**
 * @brief 演示不同进位制下的数字字面量表示
 *
 * 展示了 C++ 支持的字面量书写方式，包括：
 * - 十进制（Decimal）
 * - 二进制（Binary，0b 开头）
 * - 十六进制（Hex，0x 开头）
 * - 八进制（Octal，0 开头）
 */
void
print_num() {
    const float f1{ 3.14 };  // 统一初始化
    const float f2(314e-2);  // 传统的括号初始化
    cout << "f1 (float, {3.14}): " << f1 << endl;
    cout << "f2 (float, (314e-2)): " << f2 << endl;
    const double i1{ 10 };  // 十进制
    const double i2{ 0b1010'1010 };
    // 二进制（170），使用单引号作为数字分隔符（C++ 14）
    const double i3{ 0xBAD1'2CE3 };  // 十六进制
    const double i4{ 0334 };         // 八进制
    cout << "i1 (decimal 10): " << i1 << endl;
    cout << "i2 (binary 0b10101010): " << i2 << endl;
    cout << "i3 (hex 0xBAD12CE3): " << i3 << endl;
    cout << "i4 (octal 0334): " << i4 << endl;
}

/**
 * @brief 演示统一初始化与窄化转换
 *
 * 展示了 C++ 11 引入的统一初始化（Uniform Initialization）语法，以及
 * 它如何通过禁止窄化转换来提高代码安全性。
 */
void
initialization_list() {
    double          d1{ 2.3 };
    double          d2 = { 2.3 }; /* 使用 {...} 时可以省略 = 符号 */
    complex<double> c1{ 2.3, 4.5 };
    vector<int>     v{ 1, 2, 3 };

    int i1 = 7.8; /* i1 会窄化类型转换，变为 7 */
    /* {} 方式不接受隐式类型转换 */
    // int i2{ 7.8 }; /* 错误：narrowing conversion of ‘7.7999999999999998e+0’
    // from ‘double’ to ‘int’ [-Wnarrowing] */

    cout << "d1: " << d1 << ", d2: " << d2 << endl;
    cout << "c1: " << c1 << endl;
    for (auto& x: v) { cout << "v: " << x << endl; }
    cout << "i1: " << i1 << endl;
}

/**
 * @ingroup basics_group
 * @brief 1.4 类型、变量与算术
 *
 * 演示 C++ 作为静态强类型语言的特性，以及内置类型的尺寸和字面量表现。
 * 对应《C++ 之旅》1.4 节。
 */
void
tutorial_types() {
    cout << "--- 1.4 Types, Variables, and Arithmetic ---" << endl;
    size_of_type();
    print_num();
    initialization_list();
}
