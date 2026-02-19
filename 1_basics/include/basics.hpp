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

#ifndef MODERN_CPP_BASICS_HPP
#define MODERN_CPP_BASICS_HPP

/**
 * @file basics.hpp
 * @brief 基础章节主头文件
 *
 * @copyright Copyright (c) 2026 Aaron.
 */
#include <iostream>
#include <vector>

/**
 * @defgroup basics_group 1_基础
 * @{
 */

/**
 * @brief 1.2 程序：演示 C++ 程序的基本结构
 *
 * 展示了如何定义 `main` 函数以外的辅助函数，以及如何使用标准库中的 I/O 流。
 * 包含函数：`square()`, `print_square()`
 */
void
tutorial_program();

/**
 * @brief 1.3 函数：演示函数的定义与调用
 *
 * 重点展示 C++
 * 的函数重载（Overloading）机制，即同名函数根据参数列表不同而区分。
 * 包含函数：`print(int, double)`, `print(double, int)`
 */
void
tutorial_functions();

/**
 * @brief 1.4 类型、变量与算术：演示内置类型与算术运算
 *
 * 展示了 C++
 * 中各内置类型的大小（`sizeof`），以及二进制、十六进制、八进制等多种字面量的表
 * 示方法。
 * 包含函数：`size_of_type()`, `print_num()`
 */
void
tutorial_types();

/**
 * @brief 1.6 常量：演示 `const`、`constexpr` 与 `consteval`
 *
 * 区分不同类型的常量修饰符：`const` 承诺不改变值，`constexpr`
 * 允许编译期计算，`consteval` 强制编译期计算。 包含函数：`square()`,
 * `square1()`, `sum()`
 */
void
tutorial_constants();

/**
 * @brief 1.7 指针、数组与引用：演示基础内存操作
 *
 * 展示范围 `for` 语句遍历数组、指针的空值检查（`nullptr`）以及引用的别名特性。
 * 包含函数：`print()`, `increment()`
 */
void
tutorial_pointers();

/**
 * @brief 1.8 检验：演示条件判断与循环
 *
 * 展示交互式输入处理、`if-else` 分支、`switch-case` 结构及各类循环。
 * 包含函数：`accept()`, `accept2()`, `action()`
 */
void
tutorial_tests();

/** @} */

#endif  // MODERN_CPP_BASICS_HPP
