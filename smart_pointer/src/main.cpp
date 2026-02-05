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
 * @brief 程序入口点
 * @details 演示 RAII 手法的基本使用。通过一个管理类接管裸指针，
 * 展示在对象超出作用域时如何自动触发资源回收。
 */

#include "sp.hpp"
#include "raii.hpp"

/**
 * @brief 主函数
 * @return 程序退出码
 */
int
main() {
    /* 开始演示 RAII 手法 */
    {
        /**
         * @brief 演示步骤：
         * 1. 显式创建一个 RAII_TEST 对象的裸指针。
         * 2. 创建 CRAII 对象 c，并将裸指针传递给它。
         * 3. 当花括号结束，c 离开作用域被销毁，其析构函数负责 delete 裸指针。
         */
        RAII_TEST* p = new RAII_TEST(); /* 创建裸指针 */
        CRAII c(p); /* 使用CRAII管理p */

        /* 
         * 预期输出：
         * raii_test()
         * ~CRAII()
         * ~raii_test()
         */
    }
    return 0;
}
