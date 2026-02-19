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
 * @brief 计算平方（可用于常量表达式）。
 * @param value 待求平方的数值（按引用传入，但不会被修改）
 * @return `value * value`
 */
constexpr double
square(const double& value) { /* 函数不会修改传入参数值 */
    return value * value;
}

/**
 * @brief 在编译期强制求值的平方函数。
 * @param value 常量表达式参数
 * @return `value * value`
 */
consteval double
square1(const double& value) {
    return value * value;
}

/**
 * @brief 计算向量中所有元素之和（运行期）。
 * @param value 数值向量
 * @return 所有元素的累加和
 */
double
sum(const vector<double>& value) {
    double sum = 0;
    for (const double& v: value) { sum += v; }
    return sum;
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
    constexpr int dmv{ 17 };         /* dmv 是一个命名常量 */
    int var{ 17 };                   /* var 不是常量 */
    const double sqv{ square(var) }; /* sqv 是一个命名常量，可能在运行时计算 */
    cout << "dmv: " << dmv << ", var: " << var << ", sqv: " << sqv << endl;

    vector<double> v{ 1.2, 3.4, 5.6 };
    const double s1{ sum(v) }; /* 可行：sum(v) 在运行时计算 */
    // constexpr double s2{ sum(v) }; /* 错误：sum(v) 在编译时无法求值 */
    cout << "s1: " << s1 << endl;

    constexpr double max1{ 1.4 * square(17) }; /* 可行：全参数为字面值 */
    // constexpr double max2{ 1.4 * square(var) }; /* 错误：var
    // 不是常量，所以常量表达式不成立 */
    const double max3{ 1.4 * square(var) }; /* 可行：允许在运行时计算 */

    cout << "max1: " << max1 << ", max3: " << max3 << endl;

    const double max4{ 1.4 * square1(17) }; /* 可行：全参数为字面值 */
    // const double max5{ 1.4 * square1(var) }; /* 错误：consteval 不允许非常量
    // */
    cout << "max4: " << max4 << endl;
}
