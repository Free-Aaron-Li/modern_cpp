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

#ifndef MODERN_CPP_1_BASICS_HPP
#define MODERN_CPP_1_BASICS_HPP

/**
 * @file 1_basics.hpp
 * @brief 基础章节主头文件
 *
 * @page basics_page 基础章节文档
 *
 * @section intro_basics_sec 章节概述
 *
 * 本章节是 Modern CPP 学习项目的起始章节，涵盖了 C++ 的核心语言特性和标准库组件的基础概念。
 * 内容参考自 Bjarne Stroustrup 的《C++之旅》（A Tour of C++）。
 *
 * ### 核心学习点：
 *
 * - **语言实体**：理解核心语言特性与标准库组件的区别。
 * - **程序基础**：掌握 C++ 程序的基本构成。
 *
 * @section docs_basics_sec 深入阅读
 *
 * - @ref basics_doc "第1章 基础"
 *
 * @copyright Copyright (c) 2026 Aaron.
 */
#include <iostream>

/**
 * @defgroup basics_group 第1章 基础示例
 * @{
 */

/**
 * @brief 演示 C++ 程序的基本结构
 */
void
tutorial_program();

/**
 * @brief 演示函数的定义与调用
 */
void
tutorial_functions();

/**
 * @brief 演示内置类型与算术运算
 */
void
tutorial_types();

/**
 * @brief 演示常量 (const 和 constexpr)
 */
void
tutorial_constants();

/**
 * @brief 演示指针、数组与引用
 */
void
tutorial_pointers();

/**
 * @brief 演示条件判断与循环
 */
void
tutorial_tests();

/** @} */

#endif //MODERN_CPP_1_BASICS_HPP
