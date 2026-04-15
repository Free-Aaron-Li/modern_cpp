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
 * @file 4_2_exceptions.cpp
 * @brief 第 4 章 错误处理：4.2 异常处理示例实现
 */

module; /** 全局模块片段，定义旧式头文件、宏等 */
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
        explicit
        Vector(const int s) :
            elem_{ new double[s] }, sz_{ s } {}

        /**
         * @brief 析构函数，释放内存
         */
        ~Vector() { delete[] elem_; }

        /**
         * @brief 访问指定位置的元素，执行越界检查
         * @param i 索引
         * @return 元素的引用
         * @throws std::out_of_range 如果索引超出范围
         * @details 💡：对象只读时，不保证深度只读，
         * 外部仍然可以通过返回值引用修改底层数据，最合理的方式是编写：
         * - 非 const 版本：返回 double&
         * - const 版本：返回 const double&
         * 现在编写的方式是不完整的，仅做学习使用。
         *
         * throw 指令创建的 out_of_range 类型的异常，将异常的控制权转移给
         * 直接或间接调用 Vector::operator[]() 函数的用户。编译器在实现上
         * 需要通过 @a 回溯函数调用栈并找到调用者的上下文，而在此过程中可能
         * 会调用析构函数。
         */
        auto
        operator[](const int i) const -> double& {
            if (i < 0 || size() <= i) {
                throw std::out_of_range{ "Vector::operator[]" };
            }
            return elem_[i];
        }

        /**
         * @brief 获取向量大小
         * @return 向量维度
         */
        [[nodiscard]] auto /** nodiscard 的含义是这个返回值不应该被忽略 */
        size() const -> int { return sz_; }

    private:
        double* elem_; ///< 元素数组指针
        int     sz_;   ///< 向量维度
    };

    /**
     * @brief 演示函数：捕获越界异常
     */
    auto
    test_out_of_range() {
        const Vector v(5);
        try {          /** 异常处理机制 */
            v[10] = 7; /** 触发异常 */
        } catch (const std::out_of_range& err) {
            std::cerr << "Caught expected exception: " << err.what()
                    << std::endl;
        }
    }
} // namespace ch4_exceptions_impl

/**
 * @ingroup error_handling_module_group
 * @brief 4.2 异常处理入口
 */
auto
tutorial_exceptions() -> void {
    std::cout << "--- 4.2 Exceptions ---" << std::endl;
    ch4_exceptions_impl::test_out_of_range();
}
