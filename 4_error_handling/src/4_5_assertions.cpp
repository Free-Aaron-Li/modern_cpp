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
#include <exception>
#include <iostream>
module error_handling;

/**
 * @brief 4.5 断言相关的命名空间实现
 */
namespace ch4_assertions_impl {
    /**
     * @brief 错误动作：定义当断言失败时采取的操作
     */
    enum class ErrorAction {
        ignore,       ///< 忽略：不执行任何操作
        throwing,     ///< 抛出：抛出异常
        terminating,  ///< 终止：调用 std::terminate() 终止程序
        logging       ///< 日志：向标准错误流输出错误信息
    };

    /**
     * @brief 默认错误动作：默认为抛出异常
     */
    constexpr auto default_error_action = ErrorAction::throwing;

    /**
     * @brief 错误码：定义常见的错误类型
     */
    enum class ErrorCode {
        range_error,  ///< 范围错误
        length_error  ///< 长度错误
    };

    /**
     * @brief 错误码对应的描述名称字符串数组
     */
    std::string error_code_name[]{ "range error", "length error" };

    /**
     * @brief 运行时检查断言（expect）
     *
     * @tparam action 错误动作类型，默认为 default_error_action
     * @param cond 检查条件（一个可调用对象）
     * @param x 错误码
     *
     * 该函数使用 if constexpr 进行编译期分支优化，根据 action
     * 的不同采取不同的错误处理策略。
     */
    template<ErrorAction action = default_error_action, class C>
    constexpr auto
    expect(C cond, ErrorCode x) {
        if constexpr (action == ErrorAction::logging) {
            if (!cond()) {
                std::cerr << "expect() failure: " << static_cast<int>(x) << " "
                          << error_code_name[static_cast<int>(x)] << std::endl;
            }
        }
        if constexpr (action == ErrorAction::throwing) {
            if (!cond()) { throw x; }
        }

        if constexpr (action == ErrorAction::terminating) {
            if (!cond()) { std::terminate(); }
        }
    }

    /**
     * @brief 简单的向量类，用于演示断言检查
     */
    class Vector {
    public:
        /**
         * @brief 获取向量大小
         * @return 向量中的元素数量
         */
        [[nodiscard]] auto
        size() const -> int {
            return sz_;
        }

        /**
         * @brief 下标运算符，带范围检查
         * @param i 元素索引
         * @return 对应索引的元素（此处仅演示断言，未实际返回元素）
         *
         * 使用 expect 函数检查索引 i 是否在有效范围 [0, size()) 内。
         */
        auto
        operator[](const int i) const {
            expect([i, this] { return 0 <= i && i < size(); },
                   ErrorCode::range_error);
        }

    private:
        double* elem_{ nullptr };  ///< 指向元素的指针
        int     sz_{ 0 };          ///< 向量大小
    };

    /**
     * @brief 演示运行期断言：assert
     *
     * assert 主要用于调试阶段，检查那些“绝对不应该发生”的情况。
     * 当定义了 NDEBUG 宏时，assert 会被编译器忽略。
     */
    auto
    test_runtime_assert() {
        constexpr int x{ 10 };
        assert(x > 0);  /// 如果条件为假，程序将终止并报错
        /** 报错情况：Assertion failed: (x < 0), function test_runtime_assert,
         * file 4_5_assertions.cpp, line 128. */
        std::cout << "Runtime assertion passed." << std::endl;
    }

    /**
     * @brief 演示静态断言：static_assert
     *
     * static_assert 在编译期验证条件，不符合条件将导致编译失败。
     */
    auto
    test_static_assert() {
        constexpr double speed_of_light = 299792458;
        static_assert(speed_of_light > 0, "Speed of light must be positive");
        std::cout << "Static assertion passed (verified at compile time)."
                  << std::endl;
    }

    /**
     * @brief 演示静态断言： noexcept
     *
     * noexcept 承诺函数不会抛出异常。
     * 如果在 noexcept 函数内抛出异常，程序会调用 std::terminate() 直接中止。
     */
    auto
    test_noexcept() noexcept {
        std::cout << "About to violate noexcept..." << std::endl;
        // throw ErrorCode::range_error;
        /** 报错信息：libc++abi: terminating due to uncaught exception of type
         * ch4_assertions_impl::ErrorCode@error_handling */
    }

    /**
     * @brief 演示程序终止（terminating action）
     *
     * 调用 expect 函数并指定 ErrorAction::terminating 策略。
     * 如果条件不满足，程序将直接调用 std::terminate()。
     */
    auto
    test_expect_termination() {
        std::cout << "Testing expect with ErrorAction::terminating (this will "
                     "stop the program if it fails)..."
                  << std::endl;
        // 若要观察终止行为，请取消下面代码的注释
        // expect<ErrorAction::terminating>([] { return 1 == 2; },
        // ErrorCode::range_error);
    }
}  // namespace ch4_assertions_impl

/**
 * @ingroup error_handling_module_group
 * @brief 4.5 断言入口
 */
auto
tutorial_assertions() -> void {
    std::cout << "--- 4.5 Assertions ---" << std::endl;
    ch4_assertions_impl::test_runtime_assert();
    ch4_assertions_impl::test_static_assert();
    ch4_assertions_impl::test_noexcept();
    ch4_assertions_impl::test_expect_termination();
}
