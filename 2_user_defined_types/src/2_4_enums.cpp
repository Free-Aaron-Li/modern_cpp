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

enum class Color { red, blue, green };

enum class Traffic_light { green, yellow, red };

Traffic_light&
operator++(Traffic_light& t) {
    switch (t) {
        case Traffic_light::green: return t = Traffic_light::yellow;
        case Traffic_light::yellow: return t = Traffic_light::red;
        case Traffic_light::red: return t = Traffic_light::green;
    }
    return t;
}

/**
 * @ingroup user_defined_types_group
 * @brief 2.4 枚举：演示 enum class 与普通 enum
 *
 * 比较强类型枚举（scoped enums）与传统枚举的区别。
 *
 * 对应《C++ 之旅》2.4 节。
 */
void
tutorial_enums() {
    std::cout << "--- 2.4 Enums ---" << std::endl;
    Color col = Color::red;
    Traffic_light light = Traffic_light::red;
    if (col == Color::red) {
        // use col to avoid warning
    }

    if (light == Traffic_light::red) { ++light; }

    if (light == Traffic_light::green) {
        std::cout << "Light is now green" << std::endl;
    }
}
