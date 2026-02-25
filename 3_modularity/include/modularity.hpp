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

#ifndef MODERN_CPP_MODULARITY_HPP
#define MODERN_CPP_MODULARITY_HPP

/**
 * @file modularity.hpp
 * @brief 第 3 章 模块化主头文件
 *
 * @copyright Copyright (c) 2026 Aaron.
 */
#include <iostream>
#include <string>
#include <vector>

/**
 * @defgroup modularity_group 3_模块化
 * @{
 *
 * @brief 第 3 章：模块化（Modularity）
 *
 * 本章主要介绍 C++ 如何支持模块化编程，包括分离编译、
 * 命名空间、函数参数与返回值以及错误处理。
 *
 * 核心学习点：
 * - 3.2 分离编译：理解头文件与源文件的角色。
 * - 3.3 命名空间：避免命名冲突并组织代码。
 * - 3.4 函数参数与返回值：参数传递、值返回与结构化绑定。
 * - 3.5 错误处理：异常、对象不变式与静态断言。
 */

/**
 * @brief 3.2 分离编译：演示头文件与源文件的分离
 *
 * 涉及：@ref ch3_separate_compilation_impl::Vector, @ref
 * ch3_separate_compilation_impl::ModularVector,
 * @ref ch3_separate_compilation_impl::sqrt_sum, @ref
 * ch3_separate_compilation_impl::module_sqrt_sum
 */
void
tutorial_separate_compilation();

/**
 * @brief 3.3 命名空间：演示 namespace 的定义与使用
 *
 * 涉及：@ref ch3_namespaces_impl::complex
 */
void
tutorial_namespaces();

/**
 * @brief 3.4 函数参数与返回值：演示参数传递与结构化绑定
 *
 * 涉及：@ref ch3_args_and_returns_impl::test_argument_passing, @ref
 * ch3_args_and_returns_impl::test_structured_bindings,
 * @ref ch3_args_and_returns_impl::Entry
 */
void
tutorial_function_arguments_and_return_values();

/** @} */

#endif  // MODERN_CPP_MODULARITY_HPP
