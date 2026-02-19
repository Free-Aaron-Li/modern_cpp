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

#ifndef MODERN_CPP_USER_DEFINED_TYPES_HPP
#define MODERN_CPP_USER_DEFINED_TYPES_HPP

/**
 * @file user_defined_types.hpp
 * @brief 第 2 章 用户自定义类型主头文件
 *
 * @copyright Copyright (c) 2026 Aaron.
 */
#include <iostream>

/**
 * @defgroup user_defined_types_group 2_ 用户自定义类型
 * @{
 *
 * @brief 第 2 章：用户自定义类型 (User-Defined Types)
 *
 * 本章主要介绍 C++ 中四种基本的用户自定义类型：结构体 (struct)、类
 * (class)、枚举 (enum) 和联合 (union)。
 *
 * 核心学习点：
 * - 2.1 引言：理解内置类型与用户自定义类型的区别。
 * - 2.2 结构体 (struct)：最简单的数据组合方式，成员默认公开。
 * - 2.3 类 (class)：支持封装、构造函数及成员访问控制。
 * - 2.4 枚举 (enum)：定义命名的常量集合，推荐使用 `enum class`。
 * - 2.5 联合 (union)：在同一内存位置存储不同类型，需谨慎管理。
 */

/**
 * @brief 2.2 结构体：演示 struct 的定义与初始化
 *
 * 介绍 C++ 中最简单的用户自定义类型，以及通过 new 在堆上分配内存。
 * 涵盖函数：`vector_init()`、`read_and_sum()` 和 `f()`
 */
void
tutorial_structs();

/**
 * @brief 2.3 类：演示 class 的封装与接口设计
 *
 * 介绍通过 public 和 private 关键字实现的访问控制，以及成员函数的定义。
 * 涵盖类：`Vector`
 */
void
tutorial_classes();

/**
 * @brief 2.4 枚举：演示 enum class 与普通 enum
 *
 * 比较强类型枚举（scoped enums）与传统枚举的区别。
 * 涵盖函数：`operator++(Traffic_light&)`
 */
void
tutorial_enums();

/**
 * @brief 2.5 联合：演示 union 的内存布局与应用
 *
 * 展示如何在同一块内存区域存储不同类型的变量，以及它的风险与现代替代方案。
 * 涵盖函数：`print_entry()`
 */
void
tutorial_unions();

/** @} */

#endif  // MODERN_CPP_USER_DEFINED_TYPES_HPP
