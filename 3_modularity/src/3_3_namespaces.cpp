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
 * @file 3_3_namespaces.cpp
 * @brief 第 3 章 模块化：命名空间示例源文件
 */

#include "modularity.hpp"

/**
 * @brief 3.3 命名空间相关的内部实现
 */
namespace ch3_namespaces_impl {
    /**
     * @brief 简单的复数类，用于演示命名空间
     *
     * 在 @ref tutorial_namespaces 中被演示使用。
     */
    class complex {
    public:
        /**
         * @brief 构造函数
         * @param r 实部
         * @param i 虚部
         */
        complex(double r, double i) : re{ r }, im{ i } {}

        /**
         * @brief 获取实部
         * @return 实部值
         */
        double
        real() const {
            return re;
        }

        /**
         * @brief 获取虚部
         * @return 虚部值
         */
        double
        imag() const {
            return im;
        }

    private:
        double re, im;
    };

    /**
     * @brief 复数加法运算符重载
     * @param a 第一个复数
     * @param b 第二个复数
     * @return 两个复数之和
     */
    complex
    operator+(complex a, complex b) {
        return { a.real() + b.real(), a.imag() + b.imag() };
    }

    /**
     * @brief 演示命名空间使用的内部入口函数
     * @return 状态码
     */
    int
    main();
}  // namespace ch3_namespaces_impl

/**
 * @brief 演示命名空间内部的主函数
 * @return 状态码
 */
int
ch3_namespaces_impl::main() {
    complex z{ 1, 2 };
    complex z2{ 3, 4 };
    complex z3 = z + z2;

    std::cout << "z3 = (" << z3.real() << ", " << z3.imag() << "i)"
              << std::endl;

    return 0;
}

/**
 * @ingroup modularity_group
 * @brief 3.3 命名空间：演示 namespace 的定义与使用
 *
 * 介绍如何使用命名空间来组织代码，避免命名冲突。
 *
 * 对应《C++ 之旅》3.3 节（C++20 后为 3.3，之前版本可能不同）。
 */
void
tutorial_namespaces() {
    std::cout << "--- 3.3 Namespaces ---" << std::endl;
    ch3_namespaces_impl::main();
}
