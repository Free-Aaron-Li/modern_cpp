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
 * @file 5_3_abstract_types.cpp
 * @brief 第 5 章 类：5.3 抽象类型示例实现
 */

module;
#include <iostream>
#include <vector>
#include <memory>
module classes;

/**
 * @brief 5.3 抽象类型相关的命名空间实现
 */
namespace ch5_abstract_types_impl {
    /**
     * @brief 容器接口（抽象类）
     */
    class Container {
    public:
        virtual double& operator[](int) = 0;  // 纯虚函数
        virtual int size() const = 0;         // 纯虚函数
        virtual ~Container() {}               // 虚析构函数
    };

    /**
     * @brief 容器的一个具体实现：Vector_container
     */
    class Vector_container : public Container {
        std::vector<double> v;
    public:
        Vector_container(int s) : v(s) {}
        ~Vector_container() {}

        double& operator[](int i) override { return v[i]; }
        int size() const override { return static_cast<int>(v.size()); }
    };
}

/**
 * @ingroup classes_module_group
 * @brief 5.3 抽象类型入口
 */
auto
tutorial_abstract_types() -> void {
    std::cout << "--- 5.3 Abstract Types ---" << std::endl;
    
    ch5_abstract_types_impl::Vector_container vc(10);
    std::cout << "Vector_container size: " << vc.size() << std::endl;
}
