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

#ifndef MODERN_CPP_SHARED_PTR_HPP
#define MODERN_CPP_SHARED_PTR_HPP
#include <iostream>
#include <ostream>

/**
 * @file shared_ptr.hpp
 * @defgroup sp_shared_ptr_group 引用计数智能指针 (shared_ptr)
 * @brief 演示 std::shared_ptr 的基本用法。
 * @details
 * ### shared_ptr 简介
 * `std::shared_ptr` 是一种通过引用计数实现共享所有权的智能指针。
 * 多个 `shared_ptr` 对象可以拥有同一个资源。
 *
 * #### 核心特性：
 *
 * 1. **引用计数**：记录有多少个 `shared_ptr` 指向同一个资源。
 * 2. **自动释放**：当最后一个指向资源的 `shared_ptr` 被销毁时，资源会被自动释放。
 * 3. **共享所有权**：可以通过拷贝构造和赋值操作分享所有权。
 *
 * ### 模块内容：
 * - @ref SHARED_PTR_TEST : 一个简单的类，用于观察 shared_ptr 管理下的对象生命周期。
 * - @ref CSPTEST : 演示 std::enable_shared_from_this 用法的类。
 *
 * ### 相关文档：
 * - @ref smart_pointer_doc "智能指针概说 - shared_ptr 章节"
 */

/**
 * @brief shared_ptr 手法测试类。
 * @details 这是一个简单的测试类，其构造函数和析构函数会输出信息，以便观察在 shared_ptr 引用计数变化时对象的生命周期。
 * @ingroup sp_shared_ptr_group
 */
class SHARED_PTR_TEST {
public:
    /**
     * @brief 构造函数。
     * 输出 "shared_ptr_test()"。
     */
    SHARED_PTR_TEST() {
        std::cout << "shared_ptr_test()" << std::endl;
    }

    /**
     * @brief 析构函数。
     * 输出 "~shared_ptr_test()"。
     */
    ~SHARED_PTR_TEST() {
        std::cout << "~shared_ptr_test()" << std::endl;
    }
};

/**
 * @brief 演示 std::enable_shared_from_this 的类。
 * @details 该类继承自 `std::enable_shared_from_this<CSPTEST>`，允许在类成员函数中安全地获取自身的 `std::shared_ptr`。
 * 这在需要将当前对象的生命周期交由 `std::shared_ptr` 管理，并将其存入容器或传递给其他异步处理时非常有用。
 * @ingroup sp_shared_ptr_group
 */
class CSPTEST : public std::enable_shared_from_this<CSPTEST> {
public:
    /**
     * @brief 构造函数。
     * 输出 "CSPTEST()"。
     */
    CSPTEST() {
        std::cout << "CSPTEST()" << std::endl;
    }

    /**
     * @brief 析构函数。
     * 输出 "~CSPTEST()"。
     */
    ~CSPTEST() {
        std::cout << "~CSPTEST()" << std::endl;
    }

    /**
     * @brief 模拟处理函数。
     * @details 通过调用 `shared_from_this()` 安全地获取指向自身的 `std::shared_ptr`，并存入内部向量中。
     * 这样做可以确保对象的生命周期被正确延长，直到内部向量不再持有该指针。
     */
    void
    process() {
        // vec_p_csptest_.emplace_back(this);
        vec_p_csptest_.emplace_back(shared_from_this());
    }

private:
    typedef std::shared_ptr<CSPTEST> p_csptest_; ///< CSPTEST 的 shared_ptr 类型定义
    std::vector<p_csptest_> vec_p_csptest_;
    ///< 内部持有的自身 shared_ptr 向量，用于演示生命周期管理
};
#endif //MODERN_CPP_SHARED_PTR_HPP
