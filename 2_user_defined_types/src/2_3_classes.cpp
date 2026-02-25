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

#include "user_defined_types.hpp"

using namespace std;

/**
 * @brief 2.3 类相关的内部实现
 */
namespace ch2_classes_impl {

    /**
     * @brief 简单的向量类
     *
     * 在 @ref tutorial_classes 中被演示使用。
     */
    class Vector {
    public:
        /**
         * @brief 构造函数
         * @param s 元素数量
         *
         * 在初始化类对象时一定会被调用，因此定义一个构造函数可以消除类变量未初
         * 始化造成的问题。
         */
        Vector(int s) : elem{ new double[s] }, sz{ s } {}

        /**
         * @brief 通过下标访问元素
         * @param i 索引
         * @return 元素的引用（从而可读可写）
         */
        double&
        operator[](int i) {
            return elem[i];
        }

        /**
         * @brief 获取向量大小
         * @return 向量中的元素数量
         */
        int
        size() {
            return sz;
        }

    private:
        double* elem; /**< 指向元素的指针 */
        int     sz;   /**< 元素的数量 */
    };

    /**
     * @brief 从标准输入读取元素并计算总和
     * @param s 元素数量
     * @return 元素的总和
     *
     * 被 @ref tutorial_classes 调用。
     */
    double
    read_and_sum(int s) {
        Vector v(s);
        for (int i = 0; i != s; ++i) cin >> v[i];

        double sum = 0;
        for (int i = 0; i != s; ++i) sum += v[i];
        return sum;
    }

}  // namespace ch2_classes_impl

/**
 * @ingroup user_defined_types_group
 * @brief 2.3 类：演示 class 的封装与接口设计
 *
 * 介绍通过 public 和 private 关键字实现的访问控制，以及成员函数的定义。
 * 涵盖类：`Vector`；涵盖函数：`read_and_sum()`
 *
 * 对应《C++ 之旅》2.3 节。
 */
void
tutorial_classes() {
    using namespace ch2_classes_impl;
    std::cout << "--- 2.3 Classes ---" << std::endl;
    read_and_sum(6);
}
