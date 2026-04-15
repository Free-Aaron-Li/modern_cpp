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
 * @file 5_5_class_hierarchies.cpp
 * @brief 第 5 章 类：5.5 类层次结构示例实现
 */

module;
#include <iostream>
#include <vector>
#include <memory>
module classes;

/**
 * @brief 5.5 类层次结构相关的命名空间实现
 */
namespace ch5_class_hierarchies_impl {
    class Shape {
    public:
        virtual void draw() const = 0;
        virtual ~Shape() {}
    };

    class Circle : public Shape {
    public:
        void draw() const override { std::cout << "Circle::draw" << std::endl; }
    };

    /**
     * @brief 演示类层次中的进一步派生
     */
    class Smiley : public Circle {
    public:
        void draw() const override {
            Circle::draw();
            std::cout << "  Smiley::draw (adding a smile)" << std::endl;
        }
    };
}

/**
 * @ingroup classes_module_group
 * @brief 5.5 类层次结构入口
 */
auto
tutorial_class_hierarchies() -> void {
    std::cout << "--- 5.5 Class Hierarchies ---" << std::endl;
    
    std::vector<std::unique_ptr<ch5_class_hierarchies_impl::Shape>> shapes;
    shapes.push_back(std::make_unique<ch5_class_hierarchies_impl::Circle>());
    shapes.push_back(std::make_unique<ch5_class_hierarchies_impl::Smiley>());

    for (const auto& s : shapes) {
        s->draw();
    }
}
