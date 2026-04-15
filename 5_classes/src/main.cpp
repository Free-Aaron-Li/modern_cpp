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
 * @file main.cpp
 * @brief 第 5 章 类主入口文件
 */

import classes;
#include <iostream>

/**
 * @brief 第 5 章 类主入口函数
 * @return 程序退出状态码
 */
int
main() {
    std::cout << "--- Chapter 5: Classes ---" << std::endl;

    tutorial_introduction();
    tutorial_concrete_types();
    tutorial_abstract_types();
    tutorial_virtual_functions();
    tutorial_class_hierarchies();

    return 0;
}
