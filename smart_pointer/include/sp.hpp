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

#ifndef MODERN_CPP_SP_HPP
#define MODERN_CPP_SP_HPP

/**
 * @file sp.hpp
 * @brief 智能指针模块主头文件
 *
 * @page smart_pointer_page 智能指针模块文档
 *
 * @section intro_sec 模块概述
 *
 * 本模块是 Modern CPP 学习项目的核心部分之一，专注于现代 C++ 中的内存管理机制。
 * 涵盖了从最基础的 RAII（资源获取即初始化）手法到高级的智能指针应用。
 *
 * ### 核心学习点：
 * - **RAII 手法**：理解对象生命周期与资源管理的绑定关系。
 * - **独占所有权**：`std::unique_ptr` 的实现与应用（规划中）。
 * - **引用计数**：`std::shared_ptr` 的原理（规划中）。
 *
 * @section dependencies_sec 依赖项
 *
 * 本模块主要依赖于 C++ 标准库，以展示原生特性的使用：
 * - `<iostream>`: 用于演示输出。
 * - `<memory>`: 提供标准智能指针支持（后续引入）。
 *
 * @section usage_sec 快速开始
 *
 * 1. 包含主头文件：
 *    @code{.cpp}
 *    #include "raii.hpp"
 *    @endcode
 * 2. 编写符合 RAII 原则的代码：
 *    @code{.cpp}
 *    {
 *        CRAII manager(new RAII_TEST());
 *        // 离开作用域时 manager 自动释放资源
 *    }
 *    @endcode
 *
 * @section group_sec 相关模块
 * - @ref sp_raii_group "RAII 手法实现"
 *
 * @copyright Copyright (c) 2026 Aaron.
 */

#include <iostream>

#endif //MODERN_CPP_SP_HPP