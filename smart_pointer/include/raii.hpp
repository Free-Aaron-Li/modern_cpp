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

#ifndef MODERN_CPP_RAII_HPP
#define MODERN_CPP_RAII_HPP

#include "sp.hpp"
/**
 * @file raii.hpp
 * @defgroup sp_raii_group RAII 手法
 * @brief RAII (Resource Acquisition Is Initialization) 手法模块。
 * @details 
 * ### RAII 简介
 * RAII（资源获取即初始化）是一种 C++ 编程技术，它将资源的生命周期与对象的生命周期绑定在一起。
 * 
 * #### 核心原理：
 * 1. 获取资源即初始化：在构造函数中获取资源（如内存、文件句柄、互斥锁等）。
 * 2. 释放资源即销毁：在析构函数中自动释放资源。
 * 
 * #### 主要优势：
 * - 安全性：防止资源泄漏（即使发生异常，析构函数也会被调用）。
 * - 简洁性：不需要手动调用释放资源的函数（如 `free`, `delete`, `fclose`）。
 * 
 * ### 模块内容：
 * - @ref RAII_TEST : 一个简单的类，用于观察构造和析构的调用。
 * - @ref CRAII : 一个 RAII 管理类，演示如何自动管理资源的生命周期。
 * 
 * ### 相关文档：
 * - @ref smart_pointer_doc "智能指针概说 - RAII 章节"
 */

/**
 * @brief RAII 手法测试类。
 * @details 这是一个简单的测试类，其构造函数和析构函数会输出信息，以便观察对象的生命周期。
 * @ingroup sp_raii_group
 */
class RAII_TEST {
public:
    /**
     * @brief 构造函数。
     * 输出 "raii_test()"。
     */
    RAII_TEST() {
        std::cout << "raii_test()" << std::endl;
    }

    /**
     * @brief 析构函数。
     * 输出 "~raii_test()"。
     */
    ~RAII_TEST() {
        std::cout << "~raii_test()" << std::endl;
    }
};

/**
 * @brief RAII 管理类 CRAII。
 * @details 该类展示了如何应用 RAII 手法。它在构造时接收一个裸指针，并在析构时负责删除该指针指向的对象。
 * @note 这是一个教学性质的实现，在实际生产中推荐使用 `std::unique_ptr` 或 `std::shared_ptr`。
 * @ingroup sp_raii_group
 */
class CRAII {
public:
    /**
     * @brief 构造函数，接管资源。
     * @param p 指向需要管理的 RAII_TEST 对象的指针。
     */
    CRAII(RAII_TEST* p) {
        raii_test_ = p;
    }

    /**
     * @brief 析构函数，释放资源。
     * 自动调用 `delete` 释放被管理的对象，从而实现 RAII。
     */
    ~CRAII() {
        std::cout << "~CRAII()" << std::endl;
        delete raii_test_;
        raii_test_ = nullptr;
    }

private:
    RAII_TEST* raii_test_; ///< 被管理的资源指针
};


#endif //MODERN_CPP_RAII_HPP
