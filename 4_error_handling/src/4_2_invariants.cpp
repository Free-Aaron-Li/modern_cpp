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
 * @file 4_2_invariants.cpp
 * @brief 第 4 章 错误处理：4.3 约束条件（不变式）示例实现
 */

module;
#include <iostream>
#include <stdexcept>

module error_handling;

    /**
     * @brief 4.3 约束条件：相关实现命名空间
     */
    namespace ch4_invariants_impl {
        /**
         * @brief 4.3 示例类 Vector：带有不变式检查
         */
        class Vector {
        public:
            /**
             * @brief 构造函数，包含不变式检查
             * @param s 向量大小
             * @throws std::length_error 如果大小为负数
             */
            Vector(int s) {
                if (s < 0) { throw std::length_error{ "Vector constructor: negative size" }; }
                elem_ = new double[s];
                sz_   = s;
            }

            /**
             * @brief 析构函数，释放资源
             */
            ~Vector() { delete[] elem_; }

            /**
             * @brief 下标运算符，不包含边界检查（演示核心不变式）
             * @param i 索引
             * @return 元素的引用
             */
            double&
            operator[](int i) {
                return elem_[i];
            }

            /**
             * @brief 获取当前大小
             * @return 向量大小
             */
            int
            size() const {
                return sz_;
            }

        private:
            double* elem_;  ///< 指向元素的指针
            int     sz_;    ///< 向量的大小
        };

    /**
     * @brief 演示函数：构造函数中的不变式检查
     */
    void
    test_invariants() {
        try {
            Vector v(-27);  ///< 触发长度错误
        } catch (const std::length_error& err) {
            std::cerr << "Caught invariant error: " << err.what() << std::endl;
        } catch (const std::bad_alloc&) {
            std::cerr << "Memory allocation failed" << std::endl;
        }
    }
}  // namespace ch4_invariants_impl

/**
 * @ingroup error_handling_module_group
 * @brief 4.3 约束条件入口
 */
void
tutorial_invariants() {
    std::cout << "--- 4.3 Constraints (Invariants) ---" << std::endl;
    ch4_invariants_impl::test_invariants();
}
