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
 * @brief 获取用户输入并返回布尔值
 * @return 如果用户输入 'y' 返回 true，否则返回 false
 */
bool
accept() {
    cout << "Do you want to proceed (y or n)?\n";
    char answer = 0;
    cin >> answer;

    if (answer == 'y') return true;
    return false;
}

/**
 * @ingroup basics_group
 * @brief 演示条件判断与循环
 * 
 * 对应《C++ 之旅》1.8 节
 */
void
tutorial_tests() {
    cout << "--- 1.8 Tests ---" << endl;

    int x = 10;
    if (x > 0) {
        cout << "x is positive" << endl;
    } else if (x < 0) {
        cout << "x is negative" << endl;
    } else {
        cout << "x is zero" << endl;
    }

    // Switch 示例
    switch (x) {
        case 0: cout << "zero" << endl;
            break;
        case 10: cout << "ten" << endl;
            break;
        default: cout << "something else" << endl;
            break;
    }
}