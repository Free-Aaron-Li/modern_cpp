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
 * @file 3_2_separate_compilation.cpp
 * @brief 第 3 章 模块化：分离编译示例源文件
 */

#include <cmath>

#include "Vector.hpp"
#include "modularity.hpp"

import module_vector; /**< 引入模块 */
// import std;         /**<
// 引入标准库，但是非常抱歉，这仍然是不可靠的，具体查看文档 */

/**
 * @brief 3.2 分离编译相关的内部实现
 */
namespace ch3_separate_compilation_impl {
    /**
     * @brief 计算向量中所有元素平方根的总和（使用头文件方式的 Vector）
     *
     * 遍历向量中的每个元素，对每个元素求平方根后累加，
     * 用于演示传统头文件方式的分离编译。
     * 被 @ref tutorial_separate_compilation 调用。
     *
     * @param v 输入的 Vector 对象（常量引用）
     * @return 返回所有元素平方根的总和
     */
    double
    sqrt_sum(const Vector& v) {
        double sum{ 0 };
        for (int i{ 0 }; i != v.size(); ++i) {
            sum += std::sqrt(v[i]);
        }
        return sum;
    }

    /**
     * @brief 计算向量中所有元素平方根的总和（使用模块化方式的 ModularVector）
     *
     * 遍历向量中的每个元素，对每个元素求平方根后累加，
     * 用于演示 C++20 模块化特性的分离编译方式。
     * 被 @ref tutorial_separate_compilation 调用。
     *
     * @param v 输入的 ModularVector 对象（常量引用）
     * @return 返回所有元素平方根的总和
     */
    double
    module_sqrt_sum(const ModularVector& v) {
        double sum{ 0 };
        for (int i{ 0 }; i != v.size(); ++i) {
            sum += std::sqrt(v[i]);
        }
        return sum;
    }
}  // namespace ch3_separate_compilation_impl


/**
 * @ingroup modularity_group
 * @brief 3.2 分离编译：演示头文件与源文件的分离
 *
 * 介绍 C++ 如何通过头文件 (.hpp/.h) 包含接口声明，
 * 以及源文件 (.cpp) 包含具体实现，从而支持分离编译。
 * 涵盖：`ch3_separate_compilation_impl::Vector` 及
 * `ch3_separate_compilation_impl::ModularVector`
 *
 * 对应《C++ 之旅》3.2 节。
 */
void
tutorial_separate_compilation() {
    using namespace ch3_separate_compilation_impl;
    std::cout << "--- 3.2 Separate Compilation ---" << std::endl;

    Vector v(6);
    for (int i = 0; i < v.size(); ++i) {
        v[i] = i * i;
    }

    ModularVector mv(6);
    for (int i = 0; i < mv.size(); ++i) {
        mv[i] = i * i;
    }

    std::cout << "Sum of square of [0, 6) is: " << sqrt_sum(v) << std::endl;
    std::cout << "[Using module] Sum of square of [0, 6) is: "
              << module_sqrt_sum(mv) << std::endl;
}
