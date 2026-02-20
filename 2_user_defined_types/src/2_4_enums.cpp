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

#include "user_defined_types.hpp"

using namespace std;

namespace {
    /**
     * @brief 颜色枚举类
     * @details 枚举值作用域在`enum class`中，因此不能直接使用`enum`类型。同时
     * 避免重复使用造成的混淆。同时具备独立作用域，使得成员名无法泄露至
     * 外部作用域，同时避免隐式混用枚举与整数。
     */
    enum class Color { red, blue, green };

    /**
     * @brief 交通灯枚举类
     */
    enum class Traffic_light { green, yellow, red };

    /**
     * @brief 交通灯自增运算符
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
}  // namespace

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
    std::cout << "--- 2.4 Enums ---" << std::endl;
    Color         col{ Color::red };
    Traffic_light tl{ Traffic_light::green };
    // Color col2{ red }; /* 错误：无法区分是哪个red。 */
    // Color col3{ Traffic_light::red }; /* 错误：不属于Color类型 */
    // int i{ Color::red }; /* 错误：Color::red不是int类型 */
}
