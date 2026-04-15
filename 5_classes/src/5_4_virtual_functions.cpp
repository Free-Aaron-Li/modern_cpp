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
 * @file 5_4_virtual_functions.cpp
 * @brief 第 5 章 类：5.4 虚函数示例实现
 */

module;
#include <iostream>
module classes;

/**
 * @brief 5.4 虚函数相关的命名空间实现
 */
namespace ch5_virtual_functions_impl {
    class Shape {
    public:
        virtual void draw() const = 0; // 纯虚函数
        virtual ~Shape() {}
    };

    class Circle : public Shape {
    public:
        void draw() const override { std::cout << "Drawing a Circle" << std::endl; }
    };

    class Square : public Shape {
    public:
        void draw() const override { std::cout << "Drawing a Square" << std::endl; }
    };

    void rotate(const Shape& s) {
        s.draw(); // 通过虚函数表进行动态绑定
    }
}

/**
 * @ingroup classes_module_group
 * @brief 5.4 虚函数入口
 */
auto
tutorial_virtual_functions() -> void {
    std::cout << "--- 5.4 Virtual Functions ---" << std::endl;
    
    ch5_virtual_functions_impl::Circle c;
    ch5_virtual_functions_impl::Square s;

    ch5_virtual_functions_impl::rotate(c);
    ch5_virtual_functions_impl::rotate(s);
}
