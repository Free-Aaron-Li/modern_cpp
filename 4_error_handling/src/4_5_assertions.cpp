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
 * @file 4_5_assertions.cpp
 * @brief 第 4 章 错误处理：4.5 断言示例实现
 */

module;
#include <cassert>
#include <iostream>

module error_handling;

    /**
     * @brief 断言相关的命名空间实现
     */
    namespace ch4_assertions_impl {
    /**
     * @brief 演示运行期断言：assert
     *
     * assert 主要用于调试阶段，检查那些“绝对不应该发生”的情况。
     * 当定义了 NDEBUG 宏时，assert 会被编译器忽略。
     */
    void
    test_runtime_assert() {
        int x = 10;
        assert(x > 0);  ///< 如果条件为假，程序将终止并报错
        std::cout << "Runtime assertion passed." << std::endl;
    }

    /**
     * @brief 演示静态断言：static_assert
     *
     * static_assert 在编译期验证条件，不符合条件将导致编译失败。
     */
    void
    test_static_assert() {
        constexpr double speed_of_light = 299792458;
        static_assert(speed_of_light > 0, "Speed of light must be positive");
        std::cout << "Static assertion passed (verified at compile time)." << std::endl;
    }
}  // namespace ch4_assertions_impl

/**
 * @ingroup error_handling_module_group
 * @brief 4.5 断言入口
 */
void
tutorial_assertions() {
    std::cout << "--- 4.5 Assertions ---" << std::endl;
    ch4_assertions_impl::test_runtime_assert();
    ch4_assertions_impl::test_static_assert();
}
