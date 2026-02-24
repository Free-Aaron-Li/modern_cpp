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

#ifndef MODERN_CPP_VECTOR_HPP
#define MODERN_CPP_VECTOR_HPP

/**
 * @file Vector.hpp
 * @brief 演示分离编译的 Vector 类声明
 */

namespace ch3_separate_compilation_impl {
    /**
     * @brief 简单的向量类，用于演示分离编译。
     */
    class Vector {
    public:
        /**
         * @brief 使用给定大小构造（不初始化元素）。
         * @param s 元素个数
         */
        Vector(int s);
        /**
         * @brief 下标访问（返回可修改引用）。
         * @param i 索引
         * @return 第 i 个元素引用
         */
        double&
        operator[](int i);
        /**
         * @brief 返回元素个数。
         */
        int
        size();

    private:
        double* elem;  ///< 指向元素的指针
        int     sz;    ///< 元素个数
    };
}  // namespace ch3_separate_compilation_impl

#endif  // MODERN_CPP_VECTOR_HPP
