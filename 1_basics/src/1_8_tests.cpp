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

#include "basics.hpp"

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
 * @brief 获取用户输入并返回布尔值（使用 switch 语句）
 * @return 如果用户输入 'y' 返回 true，否则返回 false
 */
bool
accept2() {
    cout << "Do you want to proceed (y or n)?\n"; /* 输出提问 */
    char answer{ 0 };                             /* 初始化为用户不可能输入值 */
    cin >> answer;                                /* 读取用户输入 */

    switch (answer) {
        case 'y': return true;
        case 'n': return false;
        default: cout << "I'll take that for a no.\n";
            return false;
    }
}

/**
 * @brief 简单的点坐标结构体
 */
struct Point {
    int x_; ///< x 轴坐标
    int y_; ///< y 轴坐标
};

/**
 * @brief 执行连续动作的演示函数
 * 
 * 演示了循环（while）、字符串读取（cin）以及在循环体内更新坐标点。
 * 支持 'u' (up), 'n' (north), 'r' (right), 'e' (east) 等输入字符。
 */
void
action() {
    while (true) {
        cout <<
                "enter action (u:up, n:up, r:right, e:right, other:freeze, q:quit):\n";
        /* 请求动作 */
        string act;
        cin >> act; /* 将字符读到字符串 */
        if (act == "q") break;
        Point delta{ 0, 0 };
        for (char ch: act) {
            switch (ch) {
                case 'u':
                case 'n': ++delta.y_;
                    break;
                case 'r':
                case 'e': ++delta.x_;
                    break;
                default: cout << "I freeze!\n";
            }
        }
        cout << "delta:" << delta.x_ << "," << delta.y_ << endl;
    }
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
    // accept();
    accept2();
    action();
}
