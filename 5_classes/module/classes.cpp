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

/**
 * @file classes.cpp
 * @brief 第 5 章 类：C++20 模块主接口文件
 */

/**
 * @brief 类示例模块，构建第五章程序入口与各子章节的桥梁。
 */
export module classes;

/**
 * @defgroup classes_module_group 5_类 (Module)
 * @{
 *
 * @brief 第 5 章：类（Classes）的模块化实现
 *
 * 本模块导出第 5 章中定义的所有类教程入口函数。
 */

/**
 * @brief 5.1 引言：演示类的基本概念
 */
export auto
tutorial_introduction() -> void;

/**
 * @brief 5.2 具体类型：演示具体类的实现（如 Vector, Complex）
 */
export auto
tutorial_concrete_types() -> void;

/**
 * @brief 5.3 抽象类型：演示接口和抽象类
 */
export auto
tutorial_abstract_types() -> void;

/**
 * @brief 5.4 虚函数：演示多态和虚函数调用机制
 */
export auto
tutorial_virtual_functions() -> void;

/**
 * @brief 5.5 类层次结构：演示继承和复杂的类层次
 */
export auto
tutorial_class_hierarchies() -> void;

/** @} */
