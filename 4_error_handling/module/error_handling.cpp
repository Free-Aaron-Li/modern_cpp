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
 * @file error_handling.cpp
 * @brief 第 4 章 错误处理：C++20 模块主接口文件
 */

/**
 * @brief 错误处理示例模块，构建第四章程序入口与各子章节的桥梁。
 */
export module error_handling;

/**
 * @defgroup error_handling_module_group 4_错误处理 (Module)
 * @{
 *
 * @brief 第 4 章：错误处理（Error Handling）的模块化实现
 *
 * 本模块导出第 4 章中定义的所有错误处理教程入口函数。
 */

/**
 * @brief 4.2 异常：演示 C++ 异常处理机制
 */
export auto
tutorial_exceptions() -> void;

/**
 * @brief 4.3 约束条件：演示对象不变式检查
 */
export auto
tutorial_invariants() -> void;

/**
 * @brief 4.4 错误处理的其他替代方式：演示非异常错误处理
 */
export auto
tutorial_error_handling_alternatives() -> void;

/**
 * @brief 4.5 断言：演示运行期与编译期检查
 */
export auto
tutorial_assertions() -> void;

/** @} */
