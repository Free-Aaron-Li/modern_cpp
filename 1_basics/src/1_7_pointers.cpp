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
 * @ingroup basics_group
 * @brief 演示指针、数组与引用
 * 
 * 对应《C++ 之旅》1.7 节
 */
void
tutorial_pointers() {
    cout << "--- 1.7 Pointers, Arrays, and References ---" << endl;

    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // 数组

    for (auto x: v) { // 范围 for 循环 (拷贝)
        cout << x << " ";
    }
    cout << endl;

    for (auto &x: v) { // 范围 for 循环 (引用)
        x += 1;
    }

    int *p = &v[3]; // 指针
    cout << "p points to: " << *p << endl;

    int &r = v[4]; // 引用
    r = 100;
    cout << "v[4] is now: " << v[4] << endl;
}