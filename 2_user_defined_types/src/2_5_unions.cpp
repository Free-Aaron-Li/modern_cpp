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
 * @file 2_5_unions.cpp
 * @brief 第 2 章 用户自定义类型：联合（union）示例源文件
 */

#include "user_defined_types.hpp"

using namespace std;

/**
 * @brief 2.5 联合相关的内部实现
 */
namespace ch2_unions_impl {
    /**
     * @brief 表示 Entry 中存储的数据类型
     *
     * 在 @ref tutorial_unions 中被演示使用。
     */
    enum class Type { ptr, num }; /* Type 可以是 ptr 或 num */

    /**
     * @brief 可变类型值的联合体
     *
     * 在 @ref tutorial_unions 中被演示使用。
     *
     * @details 联合体（union）允许在同一块内存中存储不同类型的数据，
     * 但同一时刻只能使用其中一个成员。这里定义了指针和整数两种类型，
     * 通过配合 Type 枚举和 Entry 结构体来跟踪当前存储的实际类型。
     *
     * @note 联合体的大小等于其最大成员的大小。使用时需要程序员手动
     * 维护类型信息，否则容易引发未定义行为。现代 C++ 推荐使用
     * std::variant 作为类型安全的替代方案。
     */
    union Value {
        int* p; /**< 指针类型成员：指向 int 的指针 */
        int  i; /**< 整数类型成员：int 值 */
    };

    /**
     * @brief 包含名字与可变类型值的实体结构
     *
     * 在 @ref tutorial_unions 中被演示使用。
     */
    struct Entry {
        std::string        name; /**< 名字 */
        Type               t;    /**< 当前存储的类型 */
        Value              v;    /**< 存储的值 */
        variant<int*, int> v1;   /**< 存储的值（替代方案）*/
    };

    /**
     * @brief 打印 Entry 实体的内容（使用 union 版本）
     *
     * 在 @ref tutorial_unions 中被演示使用。
     *
     * @param e 待打印的 Entry 引用
     * @details 根据 Type 枚举值判断当前使用的联合体成员，
     * 然后输出相应的值。这种方式需要手动维护类型信息。
     */
    void
    print_entry(const Entry& e) {
        /* 根据类型标记判断当前存储的是指针还是整数 */
        if (e.t == Type::ptr)
            std::cout << e.name << ": " << e.v.p << std::endl;
        else
            std::cout << e.name << ": " << e.v.i << std::endl;
    }

    /**
     * @brief 打印 Entry 实体的内容（使用 std::variant 版本）
     *
     * 在 @ref tutorial_unions 中被演示使用。
     *
     * @param e 待打印的 Entry 引用
     * @details 使用 std::variant 的类型安全机制，通过 holds_alternative
     * 检查当前存储的类型，并使用 get 获取相应的值。这是现代 C++ 推荐
     * 的做法，无需手动维护类型标记。
     */
    void
    print_entry1(const Entry& e) {
        /* 使用 std::variant 的类型安全检查 */
        if (holds_alternative<int>(e.v1)) {
            /* 当前存储的是 int 类型 */
            cout << get<int>(e.v1) << endl;
        } else {
            /* 当前存储的是 int* 类型 */
            cout << get<int*>(e.v1) << endl;
        }
    }


}  // namespace ch2_unions_impl

/**
 * @ingroup user_defined_types_group
 * @brief 2.5 联合：演示 union 的内存布局与应用
 *
 * 展示如何在同一块内存区域存储不同类型的变量，以及它的风险与现代替代方案。
 *
 * 对应《C++ 之旅》2.5 节。
 */
void
tutorial_unions() {
    using namespace ch2_unions_impl;
    std::cout << "--- 2.5 Unions ---" << std::endl;
}
