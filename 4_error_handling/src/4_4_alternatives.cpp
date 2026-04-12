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
 * @file 4_4_alternatives.cpp
 * @brief 第 4 章 错误处理：4.4 错误处理的其他替代方式示例实现
 */

module;
#include <cmath>
#include <iostream>
#include <optional>
#include <system_error>

module error_handling;

/**
 * @brief 4.4 错误替代方案：相关实现命名空间
 */
namespace ch4_alternatives_impl {
    /**
     * @brief 使用错误码的替代方式
     * @param x 输入值
     * @param ec 错误码引用
     * @return 计算结果
     */
    double
    safe_sqrt(double x, std::error_code& ec) {
        if (x < 0) {
            ec = std::make_error_code(std::errc::invalid_argument);
            return 0;
        }
        return std::sqrt(x);
    }

    /**
     * @brief 使用 std::optional 的替代方式
     * @param x 输入值
     * @return 包含结果的 optional，若输入非法则返回 std::nullopt
     */
    std::optional<double>
    safe_sqrt_opt(double x) {
        if (x < 0) { return std::nullopt; }
        return std::sqrt(x);
    }

    /**
     * @brief 演示函数：非异常错误处理方式
     */
    void
    test_alternatives() {
        // 1. 错误码方式
        std::error_code ec;
        double          res1 = safe_sqrt(-1.0, ec);

        // 2. std::optional 方式
        auto res2 = safe_sqrt_opt(-1.0);
    }
}  // namespace ch4_alternatives_impl

/**
 * @ingroup error_handling_module_group
 * @brief 4.4 错误处理的其他替代方式入口
 */
void
tutorial_error_handling_alternatives() {
    std::cout << "--- 4.4 Error Handling Alternatives ---" << std::endl;
    ch4_alternatives_impl::test_alternatives();
}
