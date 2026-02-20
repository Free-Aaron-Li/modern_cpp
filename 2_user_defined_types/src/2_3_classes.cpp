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

/* 匿名 namespace 里名字具备内部链接，等价于“只在当前.cpp（当前翻译单元）中
 * 可见/可链接。
 * 不将 tutorial_classes 包含在内原因在于该函数是对外提供的入口函数，需要外部
 * 链接。这是一个常见的组织方式：内部实现隐藏 + 外部接口暴露。
 */
namespace {

    class Vector {
    public:
        /* 构造函数在初始化类对象时一定会被调用，因此定义一个构造函数
         * 可以消除类变量未初始化造成的问题。
         */
        Vector(int s) : elem{ new double[s] }, sz{ s } {} /* 构造一个 Vector */

        double& /* 返回值为引用，从而可读可写 */
        operator[](int i) {
            return elem[i];
        } /* 通过下标访问元素 */

        int
        size() {
            return sz;
        }

    private:
        double* elem;
        int sz;
    };

    /**
     * @brief 从标准输入读取元素并计算总和
     * @param s 元素数量
     * @return 元素的总和
     */
    double
    read_and_sum(int s) {
        Vector v(s);
        for (int i = 0; i != s; ++i) cin >> v[i];

        double sum = 0;
        for (int i = 0; i != s; ++i) sum += v[i];
        return sum;
    }

}  // namespace

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
    std::cout << "--- 2.3 Classes ---" << std::endl;
    read_and_sum(6);
}
