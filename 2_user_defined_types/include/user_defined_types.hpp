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

#ifndef MODERN_CPP_2_USER_DEFINED_TYPES_HPP
#define MODERN_CPP_2_USER_DEFINED_TYPES_HPP

/**
 * @file user_defined_types.hpp
 * @brief 第 2 章 用户自定义类型主头文件
 *
 * @copyright Copyright (c) 2026 Aaron.
 */
#include <iostream>

/**
 * @defgroup user_defined_types_group 2_用户自定义类型
 * @{
 */

/**
 * @brief 2.2 结构体：演示 struct 的定义与初始化
 * 
 * 介绍 C++ 中最简单的用户自定义类型，以及构造函数的初步概念。
 */
void
tutorial_structs();

/**
 * @brief 2.3 类：演示 class 的封装与接口设计
 * 
 * 介绍通过 public 和 private 关键字实现的访问控制，以及成员函数的定义。
 */
void
tutorial_classes();

/**
 * @brief 2.4 枚举：演示 enum class 与普通 enum
 * 
 * 比较强类型枚举（scoped enums）与传统枚举的区别。
 */
void
tutorial_enums();

/**
 * @brief 2.5 联合：演示 union 的内存布局与应用
 * 
 * 展示如何在同一块内存区域存储不同类型的变量，以及它的风险与现代替代方案。
 */
void
tutorial_unions();

/** @} */

#endif //MODERN_CPP_2_USER_DEFINED_TYPES_HPP