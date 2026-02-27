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
 * @file 3_4_function_arguments_and_return_values.cpp
 * @brief 第 3 章 模块化：函数参数与返回值示例源文件
 */

#include "modularity.hpp"


/**
 * @brief 3.4 函数参数与返回值相关的内部实现
 */
namespace ch3_args_and_returns_impl {

    /**
     * @brief 计算向量中元素的和
     *
     * 该函数演示了常量引用参数的传递。
     *
     * @param v 包含整数的常量引用向量
     * @return 元素的总和
     */
    int
    sum(const std::vector<int>& v) {
        /** 以引用方式传入，考虑到 vector 对象很大情况。
            同时本函数并没有修改参数的理由，出于安全考虑以常量引用方式传入。*/
        int s{ 0 };
        for (const int i: v) { s += i; }
        return s;
    }

    /**
     * @brief 演示不同的参数传递方式
     *
     * 在 @ref tutorial_function_arguments_and_return_values 中被演示使用。
     *
     * @param v 传值（Copy）
     * @param r 传引用（Reference）
     * @param cr 传常量引用（Const Reference）
     */
    void
    test_argument_passing(int v, int& r, const int& cr) {
        v = 100;  // 仅修改局部副本
        r = 200;  // 修改调用者的变量
        // cr = 300;  // 错误：不可修改常量引用
        (void) cr;
    }

    /**
     * @brief 简单的条目结构
     *
     * 在 @ref tutorial_function_arguments_and_return_values 中被演示使用。
     */
    struct Entry {
        std::string name;
        int         value;
    };

    /**
     * @brief 演示返回多个值（通过结构体和结构化绑定）
     *
     * 在 @ref tutorial_function_arguments_and_return_values 中被演示使用。
     */
    Entry
    get_entry() {
        return { "example", 42 };
    }

    /**
     * @brief 演示结构化绑定（Structured Bindings）
     *
     * 在 @ref tutorial_function_arguments_and_return_values 中被演示使用。
     */
    void
    test_structured_bindings() {
        auto [n, v] = get_entry();
        std::cout << "Structured binding: name = " << n << ", value = " << v
                  << std::endl;

        std::map<std::string, int> m = { { "a", 1 }, { "b", 2 } };
        for (const auto& [key, val]: m) {
            std::cout << "Key: " << key << ", Value: " << val << std::endl;
        }
    }
}  // namespace ch3_args_and_returns_impl

/**
 * @ingroup modularity_group
 * @brief 3.4 函数参数与返回值：演示参数传递与结构化绑定
 *
 * 对应《C++ 之旅》3.4 节。
 */
void
tutorial_function_arguments_and_return_values() {
    using namespace ch3_args_and_returns_impl;
    std::cout << "--- 3.4 Function Arguments and Return Values ---"
              << std::endl;

    const std::vector<int> fib{ 1, 2, 3, 5, 8, 13, 21 };
    const int              res = sum(fib);
    std::cout << "Sum of Fibonacci sequence: " << res << std::endl;


    int x = 1, y = 2, z = 3;
    std::cout << "Before: x=" << x << ", y=" << y << ", z=" << z << std::endl;
    test_argument_passing(x, y, z);
    std::cout << "After:  x=" << x << ", y=" << y << ", z=" << z << std::endl;

    test_structured_bindings();
}
