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

#include <map>

#include "modularity.hpp"

using namespace std;

namespace ch3_args_and_returns_impl {
    /**
     * @brief 演示不同的参数传递方式
     *
     * 在 @ref tutorial_function_arguments_and_return_values 中被演示使用。
     *
     * @param v 传值 (Copy)
     * @param r 传引用 (Reference)
     * @param cr 传常量引用 (Const Reference)
     */
    void
    test_argument_passing(int v, int& r, const int& cr) {
        v = 100;  // 仅修改局部副本
        r = 200;  // 修改调用者的变量
        // cr = 300;  // 错误：不可修改常量引用
        (void) cr;
    }

    /**
     * @brief 简单的条目结构
     *
     * 在 @ref tutorial_function_arguments_and_return_values 中被演示使用。
     */
    struct Entry {
        string name;
        int    value;
    };

    /**
     * @brief 演示返回多个值（通过结构体和结构化绑定）
     *
     * 在 @ref tutorial_function_arguments_and_return_values 中被演示使用。
     */
    Entry
    get_entry() {
        return { "example", 42 };
    }

    /**
     * @brief 演示结构化绑定 (Structured Bindings)
     *
     * 在 @ref tutorial_function_arguments_and_return_values 中被演示使用。
     */
    void
    test_structured_bindings() {
        auto [n, v] = get_entry();
        cout << "Structured binding: name = " << n << ", value = " << v << endl;

        map<string, int> m = { { "a", 1 }, { "b", 2 } };
        for (const auto& [key, val]: m) {
            cout << "Key: " << key << ", Value: " << val << endl;
        }
    }
}  // namespace ch3_args_and_returns_impl

/**
 * @ingroup modularity_group
 * @brief 3.4 函数参数与返回值：演示参数传递与结构化绑定
 *
 * 对应《C++ 之旅》3.4 节。
 */
void
tutorial_function_arguments_and_return_values() {
    using namespace ch3_args_and_returns_impl;
    cout << "--- 3.4 Function Arguments and Return Values ---" << endl;

    int x = 1, y = 2, z = 3;
    cout << "Before: x=" << x << ", y=" << y << ", z=" << z << endl;
    test_argument_passing(x, y, z);
    cout << "After:  x=" << x << ", y=" << y << ", z=" << z << endl;

    test_structured_bindings();
}
