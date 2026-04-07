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
 * @file Vector.cpp
 * @brief 第 3 章 模块化：Vector 类的实现（分离编译示例）
 */

#include "Vector.hpp"

/**
 * @brief 3.2 分离编译相关的内部实现
 */
namespace ch3_separate_compilation_impl {
    /**
     * @brief 构造函数实现
     * @param s 向量的大小
     */
    Vector::Vector(int s) : elem_{ new double[s] }, sz_{ s } {}


    /**
     * @brief 下标运算符重载实现
     * @param i 索引位置
     * @return 返回第 i 个元素的引用（可修改）
     */
    double&
    Vector::operator[](int i) const {
        return elem_[i];
    }

    /**
     * @brief 获取向量大小
     * @return 返回向量中元素的个数
     */
    int
    Vector::size() const {
        return sz_;
    }
}  // namespace ch3_separate_compilation_impl
