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

#include "1_basics.hpp"

using namespace std;

/**
 * @brief 演示数组遍历（范围 for）
 */
void
print() {
    int v[]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (auto x: v) { /* 通过 x 遍历 v 中的每个元素 */
        cout << x << "\n";
    }

    for (auto x: { 10, 21, 32, 43, 54, 65 }) {
        cout << x << "\n";
    }
}

/**
 * @brief 演示通过引用遍历数组并累加
 */
void
increment() {
    int v[]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int res{ 0 };
    for (auto& x: v) { /* 通过引用 x 遍历 v 中的每个元素，节约资源 */
        res += x;
    }
    cout << "total of v is: " << res << "\n";
}

/**
 * @ingroup basics_group
 * @brief 演示指针、数组与引用
 * 
 * 对应《C++ 之旅》1.7 节
 */
void
tutorial_pointers() {
    cout << "--- 1.7 Pointers, Arrays, and References ---" << endl;
    print();
    increment();
    [[maybe_unused]] double* pd{ nullptr };
    [[maybe_unused]] vector<int>* pl{ nullptr }; /* 指向空指针 */
    // int x = nullptr; /* 错误：不能在初始化时将‘std::nullptr_t’转换为‘int’ */
}
