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
 * @file 5_1_introduction.cpp
 * @brief 第 5 章 类：5.1 引言示例实现
 */

module;
#include <iostream>
module classes;

/**
 * @brief 5.1 引言相关的命名空间实现
 */
namespace ch5_introduction_impl {
    /**
     * @brief 简单的类定义，演示类的基本思想
     * 类是用户定义的类型，用于表示程序中的概念。
     */
    class X {
    public:
        explicit
        X(const int v) :
            val_(v) {}

        [[nodiscard]] auto
        get() const -> int { return val_; }

    private:
        int val_;
    };
}

/**
 * @ingroup classes_module_group
 * @brief 5.1 引言入口
 */
auto
tutorial_introduction() -> void {
    std::cout << "--- 5.1 Introduction ---" << std::endl;
    const ch5_introduction_impl::X x{ 42 };
    std::cout << "Class X value: " << x.get() << std::endl;
}
