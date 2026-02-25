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
 * @file 2_4_enums.cpp
 * @brief 第 2 章 用户自定义类型：枚举（enum class）示例源文件
 */

#include "user_defined_types.hpp"

using namespace std;

/**
 * @brief 2.4 枚举相关的内部实现
 */
namespace ch2_enums_impl {
    /**
     * @brief 颜色枚举类
     *
     * 在 @ref tutorial_enums 中被演示使用。
     *
     * @details 枚举值作用域在 `enum class` 中，因此不能直接使用 `enum`
     * 类型。同时
     * 避免重复使用造成的混淆。同时具备独立作用域，使得成员名无法泄露至
     * 外部作用域，同时避免隐式混用枚举与整数。
     */
    enum class Color { red, blue, green };

    /**
     * @brief 交通灯枚举类
     *
     * 在 @ref tutorial_enums 中被演示使用。
     */
    enum class Traffic_light { green, yellow, red };

    /**
     * @brief 交通灯自增运算符
     *
     * 在 @ref tutorial_enums 中被演示使用。
     *
     * @param t 交通灯引用
     * @return 更新后的交通灯引用
     */
    Traffic_light&
    operator++(Traffic_light& t) {
        /* 重复枚举名字较为繁琐冗长，可在作用域内简写 */
        using enum Traffic_light;
        switch (t) {
            // case Traffic_light::green: return t = Traffic_light::yellow;
            // case Traffic_light::yellow: return t = Traffic_light::red;
            // case Traffic_light::red: return t = Traffic_light::green;
            case green: return t = yellow;
            case yellow: return t = red;
            case red: return t = green;
        }
        return t;
    }
}  // namespace ch2_enums_impl

/**
 * @ingroup user_defined_types_group
 * @brief 2.4 枚举：演示 enum class
 *
 * 介绍强类型枚举（scoped enums）。
 *
 * 对应《C++ 之旅》2.4 节。
 */
void
tutorial_enums() {
    using namespace ch2_enums_impl;
    std::cout << "--- 2.4 Enums ---" << std::endl;
    Color         col{ Color::red };          /* 强类型枚举需要指定作用域 */
    Traffic_light tl{ Traffic_light::green }; /* 不同枚举类的成员互不干扰 */
    // Color col2{ red }; /* 错误：无法区分是哪个 red。 */
    // Color col3{ Traffic_light::red }; /* 错误：不属于 Color 类型 */
    // int i{ Color::red }; /* 错误：Color::red 不是 int 类型 */
}
