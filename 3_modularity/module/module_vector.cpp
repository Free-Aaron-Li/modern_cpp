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
 * @file module_vector.cpp
 * @brief 第 3 章 模块化：模块化向量类（C++20 module）示例实现
 */

export module module_vector;

/**
 * @brief 3.2 分离编译相关的内部实现
 */
namespace ch3_separate_compilation_impl {
    /**
     * @brief 模块化向量类，用于演示 C++20 模块特性
     *
     * 这是一个简单的动态数组封装类，通过模块导出供其他翻译单元使用。
     * 在 @ref tutorial_separate_compilation 中被演示使用。
     */
    export class ModularVector {
    public:
        /**
         * @brief 构造函数，创建指定大小的向量
         * @param s 向量的大小（元素个数）
         */
        ModularVector(int s);

        /**
         * @brief 下标运算符重载，访问指定位置的元素
         * @param i 元素索引
         * @return 返回第 i 个元素的引用（可修改）
         */
        double&
        operator[](int i) const;

        /**
         * @brief 获取向量大小
         * @return 返回向量中元素的个数
         */
        int
        size() const;

    private:
        double* elem_;  ///< 指向元素数组的指针
        int     sz_;    ///< 向量的大小（元素个数）
    };

    /**
     * @brief 构造函数实现，分配指定大小的内存空间
     * @param s 向量大小
     */
    ModularVector::ModularVector(int s) : elem_{ new double[s] }, sz_{ s } {}

    /**
     * @brief 下标运算符实现，返回指定位置元素的引用
     * @param i 元素索引
     * @return 第 i 个元素的引用
     */
    double&
    ModularVector::operator[](int i) const {
        return elem_[i];
    }

    /**
     * @brief 获取向量大小的实现
     * @return 向量中元素的个数
     */
    int
    ModularVector::size() const {
        return sz_;
    }

    /**
     * @brief 相等运算符重载，比较两个向量是否相等
     *
     * 两个向量相等的条件：
     * 1. 大小相同
     * 2. 对应位置的所有元素都相等
     *
     * @param lhs 左操作数向量
     * @param rhs 右操作数向量
     * @return 如果两个向量相等返回 true，否则返回 false
     */
    export bool
    operator==(const ModularVector& lhs, const ModularVector& rhs) {
        if (lhs.size() != rhs.size()) { return false; }
        for (int i{ 0 }; i < lhs.size(); ++i) {
            if (lhs[i] != rhs[i]) { return false; }
        }
        return true;
    }
}  // namespace ch3_separate_compilation_impl
