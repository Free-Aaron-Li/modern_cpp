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

/**
 * @brief 第1章 基础示例程序入口
 */
int
main() {
    std::cout << "========== Modern CPP: Chapter 1 Basics ==========" << std::endl;

    tutorial_program();
    tutorial_functions();
    tutorial_types();
    tutorial_constants();
    tutorial_pointers();
    tutorial_tests();

    std::cout << "==================================================" << std::endl;
    return 0;
}
