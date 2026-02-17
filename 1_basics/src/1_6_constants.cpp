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

using namespace std;

constexpr double
const_square(double x) {
    return x * x;
}

/**
 * @ingroup basics_group
 * @brief 演示常量 (const 和 constexpr)
 * 
 * 对应《C++ 之旅》1.6 节
 */
void
tutorial_constants() {
    cout << "--- 1.6 Constants ---" << endl;

    const int dmv = 17; // dmv 是一个常量
    int var = 17;

    constexpr double max1 = 1.4 * const_square(dmv); // OK
    // constexpr double max2 = 1.4 * const_square(var); // Error: var 不是常量表达式
    const double max3 = 1.4 * const_square(var); // OK, 在运行时求值

    cout << "max1: " << max1 << ", max3: " << max3 << endl;
}