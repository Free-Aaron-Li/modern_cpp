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
 * @file 4_1_exceptions.cpp
 * @brief 第 4 章 错误处理：4.2 异常处理示例实现
 */

module;
#include <iostream>
#include <stdexcept>

module error_handling;

    /**
     * @brief 4.2 异常：相关实现命名空间
     */
    namespace ch4_exceptions_impl {
        /**
         * @brief 4.2 示例类 Vector：演示越界检查
         */
        class Vector {
        public:
            /**
             * @brief 构造函数
             * @param s 向量大小
             */
            Vector(int s) : elem_{ new double[s] }, sz_{ s } {}

            /**
             * @brief 析构函数，释放内存
             */
            ~Vector() { delete[] elem_; }

            /**
             * @brief 访问指定位置的元素，执行越界检查
             * @param i 索引
             * @return 元素的引用
             * @throws std::out_of_range 如果索引超出范围
             */
            double&
            operator[](int i) {
                if (i < 0 || size() <= i) { throw std::out_of_range{ "Vector::operator[]" }; }
                return elem_[i];
            }

            /**
             * @brief 获取向量大小
             * @return 向量维度
             */
            int
            size() const {
                return sz_;
            }

        private:
            double* elem_;  ///< 元素数组指针
            int     sz_;    ///< 向量维度
        };

        /**
         * @brief 演示函数：捕获越界异常
         */
        void
        test_out_of_range() {
        Vector v(5);
        try {
            v[10] = 7;  ///< 触发异常
        } catch (const std::out_of_range& err) {
            std::cerr << "Caught expected exception: " << err.what() << std::endl;
        }
    }
}  // namespace ch4_exceptions_impl

/**
 * @ingroup error_handling_module_group
 * @brief 4.2 异常处理入口
 */
void
tutorial_exceptions() {
    std::cout << "--- 4.2 Exceptions ---" << std::endl;
    ch4_exceptions_impl::test_out_of_range();
}
